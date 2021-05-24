#include <stdlib.h>
#include <stdio.h>

int main(){
    int a[5]; //malloc(sizeof(int)*5);
    for(int i = 0; i<100; i++){
        a[i] = i;
        printf("%d",a[i]);
    }
}