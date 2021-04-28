#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "numerical_recipes/nrutil.h"
#include "numerical_recipes/nrutil.c"
#include "numerical_recipes/tred2.c"
#include "numerical_recipes/tqli.c"
#include "numerical_recipes/pythag.c"

void generate_plot(){
  FILE* gnuplot_pipe = popen ("gnuplot -persistent", "w");
  fprintf(gnuplot_pipe, "load 'gnuplot_4.sh\n");
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

void fprintM(float ** mat, int size, FILE * f){
  for(int i = 1; i <= size; i++) {
		for(int j = 1; j <= size; j ++) {
      fprintf(f, "%16f ", mat[i][j]);
      }
    fprintf(f, "\n");
  }
  fprintf(f, "\n");
}

void printV(float * vec, int size) {
    for(int i=1;i<=size;i++){
        printf("%16f ", vec[i]);
    }
    printf("\n");
}

void mulM(float **a, float **b, float **c, int size) {
    for(int i=1; i<=size; i++) {
        for(int j=1; j<=size; j++){
            c[i][j]=0.;
            for(int k=1; k<=size; k++){
              c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

void mulMbyV(float **a, float *b, float *c, int size) {
    for(int i=1; i<=size; i++) {
      c[i] = 0.0;
      for(int j=1; j<=size; j++){
        c[i] += a[i][j]*b[j];
      }
    }
}

float scalar(float *a, float*b, int size){
    float x=0.0;
    for(int i=1; i<=size; i++){
        x += a[i] * b[i];
    }
    return x;
}


int main(void){
  int N = 7;
  float ** mat  = matrix(1, N, 1, N);
  float ** matCopy  = matrix(1, N, 1, N);
  float * d  = vector(1, N);
  float * e  = vector(1, N);
  float ** Z  = matrix(1, N, 1, N);

  FILE * f = fopen("dane.txt", "w+");

  for (int i = 1; i <= N; i++){
    Z[i][i] = 1;
    for (int j = 1; j <= N; j++){
      mat[i][j] = sqrtf((float) (i+j));
      matCopy[i][j] = sqrtf((float) (i+j));
    }
  }

  printM(mat, N);
  fprintM(mat, N, f);

  tred2(mat, N, d, e);
  fprintM(mat, N, f);

  tqli(d, e, N, Z);
  
  fprintM(Z, N, f);
  printM(Z, N);
  printV(d, N);

  float * xi  = vector(1, N);
  float * xi_1  = vector(1, N);

  for(int k=1; k<=N; k++) {
    float lambda;
    for(int i=1; i<=8; i++) {
      mulMbyV(matCopy, xi, xi_1, N);
      lambda = scalar(xi_1, xi, N)/scalar(xi, xi, N);
      float norm = sqrtf(scalar(xi_1, xi_1, N));
      for (int j=1; j<= N; j++){
        xi_1[j] = xi_1[j]/norm;
      }
    }
    for(int i=1; i<=N; i++) {
      for(int j=1; j<=N; j++) {
        matCopy[i][j] = matCopy[i][j] - lambda*scalar(xi,xi,N);
      }
    }
  }

  fprintM(matCopy, N, f);

  fclose(f);
  free_matrix(mat, 1, N, 1, N);
  free_matrix(matCopy, 1, N, 1, N);
  free_matrix(Z, 1, N, 1, N);
  free_vector(d, 1, N);
  free_vector(e, 1, N);
  free_vector(xi, 1, N);
  free_vector(xi_1, 1, N);
  // generate_plot();
	return 0;
}
