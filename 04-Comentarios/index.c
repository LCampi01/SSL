#include <stdio.h>
#include <stdlib.h>
#include "commentReplacer.h"
#include "stackOfCharsModule.h" 


int main() {
    FILE *source, *destination;
    char c, aux;
    puts("Ingrese nombre de archivo y extension, Ej: ejemplo.c ");
    char fileName[15];
    scanf("%s", fileName);
    source = fopen (fileName,"r"); 
    destination = fopen ("auxFile.txt","w");
    
    struct Stack* stack = createStack(100);
    
    while( ( c = fgetc(source) ) != EOF ){
        commentReplacer(c, aux, 0, source, destination);
        if (!checkBrackets(c, stack)){
            puts("Los brackets no estan correctamente equilibrados");            
        }
    }
    puts("Presione una tecla para salir de la consola");
    char exit;
    scanf("%s", exit);

    fclose(source);
    fclose(destination);

    remove(fileName);
    rename("auxFile.txt", fileName);

    return 0;
}
