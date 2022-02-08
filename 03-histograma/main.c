#include <stdio.h>
#include "histograma.h"
#include "Graficador.h"

void menu() {
    printf("Seleccione que contador desea usar: \n");
    printf("a - Contador con recursividad \n");
    printf("b - Contador con switch \n");
    printf("c - Contador con goto\n");
    printf("d - Contador con trancision por argumento\n");
    printf("Presione ESC para finalizar \n");
    printf("\n");
}

int main() {

   ArregloDeLongitudes arreglo = {
      {0}
   };

   menu();
      switch (getchar()) {
         case 'a':
            printf("Escriba caracteres y luego presione ctrl + z (Win.) o ctrl + d (Unix) para finalizar... \n");
            contadorRecursivo(&arreglo);
            histograma(arreglo.longitudes, sizeof(ArregloDeLongitudes) / sizeof(int));
         break;
         case 'b':
            printf("Escriba caracteres y luego presione ctrl + z (Win.) o ctrl + d (Unix) para finalizar... \n");
            contadorSwitch(&arreglo);
            histograma(arreglo.longitudes, sizeof(ArregloDeLongitudes) / sizeof(int));
         break;
         case 'c':
            printf("Escriba caracteres y luego presione ctrl + z (Win.) o ctrl + d (Unix) para finalizar... \n");
            contadorGoto(&arreglo);
            histograma(arreglo.longitudes, sizeof(ArregloDeLongitudes) / sizeof(int));
         break;
         case 'd':
            printf("Escriba caracteres y luego presione ctrl + z (Win.) o ctrl + d (Unix) para finalizar... \n");
            contadorPorParametro(&arreglo, getchar(), 0, 0);
            histograma(arreglo.longitudes, sizeof(ArregloDeLongitudes) / sizeof(int));
         break;
      }

   return 0;
}

