#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#include "numerical_recipes/nrutil.h"
#include "numerical_recipes/nrutil.c"
#include "numerical_recipes/tred2.c"
#include "numerical_recipes/pythag.c"
#include "numerical_recipes/tqli.c"
	 
void generate_plot(){
    FILE* gnuplot_pipe = popen ("gnuplot -persistent", "w");
    fprintf(gnuplot_pipe, "load 'gnuplot_4.sh\n");
    pclose(gnuplot_pipe);
}
	 
int main(void){
   int nx = 20;
   int ny = 20;
   int N = nx*ny;
	 
   float ** H  = matrix(1, N, 1, N);
   float ** Y  = matrix(1, N, 1, N);
   float ** X  = matrix(1, N, 1, N);
	 
   float * d = vector(1, N);
   float * e = vector(1, N);
	 
   int * indx = ivector(1, N);
	 
   int m = 10;
   float t = -0.021;
	 
   for(int i=1;i<=nx;i++){
        for(int j=1;j<=ny;j++){
            int l=j+(i-1)*ny;
	 
            for(int k=1;k<=N;k++) H[l][k]=0.;
	        if(i>1)
                H[l][l-ny]=t; //dla i=1 nie ma sasiada z lewej strony
            if(i<nx)
                H[l][l+ny]=t; //dla i=nx nie ma sasiada z prawej strony
            H[l][l]=-4*t;
            if(j>1)
                H[l][l-1]=t; //dla j=1 nie ma sasiada ponizej siatki
            if(j<ny)
                H[l][l+1]=t; //dla j=ny nie ma sasiada powyzej siatki
	    }
	}


    for(int i=0;i<=N;i++){
        e[i]=0;
        d[i]=0;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j){ Y[i][j] = 1; }
            else Y[i][j] = 0;
        }
    }

   tred2(H,N,d,e); // H -> P
   tqli(d,e,N,Y);
	 
   for(int i=1; i<=N; i++){
     for(int j=1; j<=N; j++){
       float temp = 0.0;
       for(int k=1; k<=N; k++){
         temp += H[i][k]*Y[k][j];
       }
       X[i][j] = temp;
     }
   }
	 
   for(int l=1;l<=N;l++) indx[l]=l;
	 
   for(int l=1;l<=N-1;l++){
        for(int k=N;k>=l+1;k--){
            float e1=d[k-1];
            float e2=d[k];
            float l1=indx[k-1];
            float l2=indx[k];
            if(e2<e1){
                d[k]=e1;
                d[k-1]=e2;
                indx[k]=l1;
                indx[k-1]=l2;
	        }
	    }
   }

   FILE *fp;
   fp=fopen("dane.dat","w");
   for(int i=1;i<=nx;i++){
     for(int j=1;j<=ny;j++){
       int l=j+(i-1)*ny;
       fprintf(fp,"%6d %6d ",i,j);
       for(int k=1;k<=m;k++){
         fprintf(fp," %12.6f ",X[l][ indx[k] ]);
	         }
       fprintf(fp,"\n");
	       }
     fprintf(fp,"\n");
	     }
   fclose(fp);
	 
	 
    free_matrix(H, 1, N, 1, N);
    free_matrix(Y, 1, N, 1, N);
    free_matrix(X, 1, N, 1, N);
    free_vector(d, 1, N);
	free_vector(e, 1, N);
    free_ivector(indx, 1, N);

    generate_plot();
	return 0;
}
