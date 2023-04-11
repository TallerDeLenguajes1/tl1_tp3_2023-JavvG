/*  Granero Javier - Abril 11 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Names 5

int main() {

    char *buff;     // Variable auxiliar
    char *fullname;
    char *namelist[Names];

    printf("\n > Deber%c ingresar %d nombres", 160, Names);

    for(int i=0; i<Names; i++) {

        buff = (char *) malloc(100*sizeof(char));        // Reserva de memoria dinámica para la variable auxiliar

        printf("\n\n > Ingrese el nombre completo de la persona %d: ", i+1);
        gets(buff);

        fullname = (char*) malloc(strlen(buff) * sizeof(char));

        strcpy(fullname, buff);

        namelist[i] = (char*) malloc((strlen(fullname) + 1) * sizeof(char));

        strcpy(namelist[i], fullname);

        free(buff);     // Importante (!)
        free(fullname);

    }

    printf("\n\n >> Estos son los nombres ingresados: \n\n");

    for(int i=0; i<Names; i++) {

        printf("\t > ");

        puts(namelist[i]);

    }

    getchar();

    return 0;

}