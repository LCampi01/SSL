#include "histograma.h"

enum {
        IN = 1,
        OUT = 0
};

void contadorPorParametro(ArregloDeLongitudes* arreglo, int caracter, int longitud, int estado) {    
    if(caracter == EOF) {
        if (ferror(stdin) && longitud > 0) 
            ++arreglo->longitudes[longitud];
        return; 
    }

    else if(estado == OUT) {
        if (caracter == ' ' || caracter == '\n' || caracter == '\t') {
            contadorPorParametro(arreglo, getchar(), longitud, OUT);
        } else {
            ++longitud;
            contadorPorParametro(arreglo, getchar(), longitud, IN);
        }
    } else {
        if (caracter == ' ' || caracter == '\n' || caracter == '\t') {
            ++arreglo->longitudes[longitud];
            longitud = 0;
            contadorPorParametro(arreglo, getchar(), longitud, OUT);
        } else {
            ++longitud;
            contadorPorParametro(arreglo, getchar(), longitud, IN);      
        }
    }
}

