#include <stdio.h>

#ifndef HISTOGRAMA_H_INCLUDED
#define HISTOGRAMA_H_INCLUDED;

typedef struct {
      int longitudes[100];
} ArregloDeLongitudes;

void contadorSwitch(ArregloDeLongitudes *);
void contadorGoto(ArregloDeLongitudes *);
void contadorRecursivo(ArregloDeLongitudes *);
void contadorPorParametro(ArregloDeLongitudes*, int, int, int);

#endif