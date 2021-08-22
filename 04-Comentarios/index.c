#include <stdio.h>
#include <stdlib.h>
#include "commentReplacer.h"

int main() {
    char c, aux;

    while( ( c = getchar() ) != EOF )
        commentReplacer(c, aux, 0);

    return 0;
}
