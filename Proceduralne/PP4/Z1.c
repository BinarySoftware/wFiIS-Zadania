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
    for(int i = 0; i<N; i++){
        tab[i] = float_rand(23.0,34.0);
    }
    float * iter = tab;
    for(int i = 0; i<N; i++){
        printf("%f, ", *iter);
        iter++;
    }

    int K;
    printf("\nPodaj rozmiar nowej tablicy:");
    scanf("%d", &K);
    if(K>N){
        tab = realloc(tab ,K* sizeof(float));
        if (!tab){
            printf("Brak pamieci\n");
            exit(-1);
        }
        for(int i = N; i<K; i++){
            tab[i] = -1.0*float_rand(5.0,20.0);
        }
        float * iter = tab;
        for(int i = 0; i<K; i++){
            printf("%f, ", *iter);
            iter++;
        }
    }
    free(tab);
    return 0;
}