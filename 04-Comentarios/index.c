#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "commentReplacer.h"
#include "stack.h"

int main() {
    char c, aux;
    struct Stack* stack = createStack(100);


    while( ( c = getchar() ) != EOF ) {
        if ( checkBrackets(c, stack) ) {
            fprintf(stderr, "Brackets mal balanceados. \n", strerror( 1 ));
            abort();
        }
        commentReplacer(c, aux, 0);
    }

    return 0;
}
