#include <assert.h>
#include "histograma.h"
#include <stdio.h>


int main(){
    struct ArregloDeLongitudes arregloSwitch = {
        {0}
    };  

    printf("Intente escribir: -esto es un test- y finalice con ctrl + z (Win.) o ctrl + d (Unix)\n\n");
    contadorSwitch(&arregloSwitch);
    assert(arregloSwitch.longitudes[0] == 0);
    assert(arregloSwitch.longitudes[1] == 0);
    assert(arregloSwitch.longitudes[1] != 3);
    assert(arregloSwitch.longitudes[2] == 2);
    assert(arregloSwitch.longitudes[3] == 0);
    assert(arregloSwitch.longitudes[4] == 2);
    assert(arregloSwitch.longitudes[4] != 16);
    printf("Test contadorSwitch superado correctamente.\n\n");
    clearerr(stdin);

    struct ArregloDeLongitudes arregloGoto = {
        {0}
    };

    contadorGoto(&arregloGoto);
    assert(arregloGoto.longitudes[0] == 0);
    assert(arregloGoto.longitudes[1] == 0);
    assert(arregloGoto.longitudes[1] != 3);
    assert(arregloGoto.longitudes[2] == 2);
    assert(arregloGoto.longitudes[3] == 0);
    assert(arregloGoto.longitudes[4] == 2);
    assert(arregloGoto.longitudes[4] != 16);
    printf("Test contadorGoto superado correctamente.\n\n");
    clearerr(stdin);
    
    struct ArregloDeLongitudes arregloRecursivo = {
        {0}
    };

    contadorRecursivo(&arregloRecursivo);
    assert(arregloRecursivo.longitudes[0] == 0);
    assert(arregloRecursivo.longitudes[1] == 0);
    assert(arregloRecursivo.longitudes[1] != 3);
    assert(arregloRecursivo.longitudes[2] == 2);
    assert(arregloRecursivo.longitudes[3] == 0);
    assert(arregloRecursivo.longitudes[4] == 2);
    assert(arregloRecursivo.longitudes[4] != 16);
    printf("Test contadorRecursivo superado correctamente.\n\n");
    clearerr(stdin);
    
    
    struct ArregloDeLongitudes arregloParametro = {
        {0}
    };
    
    contadorPorParametro(&arregloParametro, getchar(), 0, 0);
    assert(arregloParametro.longitudes[0] == 0);
    assert(arregloParametro.longitudes[1] == 0);
    assert(arregloParametro.longitudes[1] != 3);
    assert(arregloParametro.longitudes[2] == 2);
    assert(arregloParametro.longitudes[3] == 0);
    assert(arregloParametro.longitudes[4] == 2);
    assert(arregloParametro.longitudes[4] != 16);
    printf("Test contadorPorParametro superado correctamente.\n\n");
    clearerr(stdin);

    printf("Los test fueron superados correctamente. \n");
}
