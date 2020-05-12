#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double rand_double(double min, double max){
    double scale = rand() / (double) RAND_MAX;
    return min + scale * ( max - min );
}

void print_text_double(char * name){
    printf("\nTablica double z tekstu:\n");
    FILE* txtFile = fopen(name, "r");
    double d;
    while(true) {
        fscanf(txtFile, "%lf", &d);
        if (feof(txtFile)){
            break;
        }
        printf("%lf\n", d);
    }
    fclose(txtFile);
}

void print_bin_double(char * name){
    printf("\nTablica double z pliku binarnego:\n");
    FILE* binFile = fopen(name, "rb");
    double d;
    while(true) {
        fread(&d, 1, sizeof(double), binFile);
        if (feof(binFile)){
            break;
        }
        printf("%lf\n", d);
    }
    fclose(binFile);
}

void print_file_size(char * name_bin, char * name_txt){
    FILE* flBin = fopen(name_bin, "rb");
    fseek(flBin, 0L, SEEK_END);
    long int fSizeBin = ftell(flBin);
    fclose(flBin);

    FILE* flTxt = fopen(name_txt, "r");
    fseek(flTxt, 0L, SEEK_END);
    long int fSizeTxt = ftell(flTxt);
    fclose(flTxt);

    printf("\nRozmiary plikow:\n");
    printf("plik tekstowy -- %ld bajtow\n", fSizeTxt);
    printf("plik binarny -- %ld bajtow\n", fSizeBin);
}

void arr_from_text_file(char * name, FILE *textFile) {
    double *arr = malloc(sizeof(double));
    int arr_len = 0;
    textFile = fopen(name, "r");
    while(true) {
        double temp;
        fscanf(textFile, "%lf", &temp);
        if (feof(textFile)) {
            break;
        }
        arr_len++;
        arr = realloc(arr, arr_len * sizeof(double));
        arr[arr_len - 1] = temp;
    }
    fclose(textFile);

    printf("\nTablica double z pliku tekstowego:\n");
    for(int i = 0; i < arr_len; i++){
        printf("%lf\n", arr[i]);
    }

    free(arr);
}

void arr_from_bin_file(char * name, FILE *binFile) {
    double *arr = malloc(sizeof(double));
    int arr_len = 0;
    binFile = fopen(name, "rb");
    while(true) {
        double temp;
        fread(&temp, 1, sizeof(double), binFile);
        if (feof(binFile)) {
            break;
        }
        arr_len++;
        arr = realloc(arr, arr_len * sizeof(double));
        arr[arr_len - 1] = temp;
    }
    fclose(binFile);

    printf("\nTablica double z pliku binarnego:\n");
    for(int i = 0; i < arr_len; i++){
        printf("%lf\n", arr[i]);
    }

    free(arr);
}

void replace_every_fifth_element(char *name, FILE *binFile) {
    printf("\nZamiana na zera co 5-tego elementu:\n");
    binFile = fopen(name, "r+b");
    fseek(binFile, 0, SEEK_END);
    int len = ftell(binFile)/sizeof(double);
    fseek(binFile, 0, SEEK_SET);
    double zero = 0.0;
    for (int i=0; i < len; i += 5){
        fseek(binFile, i*sizeof(double), SEEK_SET );
        fwrite(&zero, sizeof(zero), 1, binFile);
    }
    fclose(binFile);
    print_bin_double(name);
}

int main(int argc, char** argv){
    // Sprawdzenie czy uzytkownik podal nazwy plikow
    if(argc <= 2){
        puts("Za malo argumentow, potrzeba 2 w formacie - plik_bin plik_txt");
        return(1);
    }

    // Generacja tablicy losowych liczb o podanym rozmiarze
    int len;
    printf("Podaj dlugosc tablicy: ");
    scanf("%d", &len);

    double arr[len];
    srand(time(0));
    for(int i=0; i < len; i++) {
        arr[i] = rand_double(0.0, 100.0);
    }

    // Zapis tablicy do plikow
    FILE* textFile = fopen(argv[2], "w");
    for(int i=0; i<len; i++){
        fprintf(textFile, "%lf\n", arr[i]);
    }
    fclose(textFile);

    FILE* binFile = fopen(argv[1], "wb");
    fwrite(arr, sizeof(double), len, binFile);
    fclose(binFile);

    // Odczyt danych z plików oraz ich wielkosci
    print_text_double(argv[2]);
    print_bin_double(argv[1]);
    print_file_size(argv[1], argv[2]);

    arr_from_text_file(argv[2], textFile);
    arr_from_bin_file(argv[1], binFile);

    replace_every_fifth_element(argv[1], binFile);
    return 0;
}
