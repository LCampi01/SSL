#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Graficador.h"

void histograma(int longitudes[], int size){
    system("clear");
    int longitud = 0, contador = 0;

    for(int i = 1; i < size; i++) {
        if (longitudes[i] != 0) {
            printf("%3d|", i);
            while (contador < longitudes[i]) {
                printf("%c",'*');
                contador ++;
                }
        printf("\n");
        }
        contador = 0; 
    }
    printf("\n \t L o n g i t u d \n");

}