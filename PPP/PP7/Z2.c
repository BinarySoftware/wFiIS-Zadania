#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char line[BUFSIZ];
    char * slowoKlucz = argv[1];
    int iloscLinii = 0;
    int iloscWystapien = 0;
    int lenSlowaKlucz = strlen(slowoKlucz);

    while (fgets(line,sizeof(line),stdin)) {
        int lenLine = strlen(line);
        int iloscWystapienWLinii = 0;

        for (int i = 0; i < lenLine;){
            int j = 0;
            int tempIlWyst = 0;

            while (line[i] == slowoKlucz[j]){
                tempIlWyst++;
                i++;
                j++;
            }

            if (tempIlWyst == lenSlowaKlucz) {
                iloscWystapienWLinii++;
                tempIlWyst = 0;
            } else {
                i++;
            }
        }

        if (iloscWystapienWLinii > 0){
            iloscLinii++;
            iloscWystapien += iloscWystapienWLinii;
            puts(line);
        }
    }

    printf("\"%s\" wynik: wypisane %d linii ; %d wystąpień.", slowoKlucz, iloscLinii, iloscWystapien);
    return 0;
}
