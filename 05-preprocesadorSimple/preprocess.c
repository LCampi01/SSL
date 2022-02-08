#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h> 
#include "symbolTable.h"

enum {
    initialState = 0,
    possibleComment = 1,
    commentaryWithDoubleBar = 2,
    commentaryWithAsterisk = 3,
    possibleDirective = 4,
    D = 5,
    De = 6,
    defineDirective = 7,
    U = 8,
    Un = 9,
    undefDirective = 10,
    defineIdentifier = 11,
    undefIdentifier = 12,
    constantValue = 13,
    defineConstant = 14,
    I = 15,
    In = 16,
    includeDirective = 17, 
    includeLocation = 18,
    localInclude = 19,
    externalInclude = 20
};

void preprocess(char c, char aux, char str[], int state) {

    if(state == initialState) {
        if (c == '#') {
            preprocess(getchar(), aux, str, possibleDirective);
            return;
        }
        else if (c == '(' || c == '=') {
            putchar(c);
            preprocess(getchar(), aux, str, defineConstant);
            return;
        }
        else if ( c == '/' ) {
            preprocess(c, aux, str, possibleComment);
            return;
        } else {
            putchar(c);
            return;
        }
    }

    if(state == possibleComment) {
        if ( ( aux = getchar() ) == '/') {
            preprocess(c, aux, str, commentaryWithDoubleBar);
            return;
        } else if (aux == '*') {
            preprocess(c, aux, str, commentaryWithAsterisk);
            return;
        } else {
            putchar(c);
            putchar(aux);
            return;
        }
    }

    if (state == commentaryWithDoubleBar) {
        char current;
        while( ( current = getchar() ) != EOF ) {
            if( current == '\n') {
                putchar(current);
                return;
            }
        }
    }
    
    if (state == commentaryWithAsterisk) {
        char current, currentAux;
        while((current = getchar() ) !=EOF ) {
            if(current == '*')
            {
                currentAux = getchar();
                if(currentAux == '/')
                    return;
            }
        }
    }

    if(state == possibleDirective) {
        if (c == 'd') {
            preprocess(getchar(), aux, str, D);
            return;
        }
        else if(c == 'u') {
            preprocess(getchar(), aux, str, U);
            return;
        }
        else if(c == 'i') {
            preprocess(getchar(), aux, str, I);
            return;
        }  
        else {
            putchar('#');
            putchar(c);
            return;
        }   
    }

    if(state == D) {
        if (c == 'e')
            preprocess(getchar(), aux, str, De);
        return;
    }

    if(state == U) {
        if (c == 'n')
            preprocess(getchar(), aux, str, Un);
        return;
    }
    if(state == I) {
        if (c == 'n')
            preprocess(getchar(), aux, str, In);
        return;
    }

    if(state == De) {
        if (c == 'f') {
            while (c != 'e')
                c = getchar();
            preprocess(getchar(), aux, str, defineDirective);
        }
        return;
    }

    if(state == Un) {
        if (c == 'd') {
            while (c != 'f')
               c = getchar();
            preprocess(getchar(), aux, str, undefDirective);
        }
        return;
    }
    if(state == In) {
        if (c == 'c') {
            while (c != 'e')
               c = getchar();
            preprocess(getchar(), aux, str, includeDirective);
        }
        return;
    }

    if(state == defineDirective) {
        if (c == ' ') 
            preprocess(getchar(), aux, str, defineIdentifier);
    }

    if(state == includeDirective) {
        if (c == ' ') 
            preprocess(getchar(), aux, str, includeLocation);
    }

    if(state == undefDirective) {
        if (c == ' ') 
            preprocess(getchar(), aux, str, undefIdentifier);
    }

    if(state == defineIdentifier) {
        memset(str, 0, 100);
        for(int i = 0; c != ' '; i++) {
            str[i] = c;
            c = getchar();
        } 
        preprocess(getchar(), aux, str, constantValue);
    }

    if(state == undefIdentifier) {
        for (int i = 0; c != ' ' && c != '\n'; i++) {
            str[i] = c;
            c = getchar();
        } 
        rem(str);
    }

    if(state == includeLocation) {

        if (c == '"' || c == '\'') preprocess(getchar(), c, str, localInclude);

        if (c == '<') preprocess(getchar(), aux, str, externalInclude); 

        return;
    }

    if(state == localInclude) {
        memset(str, 0, 100);
        for (int i = 0; c != aux; i++) {
            if (c == '\n') return;
            str[i] = c;
            c = getchar();
        } 
        FILE *archivoInclude;
        archivoInclude = fopen(str, "r+");

        if (archivoInclude == NULL){
            printf("El archivo ", str, " no pudo ser abierto");
            exit(-1);
        }else {
            while((c = fgetc(archivoInclude)) != EOF){
                putchar(c);
            }
            fclose(archivoInclude);
            return;
        }

    }
    if(state == externalInclude) {
        memset(str, 0, 100);
        for (int i = 0; c != '>'; i++) {
            if (c == '\n') return;
            str[i] = c;
            c = getchar();
        } 

        FILE *archivoInclude;
        char source[50];
        strcpy(source, "C:/MinGW/include/");     
        strcat(source, str);
        archivoInclude = fopen(source, "r+");


        if (archivoInclude == NULL){
            printf("El archivo ", str, " no pudo ser abierto");
            exit(-1);
        }else {
            while((c = fgetc(archivoInclude)) != EOF){
                putchar(c);
            }
            fclose(archivoInclude);
            return;
        }

    }

    if(state == constantValue) {
        char value[100];
        memset(value, 0, 100);
        for (int i = 0; c != ' ' && c != '\n'; i++) {
            value[i] = c;
            c = getchar();
        }
        install(str, value);        
    } 

    if(state == defineConstant) {
        struct nlist *found;
        memset(str, 0, 100);
        for (int i = 0; c != ' ' && c != ',' && c != ')' && c != ';'; i++) {
            if (c == '"') {
                putchar(c);
                c = getchar();
                while ( c != '"') {
                    putchar(c);
                    c = getchar();
                }
                putchar(c);
                c = getchar();
            }
            str[i] = c;
            c = getchar();
        }
        found = lookup(str);
        
        if (found != NULL) {
            printf(found->val);
            putchar(c);
            preprocess( getchar(), aux, str, defineConstant);
        }
        else {
            printf("%s", str);
            putchar(c);
            if(c == ')' || c == ';') return;
            preprocess( getchar(), aux, str, defineConstant);
        }
    }
}
