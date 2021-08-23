#include <stdio.h>
#include <stdlib.h>
#include "commentReplacer.h"
#include "stackOfCharsModule.h" 


int main() {
    char c, aux;
    struct Stack* stack = createStack(100);
    while( ( c = getchar() ) != EOF ){
        commentReplacer(c, aux, 0);
        if (!checkBrackets(c, stack)){
            puts("Los brackets no estan correctamente equilibrados");            
        }
    }
    return 0;
}
