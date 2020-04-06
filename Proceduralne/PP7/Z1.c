#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROZMIAR 81        //maksymalna dlugość łańcuchów
#define GRAN 21           // maksymalna liczba łańcuchów

void sortlan(char *lan[], int num);  //procedura sortująca łancuchy

int main(void){
    char dane[GRAN][ROZMIAR];
    //tablica przechowujaca łańcuchy nie dłuzsze niz ROZMIAR znakow nie wiecej niz GRAN
    char **wsklan = (char **) dane;
    //wskaźnik na tablicę wskaźników - rozmiar zależny od ilości wczytanych łańcuchów
    int licz = 1;                //licznik danych wejsciowych
    int k;
    printf("Podaj maksymalnie %d wierszy \n",GRAN);
    printf("Aby zakonczyc, wcisnij Enter na poczatku wiersza.\n");

    // UWAGA
    //
    // Wiem że nie iteruje sie od 1
    // natomiast nie wiem skąd, ale mam problem
    // gdyz element zerowy jest jakis dziwny
    // nie przypisuje sie do niego poprawny string
    // tylko jakies dziwne dane spoza wypisywalnych znaków ASCII
    // i dlatego pierwszy string jest zamiast jakiegos 'foo' np '???'
    // ale pozniej juz nie ma tego problemu
    // dlatego tez omijam pierwdsze miejsce w pamieci

    while (licz < GRAN && fgets(dane[licz],ROZMIAR,stdin) != NULL && dane[licz][0] != '\0' && dane[licz][0] != '\n'){
        wsklan[licz] = &dane[licz][0];
//        printf("%s\n", wsklan[licz]);
//        printf("%s\n", dane[licz]);
        //ustaw wskaźnik z tablicy wsklan na wczytany łańcuch
        licz++;
    }
    puts("\n Wczytano:\n");
    for (k = 1; k < licz; k++) {
        puts(*(wsklan + k));  // z użyciem identyfikataora wsklan
//        puts(dane[k]) ;
//        printf("wsk : %ld  tab: %ld\n", &wsklan[k][0], &dane[k][0]);
    }

    sortlan(wsklan, licz); // wywłoanie procedury sortującej

    puts("\n Oto uporzadkowana lista:\n");
    for (k = 1; k < licz; k++){
//        puts(*(wsklan + k));  // z użyciem identyfikataora wsklan
        puts(dane[k]) ; // z użyciem identyfikataora dane
//        printf("wsk : %ld  tab: %ld\n", &wsklan[k][0], &dane[k][0]);
    }
    return 0;
}

// procedura sortująca
void sortlan(char *lan[], int num) {
    //potrzebne zmienne lokalne
    for (int i = 1; i < num; i++) {
        for (int j = 1; j < num-1; j++) {
            if (strcmp(lan[j],lan[j+1]) > 0) {
                char *temp = malloc(ROZMIAR* sizeof(char));
                strcpy(temp,lan[j+1]);
                strcpy(lan[j+1],lan[j]);
                strcpy(lan[j],temp);
//                char * temp = lan[j+1];
//                lan[j+1]=lan[j];
//                lan[j]=temp;
            }
        }
    }
}