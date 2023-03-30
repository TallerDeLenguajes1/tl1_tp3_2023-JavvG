/*  Granero Javier - Marzo 30 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 12

int main() {

    int matriz[N][M], j, i, mayor = 0, menor = 50000, yearM, yearm, monthM, monthm;
    float ganancias[N];

    srand(time(NULL));

    for(i=0; i<N; i++) {

        for(j=0; j<M; j++) {

            matriz[i][j] = (int)(10000.0 + ((float)rand() / RAND_MAX) * 40000.0);      // (float)rand() / RAND_MAX) genera elementos entre 0 y 1. Luego se multiplica por 40000 para obtener valores entre 0 y 40000. Luego se le suman 10000 para obtener valores entre 10000 y 50000

        }

    }

    printf("\n > Esta es la matriz generada: \n\n");

    for(i=0; i<N; i++) {

        for(j=0; j<M; j++) {

            printf(" %5d ", matriz[i][j]);      // "%5d" reserva espacio para un entero de 5 cifras

        }

        printf("\n");

    }

    getchar();

    for(i=0; i<N; i++) {

        float sum = 0;

        for(j=0; j<M; j++) {

            sum = sum + matriz[i][j];

        }

        ganancias[i] = sum / M;

    }

    printf(" \n > Estas son los promedios de ganancias por cada a%co: \n", 164);

    for(i=0; i<N; i++) {

        printf("\n >> A%co %d es: %.2f", 164, i+1, ganancias[i]);

    }

    printf("\n");

    getchar();

    for(i=0; i<N; i++) {

        for(j=0; j<M; j++) {

            if(matriz[i][j] > mayor) {

                mayor = matriz[i][j];
                yearM = i+1; 
                monthM = j;

            }

            if(matriz[i][j] < menor) {

                menor = matriz[i][j];
                yearm = i+1; 
                monthm = j;

            }

        }

    }

    char months[12][12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};

    printf("\n >> La menor producci%cn fue de %d y fue en %s del a%co %d", 162, menor, months[monthm], 164, yearm);
    printf("\n >> La mayor producci%cn fue de %d y fue en %s del a%co %d", 162, mayor, months[monthM], 164, yearM);

    getchar();

    return 0;

}