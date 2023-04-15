/*  Granero Javier - Abril 11 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *buff;     // Variable auxiliar
    int number_of_names;
    char **names_list;

    printf("\n > Ingrese la cantidad de nombres que desea enlistar: ");
    scanf("%d", &number_of_names);

    while(number_of_names <= 0) {

        printf("\n (!) Ingrese un n%cmero v%clido: ", 163, 160);
        scanf("%d", &number_of_names);

    }

    fflush(stdin);

    names_list = (char **) malloc(sizeof(char *) * number_of_names);

    for(int i=0; i<number_of_names; i++) {

        buff = (char *) malloc(100*sizeof(char));        // Reserva de memoria dinámica para la variable auxiliar

        printf("\n\n > Ingrese el nombre completo de la persona %d: ", i+1);
        gets(buff);

        names_list[i] = (char*) malloc((strlen(buff) + 1) * sizeof(char));

        strcpy(names_list[i], buff);

        free(buff);     // Importante (!)

    }

    printf("\n\n >> Estos son los nombres ingresados: \n\n");

    for(int i=0; i<number_of_names; i++) {

        printf("\t > ");

        puts(names_list[i]);
        
        free(names_list[i]);

    }

    getchar();

    return 0;

}