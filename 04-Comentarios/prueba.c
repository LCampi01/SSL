#include <stdio.h>
#include <stdlib.h>
#include "commentReplacer.h"

int main() {
    FILE *source, *destination; // test test est test
    /* test test test test test*/
    char c, aux; /* ACA METEMOS ESTE COMENTARIOO */
    puts("Ingrese nombre de archivo y extension, Ej: ejemplo.c ");
    char fileName[15];
    scanf("%s", fileName);// test test est test
    /* test test test test test*/

    source = fopen (fileName,"r"); // test test est test
    /* test test test test test*/

    destination = fopen ("auxFile.txt","w");// test test est test
    /* test test test test test*/

    while( ( c = fgetc(source) ) != EOF ) //HOLA
        commentReplacer(c, aux, 0, source, destination);  //HOLA HOLA  /*hola*/ /*hola*/ 
    /* test test test test test*/
    
    fclose(source);
    fclose(destination);

    remove(fileName);
    rename("auxFile.txt", fileName);

    return 0;
}