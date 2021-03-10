#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "numerical_recipes/nrutil.h"
#include "numerical_recipes/nrutil.c"
#include "numerical_recipes/ludcmp.c"
#include "numerical_recipes/lubksb.c"

#define N 4 // rozmiar macierzy A: NxN


void generate_plot(){
  FILE* gnuplot_pipe = popen ("gnuplot -persistent", "w");
  fprintf(gnuplot_pipe, "set term png \n");
  fprintf(gnuplot_pipe, "set out \"z1.png\" \n");
  fprintf(gnuplot_pipe, "set xl \"t\" \n");
  fprintf(gnuplot_pipe, "set yl \"x(t)\" \n");
  fprintf(gnuplot_pipe, "p cos(x), \"out.txt\" u 1:2 w p lt 3 pt 3 t \"h=0.1'\" \n");
  pclose(gnuplot_pipe);
}

void printM(float ** mat, int size) {
  for(int i = 1; i <= size; i++) {
		for(int j = 1; j <= size; j ++) {
      printf("%16f ", mat[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void filePrintM(FILE * file, float ** mat, int size) {
  for(int i = 1; i <= size; i++) {
		for(int j = 1; j <= size; j ++) {
      fprintf(file, "%16f ", mat[i][j]);
    }
    fprintf(file, "\n");
  }
  fprintf(file, "\n");
}

int main(void){
  FILE * file = fopen("out.txt", "w");

  // Ad1
  float ** A  = matrix(1, N, 1, N);
  float ** A_copy  = matrix(1, N, 1, N);
  for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j ++) {
      A[i][j] = 1.0/(i+j);
      A_copy[i][j] = 1.0/(i+j);
    }
  }
  printf("Macierz A:\n");
  printM(A, N);
  fprintf(file, "Macierz A:\n");
  filePrintM(file, A, N);

  int * indxA = ivector(1, N);
  float dA;
  ludcmp(A, N, indxA, &dA);
  float ** L = matrix(1, N, 1, N);
  float ** U = matrix(1, N, 1, N);

  for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j ++) {
			if (i == j) {
				L[i][j] = 1;
				U[i][j] = A[i][j];
			}
			else if(i < j) {
				L[i][j] = 0;
				U[i][j] = A[i][j];
			}
			else {
				L[i][j] = A[i][j];
				U[i][j] = 0;
			}
		}
	}

  printf("Macierz L:\n");
  printM(L, N);
  fprintf(file, "Macierz L:\n");
  filePrintM(file, L, N);

  printf("Macierz U:\n");
  printM(U, N);
  fprintf(file, "Macierz U:\n");
  filePrintM(file, U, N);

 // Ad2  
  double detA = 1.0;
  printf("Elementy diagonalne U:\n");
  fprintf(file, "Elementy diagonalne U:\n");
  for(int i = 1; i <= N; i++) {
		printf("%f\t", U[i][i]);
    fprintf(file, "%f\t", U[i][i]);
    detA *= (double) U[i][i];
  }
  printf("\ndet[A]: %f* 10^(-9)\n\n", detA * 1000000000);
  fprintf(file, "\ndet[A]: %f* 10^(-9)\n\n", detA * 1000000000);

  // Ad3
	float * b1 = vector(1, N);
	float * b2 = vector(1, N);
	float * b3 = vector(1, N);
  float * b4 = vector(1, N);

	b1[1] = 1; b1[2] = 0; b1[3] = 0; b1[4] = 0;
	b2[1] = 0; b2[2] = 1; b2[3] = 0; b2[4] = 0;
	b3[1] = 0; b3[2] = 0; b3[3] = 1; b3[4] = 0;
	b4[1] = 0; b4[2] = 0; b4[3] = 0; b4[4] = 1;

  lubksb(A, N, indxA, b1);
	lubksb(A, N, indxA, b2);
	lubksb(A, N, indxA, b3);
  lubksb(A, N, indxA, b4);

  float ** A_inv = matrix(1, N, 1, N);

  for(int i = 1; i <= N; i++) {
    A_inv[i][1] = b1[i];
    A_inv[i][2] = b2[i];
   	A_inv[i][3] = b3[i];
    A_inv[i][4] = b4[i];
  }

  printf("Macierz A^(-1):\n");
  printM(A_inv, N);
  fprintf(file, "Macierz A^(-1):\n");
  filePrintM(file, A_inv, N);

  // Ad4
  float ** I  = matrix(1, N, 1, N);
  for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j ++) {
      I[i][j] = 0.;
      for(int k = 1; k <= N; k++) {
        I[i][j] += A_copy[i][k] * A_inv[k][j];
      }
    }
  }
  printf("Macierz A * A^(-1):\n");
  printM(I, N);
  fprintf(file, "Macierz A * A^(-1):\n");
  filePrintM(file, I, N);

  // Ad5
  float maxA = 0;
	float maxA_inv = 0;

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j ++) {
			if(fabs(A_copy[i][j]) > maxA)
				maxA = fabs(A_copy[i][j]);;
			if(fabs(A_inv[i][j]) > maxA_inv)
				maxA_inv= fabs(A_inv[i][j]);
		}
	}

	float kappaA = maxA * maxA_inv;

	printf("||A|| = %g\t||A^-1|| = %f\tk(A) = %f\n", maxA, maxA_inv, kappaA);
	fprintf(file, "||A|| = %g\t||A^-1|| = %f\tk(A) = %f\n", maxA, maxA_inv, kappaA);

  // Zamykanie procesow i dealokacja.
  fclose(file);
  free_matrix(A, 1, N, 1, N);
  free_matrix(L, 1, N, 1, N);
  free_matrix(U, 1, N, 1, N);
  free_matrix(A_copy, 1, N, 1, N);
  free_matrix(A_inv, 1, N, 1, N);
  free_matrix(I, 1, N, 1, N);
  free_vector(b1, 1, N);
  free_vector(b2, 1, N);
  free_vector(b3, 1, N);
  free_vector(b4, 1, N);
  free_ivector(indxA, 1, N);
	return 0;
}
