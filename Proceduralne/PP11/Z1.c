#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double rand_double(double min, double max){
    double scale = rand() / (double) RAND_MAX;
    return min + scale * ( max - min );
}

void print_text_double(char * name){
    printf("\nTablica double z tekstu:\n");
    FILE* txtFile = fopen(name, "r");
    double d;
    while(!feof(txtFile)) {
        fscanf(txtFile, "%lf", &d);
        printf("%lf\n", d);
    }
    fclose(txtFile);
}

void print_bin_double(char * name){
    printf("\nTablica double z pliku binarnego:\n");
    FILE* binFile = fopen(name, "rb");
    double d;
    while(!feof(binFile)) {
        fread(&d, 1, sizeof(double), binFile);
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

    printf("plik tekstowy -- %ld bajtow\n", fSizeTxt);
    printf("plik binarny -- %ld bajtow\n", fSizeBin);
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


    double *tab1;
    int tab1_len = 0;
    textFile = fopen(argv[2], "r");
    while(!feof(textFile)) {
        tab1_len++;
        tab1 = realloc(tab1, tab1_len * sizeof(double));
        fscanf(textFile, "%lf", tab1+(tab1_len-1));
    }
    fclose(textFile);

    printf("\nTablica 1 - z pliku tekstowego:\n");
    for(int i = 0; i < tab1_len; i++){
        printf("%lf\n", tab1[i]);
    }

    double *tab2;
    int tab2_len = 0;
    binFile = fopen(argv[1], "rb");
    while(!feof(binFile)) {
        tab2_len++;
        tab2 = realloc(tab2, tab2_len * sizeof(double));
        fread(tab2+(tab2_len-1), 1, sizeof(double), binFile);
    }
    fclose(binFile);

    printf("\nTablica 2 - z pliku binarnego:\n");
    for(int i = 0; i < tab2_len; i++){
        printf("%lf\n", tab2[i]);
    }

    binFile = fopen(argv[1], "r+b");
    double zero = 0.0;
    for (int i = 0; i < tab2_len; i+=5){
        fseek(binFile, i*sizeof(double), SEEK_SET );
        fwrite(&zero, sizeof(zero), 1, binFile);
    }
    fclose(binFile);
    print_bin_double(argv[1]);
    return 0;
}
