#include <stdio.h>

#define MAK_1(x) printf(#x); printf(" = %d\n", (x))
#define MAK_2(x) (x)%2 == 0 ? (x) >= 0 ? 1 : -1 : 0

int main(void){
    int x = 5, y = 9;
    MAK_1(7*x+2-y/6);
    printf("%d\n",MAK_2(-64));
    return 0;
}
