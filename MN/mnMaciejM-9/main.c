#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "numerical_recipes/nrutil.h"
#include "numerical_recipes/nrutil.c"
#include "numerical_recipes/gaussj.c"

#define frand() ((double)rand())/(RAND_MAX+1.0)
#define N 201
const double x_min = -4.0;
const double x_max = 4.0;
const double x_0 = 2.0;
 
double fun(double x) {
  double sigma = (x_max - x_min)/16.0;
  double sin_1 = sin(14.0*M_PI*x/(x_max - x_min));
  double exp_1 = exp(-pow(x-x_0,2)/(2*pow(sigma,2)));
  double exp_2 = exp(-pow(x+x_0,2)/(2*pow(sigma,2)));
  return sin_1 * (exp_1 + exp_2);
}

double fun_szum(double x) {
  double c_rand = (frand() - 0.5)/5.0;
  return fun(x) + c_rand;
}

int main(){
  int m = 50;
  double xi[N];
  double yi[N];
  for (int i = 0; i<N; i++){
    xi[i] = x_min + i*(x_max-x_min)/(N-1);
    yi[i] = fun(xi[i]);
  }

  double phi[m][N];
  for (int i = 0; i<N; i++){
    phi[0][i] = 1;
  }

  for (int i = 1; i<m; i++){
    double a_top = 0;
    double a_bot = 0;
    for (int k = 0; k<N; k++){
      a_top += xi[k]*pow(phi[i-1][k],2);
      a_bot += pow(phi[i-1][k],2);
    }
    double a = a_top/a_bot;

    double b_top = 0;
    double b_bot = 0;
    double b = 0;
    if (i > 1) {
      for (int k = 0; k<N; k++){
        b_top += xi[k]*phi[i-2][k]*phi[i-1][k];
        b_bot += pow(phi[i-2][k],2);
      }
      b = b_top/b_bot;
    }

    for (int k = 0; k<N; k++){
      phi[i][k] = (xi[k]-a)*phi[i-1][k];
      if (i > 1){
        phi[i][k] -= b*phi[i-2][k];
      }
    }
  }

  FILE * fGram = fopen("Gram.dat", "w");
  for (int k = 0; k<N; k++){
    fprintf(fGram, "%g", xi[k]);
    for (int i = 0; i<8; i++){
      double norm = phi[i][k]/phi[i][0];
      fprintf(fGram, "\t%g", norm);
    }
    fprintf(fGram, "\n");
  }
  fclose(fGram);

  FILE * approx = fopen("approx.dat", "w");
  FILE * pkt = fopen("pkt.dat", "w");
  for (int k = 0; k<N; k++){
    fprintf(pkt, "%g %g\n", xi[k], yi[k]);
  }

  int m_arr[3] = {10,30,50};

  for (int k = 0; k<3; k++){
    for (int s = 0; s < N; s++){
      double f_xk = 0.0;
      for (int j = 0; j < m_arr[k]; j++){
        double cj = 0.0;
        double sj = 0.0;
        for (int i=0; i < N; i++){
          cj += yi[i]*phi[j][i];
          sj += phi[j][i] * phi[j][i];
        }
        f_xk += cj/sj * phi[j][s];
      }
      fprintf(approx, "%g %g\n", xi[s], f_xk);
    }
    fprintf(approx, "\n\n");
  }
  fclose(pkt);
  fclose(approx);
  
  return 0;
}

