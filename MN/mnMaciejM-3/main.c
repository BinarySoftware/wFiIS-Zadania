#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "numerical_recipes.c/nrutil.h"
#include "numerical_recipes.c/nrutil.c"
#include "numerical_recipes.c/gaussj.c"

#define N 200 // rozmiar macierzy M: NxN


void generate_plot(){
  FILE* gnuplot_pipe = popen ("gnuplot -persistent", "w");
  fprintf(gnuplot_pipe, "set term png \n");
  fprintf(gnuplot_pipe, "set out \"z1.png\" \n");
  fprintf(gnuplot_pipe, "set xl \"t\" \n");
  fprintf(gnuplot_pipe, "set yl \"x(t)\" \n");
  fprintf(gnuplot_pipe, "p cos(x), \"out.txt\" u 1:2 w p lt 3 pt 3 t \"h=0.1'\" \n");
  pclose(gnuplot_pipe);
}


int main(void){
	float **M, **b;

	M = matrix(1, N, 1, N);
	b = matrix(1, N, 1, 1);

	for (int i = 1; i <= N; ++i){
		b[i][1] = 0.0;
		for (int j = 1; j <= N; ++j)
			M[i][j] = 0.0;
	}

  float vo = 0;
  float h = 0.1;
  float omega2 = 1.0; // k/m = 1 => omega2 = 1
  
  b[1][1] = 1;
	b[2][1] = vo*h;

	M[1][1] = 1;
	M[2][1] = -1;
	M[3][1] = 1;

  for (int i = 2; i <= N; ++i){
    	M[i][i] = 1;
      if (i+1 <= N)
        M[i+1][i] = omega2*h*h - 2;
      if (i+2 <= N)
        M[i+2][i] = 1;
	}

	gaussj(M, N, b, 1);

  FILE *fptr;
  fptr = fopen("out.txt", "w");

	for (int i = 1; i <= N; ++i) {
		printf("%f\n", b[i][1]);
    fprintf(fptr, "%f  %f\n", i*h, b[i][1]);
  }

  fclose(fptr);

	free_matrix(M, 1, N, 1, N);
	free_matrix(b, 1, N, 1, 1);

  generate_plot();

	return 0;
}
