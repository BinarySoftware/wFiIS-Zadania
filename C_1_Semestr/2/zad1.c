//
// Created by Maciej Mikołajek on 27/11/2019.
//

#include <stdio.h>

int main(void){
    int j = 0;
    for(int i = 1; i<=100; i++){
        if(i%2==0 && i%4!=0 && i%5!=0){
            printf("%d ", i);
            j++;
        }
    }
    printf("\nznaleziono %d liczb", j);
    return 0;
}
