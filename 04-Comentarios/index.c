#include <stdio.h>
#include <stdlib.h>
#include "commentReplacer.h"

int main() {
    FILE *source, *destination;
    char c, aux;
    puts("Ingrese nombre de archivo y extension, Ej: ejemplo.c ");
    char fileName[15];
    scanf("%s", fileName);
    source = fopen (fileName,"r"); 
    destination = fopen ("auxFile.txt","w");

    while( ( c = fgetc(source) ) != EOF )
        commentReplacer(c, aux, 0, source, destination);
    
    fclose(source);
    fclose(destination);

    remove(fileName);
    rename("auxFile.txt", fileName);

    return 0;
}
