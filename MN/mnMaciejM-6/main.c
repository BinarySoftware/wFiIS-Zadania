#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "numerical_recipes/nrutil.h"
#include "numerical_recipes/nrutil.c"
#define IT_MAX 30

void printV(float * vec, int size) {
    for(int i=0;i<=size;i++){
        printf("%.3f\t", vec[i]);
    }
    printf("\n");
}

float licz_r(float * a, float * b, int n, float x0){
 b[n] = 0;
  for(int k=n-1; k>=0; k--){
    b[k] = a[k+1] + x0*b[k+1];

  }
  return a[0] + x0*b[0];
}

int main(void){
  int N = 5;

  FILE * f = fopen("wyniki.dat", "w");

  float * a  = vector(0, N);
  float * b  = vector(0, N);
  float * c  = vector(0, N);

  a[0] = 240.0;
  a[1] = -196.0;
  a[2] = -92.0;
  a[3] = 33.0;
  a[4] = 14.0;
  a[5] = 1.0;

  for(int L=1; L<=N; L++){
    float x0 = 0;
    int n = N-L+1;
    for(int it=1; it<=IT_MAX; it++){
      float r = licz_r(a, b, n, x0);
      float rp = licz_r(b, c, n-1, x0);
      float x1 = x0 - r/rp;
      printf("L: %d, it: %d, x0: %.3f, Rj: %.3f, Rj': %.3f\n", L,it,x1,r,rp);
      fprintf(f,"L: %d, it: %d, x0: %.3f, Rj: %.3f, Rj': %.3f\n", L,it,x1,r,rp);
      if (fabs(x1-x0) < 1e-7) { break; }
      x0 = x1;
    }
    for(int i=0; i<=(n-1); i++) { a[i]=b[i]; }
  }
  
  fclose(f);
  free_vector(a, 0, N);
  free_vector(b, 0, N);
  free_vector(c, 0, N);
	return 0;
}
