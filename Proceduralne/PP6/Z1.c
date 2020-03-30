#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(size_t size, char *array[size]){
    char * result = malloc(sizeof(char));
    for(int i = 0; i < size; i++) {
        result = realloc(result, (strlen(result) + strlen(array[i]))* sizeof(char));
        result = strcat(result, array[i]);
    }
    return result;
}

int main() {
    char *strings[ ] = {"The sun did not shine.",
                        "It was too wet to play.",
                        " So we sat in the house - ",
                        "All that cold, cold, wet day."};
    char * cat = concat(4, strings);
    printf("%s\n", cat);
    return 0;
}
