#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define length 20

union liczba_typ{
    double d;
    int i;
};

struct liczba{
    char typ;
    union liczba_typ l;
};


int rand_int(int a, int b) {
    return (a + rand()%(b-a+1));
}

double rand_double(double min, double max ){
    double scale = rand() / (double) RAND_MAX;
    return min + scale * ( max - min );
}

void print_tab_liczba(struct liczba * tab, int len){
    for  (int i = 0; i < len; i++){
        char t = tab[i].typ;
        printf("%c ", t);
        if (t == 'i'){
            printf("%d", tab[i].l.i);
        } else {
            printf("%f", tab[i].l.d);
        }
        printf("\n");
    }
}

int struct_cmp(const void * a, const void * b){
    struct liczba *liA = (struct liczba *)a;
    struct liczba *liB = (struct liczba *)b;

    // typy :: int - lewo, double - prawo
    if (liA->typ != liB->typ){
        if(liA->typ == 'i'){
            return -1;
        } else {
            return 1;
        }
    }

    if (liA->typ == 'i'){
        return liB->l.i - liA->l.i;
    } else {
        if (liA->l.d > liB->l.d) return 1;
        else if (liA->l.d < liB->l.d) return -1;
        else return 0;
    }
}


int main() {
    srand(time(0));
    struct liczba * tab = malloc(length * sizeof(struct liczba));

    for (int i = 0; i < length; i++) {
        int randInt = rand_int(0,1);
        if (randInt == 0){
            union liczba_typ l;
            l.i = rand_int(0,100);
            struct liczba tempL = {'i', l};
            tab[i] = tempL;
        } else {
            union liczba_typ l;
            l.d = rand_double(0.0,100.0);
            struct liczba tempL = {'d', l};
            tab[i] = tempL;
        }
    }

    print_tab_liczba(tab, length);
    qsort(tab, length, sizeof(struct liczba), struct_cmp);
    printf("POSORTOWANE:\n");
    print_tab_liczba(tab, length);
    return 0;
}
