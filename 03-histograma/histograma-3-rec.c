#include "histograma.h"

void OUT (int caracter, int longitud, ArregloDeLongitudes* arreglo) {
    if (caracter == ' ' || caracter == '\n' || caracter == '\t') {
        OUT(getchar(), longitud, arreglo);
    } else {
        ++longitud;
        IN(getchar(), longitud, arreglo);
        }
    }

void IN (int caracter, int longitud, ArregloDeLongitudes* arreglo) {
    if(caracter == EOF) {
        if (ferror(stdin) && longitud > 0) 
            ++arreglo->longitudes[longitud];
        return; 
    }
    else if (caracter == ' ' || caracter == '\n' || caracter == '\t') {
        ++arreglo->longitudes[longitud];
        longitud = 0;
        OUT(getchar(), longitud, arreglo);
    }
    else {
        ++longitud;
        IN(getchar(), longitud, arreglo);       
    }
}


void contadorRecursivo(ArregloDeLongitudes* arreglo){
    int longitud = 0;
    OUT(getchar(), longitud, arreglo);
}

