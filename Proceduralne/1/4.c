#include <stdio.h>
#define N 10

void sort(char * t, int n);

int main(void){
    char t[N] = "helLoWorD";
    sort(t,N-1);
    printf("%s", t);
}

void sort(char * t, int n){
for (int i = 0; i < n-1; i++){
    for (int j = i + 1; j < n; j++){
        if (*(t+i) > *(t+j)) {
            int a = *(t+i);
            *(t+i) = *(t+j);
            *(t+j) = a;
        }
    }
}
}
