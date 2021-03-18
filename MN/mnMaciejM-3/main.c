#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3000



void generate_plot(char * fileName, double beta, double omega, double F0){
  FILE* gnuplot_pipe = popen ("gnuplot -persistent", "w");
  fprintf(gnuplot_pipe, "set term png \n");
  fprintf(gnuplot_pipe, "set out \"%s.png\" \n", fileName);
  fprintf(gnuplot_pipe, "set xl \"t\" \n");
  fprintf(gnuplot_pipe, "set yl \"x(t)\" \n");
  fprintf(gnuplot_pipe, "plot \"%s.txt\" i 0 w lp lt 0 t \"x(t); b = %g, F_0 = %g, w = %g\" \n", fileName, beta, F0, omega);
  pclose(gnuplot_pipe);
}



void fPrintTab(FILE * file, double * tab, double h){
  for (int i=0; i<N; i++){
    fprintf(file, "%g\n", tab[i]);
  }
}



void iter_jakobi(FILE * file, double omega, double F0, double beta){
  double h = 0.02;
  double lilOmg = 1;

  double a1 = 1;
  double a2 = lilOmg*lilOmg*h*h - 2 -beta*h;
  double a3 = 1 + beta*h;

  double d0[N];
  double d1[N];
  double d2[N];

  double b[N];
  double Xs[N];
  double Xn[N];

  d1[0] = 0;
  d2[0] = 0;
  d0[0] = 1;
  d0[1] = 1;
  d1[1] = -1;
  d2[1] = 0;

  b[0] = 1;
  b[1] = 0;

  for (int i=2; i<N; i++){
    d0[i] = a3;
    d1[i] = a2;
    d2[i] = a1;

    b[i] = F0 * sin(omega*h*i) * h*h;
  }

  for (int i=0; i<N; i++){ Xs[i] = Xn[i] = 0; }

  for(int iter=0; iter<N; iter++){
		Xn[0] = b[0]/d0[0];
		Xn[1] = (b[1] - d1[1] * Xs[0]) / d0[1];

		for(int i=2; i<N; i++){
			Xn[i] = (b[i] - d1[i]*Xs[i-1] - d2[i]*Xs[i-2])/d0[i];
		}

		for (int i=0; i<N; i++){
			Xs[i]=Xn[i];
		}
  }

  fPrintTab(file, Xn, h);
}



int main(void){
  FILE * file = fopen("out.txt", "w");
  double omega = 0.8;
  double F0 = 0.0;
  double beta = 0.0;

  iter_jakobi(file, omega, F0, beta);
  fclose(file);
  generate_plot("out", beta, F0, omega);


  file = fopen("out2.txt", "w");
  omega = 0.8;
  F0 = 0.0;
  beta = 0.4;

  iter_jakobi(file, omega, F0, beta);
  fclose(file);
  generate_plot("out2", beta, F0, omega);


  file = fopen("out3.txt", "w");
  omega = 0.8;
  F0 = 0.1;
  beta = 0.4;

  iter_jakobi(file, omega, F0, beta);
  fclose(file);
  generate_plot("out3", beta, F0, omega);

	return 0;
}
