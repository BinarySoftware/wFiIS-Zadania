#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "numerical_recipes/nrutil.c"
#include "numerical_recipes/nrutil.h"
#include "numerical_recipes/four1.c"

const float T = 1.0;

float frand(float min, float max){
  float scale = rand() / (float) RAND_MAX;
  return min + scale * ( max - min ); 
}

float omega() { return (2.0 * M_PI) / T; }

float fun(float t){
  return sin(omega()*t) + sin(2*omega()*t) + sin(3*omega()*t);
}

float f_delta(float t){
  return fun(t) + frand(-0.5, 0.5);
}

float g(float t){
  float sigma = T/20.0;
  float p1 = 1.0/(sigma*sqrt(2.0*M_PI));
  float p2 = exp(-t*t/(2*sigma*sigma));
  return p1*p2;
}

int main(){
  srand(time(NULL));

  FILE *f1 = fopen("k8.dat", "w");
  FILE *f2 = fopen("k10.dat", "w");
  FILE *f3 = fopen("k12.dat", "w");

  FILE* files[] = {f1, f2, f3};
  int k[] = {8, 10, 12};

  for(int i=0; i<3; i++){
    FILE * curr_f = files[i];
    int curr_k = k[i];
    const int N = pow(2, curr_k);
    float dt = 3.0*T/((float) N);
    float* f0 = vector(1, 2 * N);
    float* f = vector(1, 2 * N);
    float* g1 = vector(1, 2 * N);
    float* g2 = vector(1, 2 * N);

    for(int j = 1; j <= N; j++) {
      float ti = dt * (j - 1);
      f0[2*j - 1] = f_delta(ti);
      f[2*j - 1] = f0[2*j - 1];
      g1[2 * j - 1] = g2[2 * j - 1] = g(ti);
      f[2 * j] = f0[2 * j] = g1[2 * j] = g2[2 * j] = 0;
    }

    four1(f, N, 1);
	  four1(g1, N, 1);
	  four1(g2, N, -1);

    for (int j = 1; j <= N; j++) {
	    float a1 = f[2 * j - 1];
	    float b1 = f[2 * j];
	    float a2 = g1[2 * j - 1] + g2[2 * j - 1];
	    float b2 = g1[2 * j] + g2[2 * j];
	    f[2 * j - 1] = a1 * a2 - b1 * b2;
	    f[2 * j] = a1 * b2 + a2 * b1;
	  }

    four1(f, N, -1);
    float max = fabs(f[1]);
    for(int j = 2; j <= N; j++) {
      if (fabs(max) < fabs(f[2 * j - 1])){
        max = fabs(f[2 * j - 1]);
      }
    }

    for(int j = 1; j <= N; j++) {
      float ti = dt * (j - 1);
	    fprintf(curr_f, "%10f %10f\n", ti, f0[2 * j - 1]);
    }

    fprintf(curr_f, "\n\n");

    for (int j = 1; j <= N; j++) {
	    float ti = dt * (j - 1);
      fprintf(curr_f, "%10f %10f\n", ti, f[2 * j - 1] * 2.5 / max);
    }

    free_vector(f0, 1, 2*N);
    free_vector(f, 1, 2*N);
    free_vector(g1, 1, 2*N);
    free_vector(g2, 1, 2*N);
    fclose(curr_f);
  }

  return 0;
}