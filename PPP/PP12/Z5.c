#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float rand_f(float min, float max){
    float r = (float) rand()/RAND_MAX;
    return  r*(max - min) + min;
}

float ** matrix(int rows, int col, FILE* fp){
    float ** macierz = malloc(rows * sizeof(float*));
    for(int i=0; i < rows;i++){
        macierz[i] = calloc(col, sizeof(float));
    }

    for(int i=0; i < rows;i++){
        for(int j=0; j < col;j++){
            if(!feof(fp)){
                fread(&macierz[i][j], sizeof(float), 1, fp);
            }
        }
    }

    return macierz;
}

int main(){
    float tab[30];
    int i, x, y;

    srand(time(0));
    FILE *f_1 = fopen ("dane_1.dat","wb");
    int var;
    printf ("rozmiar = ");
    scanf ("%d", &var);
    for (i=0; i<var; i++)
        tab[i]=rand_f(0.0, 40.0);

    //zapisywanie do pliku binarnego dane_1.dat  zawartosci tablicy tab
    fwrite (tab,sizeof(float),var, f_1);
    fclose(f_1);

    // Rozne konfiguracje testowe dla rozmiaru 30
    f_1 = fopen("dane_1.dat","rb");
    float ** mat = matrix(6, 5, f_1);
    printf("Macierz 6X5\n");
    for(x=0; x<6; x++){
        for(y=0; y<5; y++){
            printf("%.3f\t",mat[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    free(mat);


    f_1 = fopen("dane_1.dat","rb");
    mat = matrix(10, 3, f_1);
    printf("Macierz 10X3\n");
    for(x=0; x<10; x++){
        for(y=0; y<3; y++){
            printf("%.3f\t",mat[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    free(mat);


    f_1 = fopen("dane_1.dat","rb");
    mat = matrix(5, 4, f_1);
    printf("Macierz 5X4\n");
    for(x=0; x<5; x++){
        for(y=0; y<4; y++){
            printf("%.3f\t",mat[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    free(mat);

    f_1 = fopen("dane_1.dat","rb");
    mat = matrix(11, 4, f_1);
    printf("Macierz 11X4\n");
    for(x=0; x<11; x++){
        for(y=0; y<4; y++){
            printf("%.3f\t",mat[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    free(mat);

    return 0;
}