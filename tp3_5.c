/*  Granero Javier - Abril 11 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *buff;     // Variable auxiliar
    char *fullname;
    int number_of_names;

    printf("\n > Ingrese la cantidad de nombres que desea enlistar: ");
    scanf("%d", &number_of_names);

    while(number_of_names <= 0) {

        printf("\n (!) Ingrese un n%cmero v%clido: ", 163, 160);
        scanf("%d", &number_of_names);

    }

    fflush(stdin);

    char *names_list[number_of_names];

    for(int i=0; i<number_of_names; i++) {

        buff = (char *) malloc(100*sizeof(char));        // Reserva de memoria dinámica para la variable auxiliar

        printf("\n\n > Ingrese el nombre completo de la persona %d: ", i+1);
        gets(buff);

        fullname = (char*) malloc((strlen(buff) + 1) * sizeof(char));

        strcpy(fullname, buff);

        names_list[i] = (char*) malloc((strlen(fullname) + 1) * sizeof(char));

        strcpy(names_list[i], fullname);

        free(buff);     // Importante (!)
        free(fullname);

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