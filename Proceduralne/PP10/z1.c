#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char *array[]){
    char * result = malloc(sizeof(char));
    int i = 0;
    while (strlen(array[i]) != 0) { //FIXME: ex. 1. element is empty will f-up
        result = realloc(result, (strlen(result) + strlen(array[i]))* sizeof(char));
        result = strcat(result, array[i]);
        i++;
    }
    return result;
}

int main() {
    char *strings[] = {"The sun did not shine.",
                        "It was too wet to play.",
                        " So we sat in the house - ",
                        "All that cold, cold, wet day."};
    char * cat = concat(strings);
    printf("%s\n", cat);
    return 0;
}
