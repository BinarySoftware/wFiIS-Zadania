#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cstring_cmp(const void * a, const void * b){
    const char *stra = a;
    const char * const *strb = b;
    return strcmp(stra, *strb);
}


int main(){
    char szukaj[]="Alex";
    char *strings[] = {"Alex", "Bill","Celine", "Dexter", "Forest","Garcia"};

    size_t string_size = sizeof(strings[0]);
    size_t strings_len = sizeof(strings)/string_size;

    char ** pt = bsearch(szukaj,strings,strings_len,string_size,cstring_cmp);
    printf("%s na pozycji %ld\n",*pt, pt-strings);
    return 0;
}