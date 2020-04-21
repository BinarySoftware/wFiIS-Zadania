#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    char pi_form[7]="";
    int i;
    for (i=0; i<7; i+=2){
        sprintf(pi_form, "%%.%dlf",i); //zbudowanie łańcucha formatującego
        printf("FORMAT %s ->",pi_form); //wypisanie łańcucha formatującego
        strcat(pi_form,"\n");//doklejenie znaku końca linii
        printf(pi_form,M_PI);//M_PI stała z biblioteki math.h
    }
}