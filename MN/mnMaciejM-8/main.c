#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "numerical_recipes/nrutil.h"
#include "numerical_recipes/nrutil.c"
#include "numerical_recipes/gaussj.c"


#define XMIN -5.0
#define XMAX 5.0
#define STEP 0.01


float fun1(float x) {
	return 1.0 / (1.0 + x * x);
}

float fun2(float x) {
    return cos(2 * x);
}

float phi(float x, float* xw, int i, float h) {
    if (x >= xw[i - 2] && x < xw[i - 1]) {
        return pow(x - xw[i - 2], 3) / pow(h, 3);
    }
    else if (x >= xw[i - 1] && x < xw[i]) {
        return (pow(h, 3) + 3 * h * h * (x - xw[i - 1]) + 3 * h * (x - xw[i - 1]) * (x - xw[i - 1]) - 3 * pow(x - xw[i - 1], 3)) / pow(h, 3);
    }
    else if (x >= xw[i] && x < xw[i + 1]) {
        return (pow(h, 3) + 3 * h * h * (xw[i + 1] - x) + 3 * h * (xw[i + 1] - x) * (xw[i + 1] - x) - 3 * pow(xw[i + 1] - x, 3)) / pow(h, 3);
    }
    else if (x >= xw[i + 1] && x <= xw[i + 2]) {
        return pow(xw[i + 2] - x, 3) / pow(h, 3);
    }
    else return 0.0;
}

float s(float h, int n, float* xw, float* c, float x) {
    float result = 0.0;
    for (int i = 0; i <= n + 1; i++) {
        result += c[i] * phi(x, xw, i, h);
    }
    return result;
}

int main() {
	const int fun1_nodes_num[] = {5, 8, 21, 10};
	const int fun2_nodes_num[] = {5, 8, 21};
	FILE* f1 = fopen("f1.dat", "w");
	FILE* f2 = fopen("f2.dat", "w");
  FILE* poch = fopen("pochodne.dat", "w");
	
	for(int i = 0; i < 4; i++) {
		int n = fun1_nodes_num[i];
		float h = (XMAX - XMIN) / (n - 1.0);
		float* xw = vector(-2, n + 3);
		float* yw = vector(1, n);
		float* c = vector(0, n + 1);
		float alpha = (fun1(XMIN + STEP) - fun1(XMIN - STEP)) / (2.0 * STEP);
        float beta = (fun1(XMAX + STEP) - fun1(XMAX - STEP)) / (2.0 * STEP);
		float** A = matrix(1, n, 1, n);
		float** b = matrix(1, n, 1, n);

		for(int i = -2; i <= n + 3; i++)
			xw[i] = XMIN + (i - 1) * h;
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				A[i][j] = 0.0;
			}
			A[i][i] = 4.0;
			b[i][1] = fun1(xw[i]);
			yw[i] = fun1(xw[i]);
		}
		
		for(int i = 1; i < n; i++){
			A[i][i + 1] = 1.0;
			A[i + 1][i] = 1.0;
		}	

		A[1][2] = 2.0;
		A[n][n - 1] = 2.0;

		b[1][1] += h / 3.0 * alpha;
		b[n][1] -= h / 3.0 * beta;	
		
		gaussj(A, n, b, 1);

		for (int i = 1; i <= n; i++) {
            c[i] = b[i][1];
        }
        c[0] = c[2] - h / 3.0 * alpha;
        c[n + 1] = c[n - 1] + h / 3.0 * beta;
        
        for (float x = XMIN; x <= XMAX; x += STEP) {
            fprintf(f1, "%f %f\n", x, s(h, n, xw, c, x));
        }
        if (n == 10){
          for (int j = 1; j <= n; j++) {
              fprintf(poch, "%f %f %f\n", xw[j], c[j],s(h, n, xw, c, xw[j]));
          }
        }

        fprintf(f1, "\n\n");

		free_vector(xw, -2, n + 3);
        free_vector(yw, 1, n);
        free_vector(c, 0, n + 1);
		free_matrix(A, 1, n, 1, n);
        free_matrix(b, 1, n, 1, 1);
    }

	for(int i = 0; i < 3; i++) {
		int n = fun2_nodes_num[i];
		float h = (XMAX - XMIN) / (n - 1.0);
		float* xw = vector(-2, n + 3);
		float* yw = vector(1, n);
		float* c = vector(0, n + 1);
		float alpha = (fun2(XMIN + STEP) - fun2(XMIN - STEP)) / (2.0 * STEP);
        float beta = (fun2(XMAX + STEP) - fun2(XMAX - STEP)) / (2.0 * STEP);
		float** A = matrix(1, n, 1, n);
		float** b = matrix(1, n, 1, n);
		
		for(int i = -2; i <= n + 3; i++)
			xw[i] = XMIN + (i - 1) * h;
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				A[i][j] = 0.0;
			}
			A[i][i] = 4.0;
			b[i][1] = fun2(xw[i]);
			yw[i] = fun2(xw[i]);
		}

		for(int i = 1; i < n; i++){
			A[i][i + 1] = 1.0;
			A[i + 1][i] = 1.0;
		}	

		A[1][2] = 2.0;
		A[n][n - 1] = 2.0;

		b[1][1] += h / 3.0 * alpha;
		b[n][1] -= h / 3.0 * beta;

		gaussj(A, n, b, 1);

		for (int i = 1; i <= n; i++) {
            c[i] = b[i][1];
        }
        c[0] = c[2] - h / 3.0 * alpha;
        c[n + 1] = c[n - 1] + h / 3.0 * beta;
        
        for (float x = XMIN; x <= XMAX; x += STEP) {
            fprintf(f2, "%f %f\n", x, s(h, n, xw, c, x));
        }

        fprintf(f2, "\n\n");

		free_vector(xw, -2, n + 3);
        free_vector(yw, 1, n);
        free_vector(c, 0, n + 1);
		free_matrix(A, 1, n, 1, n);
        free_matrix(b, 1, n, 1, 1);
    }

	fclose(f1);
    fclose(f2);
	fclose(poch);
	return 0;
}