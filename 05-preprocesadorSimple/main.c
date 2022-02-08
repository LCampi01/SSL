#include <stdio.h>
#include "preprocess.h"

int main() {
    char c, aux, s[100];
    while( ( c = getchar() ) != EOF ) {
        preprocess(c, aux, s, 0);
    }
    return 0;
}
