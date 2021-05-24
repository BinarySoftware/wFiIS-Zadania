#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const int N = 200;
const double Xmin = -10.0;
const double Ymin = -10.0;
const double Xmax = 10.0;
const double Ymax = 10.0;
const double X0 = 5.0;
const double Y0 = 5.0;

double f(double x, double y){
  double sins = sin(x) * sin(y);
  double in1 = -pow(x + M_PI/2,2);
  double in2 = -pow(y - M_PI/2,2);
  return sins - exp(in1 + in2);
}

double d_rand(const double min, const double max) {
  double r = (double)rand() / RAND_MAX; // Przedzial [0, 1]
  r = r * (max - min) + min; // Przeskalowanie do [min, max] 
  return r;
}

int main(){
  srand(time(NULL));
  double x[N+1];
  double y[N+1];

  FILE * w0 = fopen("w0.dat", "w");
  FILE * Tdat = fopen("T.dat", "w");

  for(int i = 0; i < N; i++){
    x[N] = X0;
    y[N] = Y0;
  }

  for(int it = 0; it <= 20; it++){
    double T = 10.0/pow(2, it);
    for(int k = 0; k < 100; k++){
      fprintf(w0, "%g\n", f(x[0], y[0]));
      for(int i = 0; i < N; i++){
        double dx = d_rand(-1.0, 1.0);
        double dy = d_rand(-1.0, 1.0);

        while (x[i] + dx > Xmax || x[i] + dx < Xmin) {
            dx = d_rand(-1, 1);
        }

        while (y[i] + dy > Ymax || y[i] + dy < Ymin) {
            dy = d_rand(-1, 1);
        }

        if ( f(x[i] + dx, y[i] + dy) < f(x[i], y[i])){
          x[i] = x[i] + dx;
          y[i] = y[i] + dy;
        } else if ( d_rand(0, 1) < exp(-(f(x[i] + dx, y[i] + dy)- f(x[i], y[i])) / T)){
          x[i] = x[i] + dx;
          y[i] = y[i] + dy;
        }
      }
    }

    if (it == 0 || it == 7 || it == 19){
      for(int i = 0; i < N; i++){
        fprintf(Tdat, "%g %g\n", x[i], y[i]);
      }
      fprintf(Tdat, "\n\n");
    }
  }

  fclose(w0);
  fclose(Tdat);

  return 0;
}
