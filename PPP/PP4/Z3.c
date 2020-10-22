#include <stdio.h>
#include <stdlib.h>
#define N 5

int main() {
    int * pas = malloc(sizeof(int));
    if (!pas){
        printf("Brak pamieci\n");
        exit(-1);
    }
    int s, i, j;
    pas[0] = 1;
    for (s=1; s <= N + 1; s++)
        printf("  ");
    printf("%d\n", pas[0]);
    for (i=2; i<=N+1; i++){
        pas = realloc(pas, i * sizeof(int));
        if (!pas){
            printf("Brak pamieci\n");
            exit(-1);
        }
        for (s=1; s <= N - i + 1; s++)
            printf("  ");
        printf("%3d ", pas[0]);
        pas[i-1] = 1;
        int prev=pas[0];
        int prev2=pas[1];
        for (j=1; j<i-1; j++){
            pas[j]=prev+prev2;
            prev = prev2;
            prev2 = pas[j+1];
            printf("%3d ", pas[j]);
        }
        printf("%3d\n", pas[i-1]);
    }
    free(pas);
    return 0;
}
