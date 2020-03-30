#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float float_rand(float min, float max ){
    float scale = rand() / (float) RAND_MAX;
    return min + scale * ( max - min );
}

int main() {
    srand(time(0));
    int N;
    printf("Podaj rozmiar tablicy:");
    scanf("%d", &N);

    float * tab = malloc(N* sizeof(float));
    if (!tab){
        printf("Brak pamieci\n");
        exit(-1);
    }
    printf("TABLICA:\n");
    for(int i = 0; i<N; i++){
        tab[i] = float_rand(-1.5,1.5);
        printf("%f, ", tab[i]);
    }

    float * tabDod = malloc(sizeof(float));
    if (!tabDod){
        printf("Brak pamieci\n");
        exit(-1);
    }
    float * tabUj = malloc(sizeof(float));
    if (!tabUj){
        printf("Brak pamieci\n");
        exit(-1);
    }
    int ilUj = 0;
    int ilDod = 0;
    for(int i = 0; i<N; i++){
        if (tab[i]<0.0){
            ilUj++;
            tabUj = realloc(tabUj, ilUj* sizeof(float));
            if (!tabUj){
                printf("Brak pamieci\n");
                exit(-1);
            }
            tabUj[ilUj-1] = tab[i];
        } else {
            ilDod++;
            tabDod = realloc(tabDod, ilDod* sizeof(float));
            if (!tabDod){
                printf("Brak pamieci\n");
                exit(-1);
            }
            tabDod[ilDod-1] = tab[i];
        }
    }

    printf("\nTABLICA Ujemnych liczb:\n");
    for(int i = 0; i<ilUj; i++){
        printf("%f, ", tabUj[i]);
    }
    printf("\nTABLICA Dodatnich liczb:\n");
    for(int i = 0; i<ilDod; i++){
        printf("%f, ", tabDod[i]);
    }

    free(tab);
    free(tabDod);
    free(tabUj);
    return 0;
}