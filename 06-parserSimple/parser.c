#include "stack.h"

int main(){
    char c;

    while( ( c = getchar() ) != EOF ) {
        if ( checkBrackets(c) ) {
            fprintf(stderr, "Brackets mal balanceados. \n", strerror( 1 ));
            abort();
        }
    }

    double prueba = pop();
    if(prueba != 0.0){
        fprintf(stderr, "Brackets mal balanceados. \n", strerror( 1 ));
    }

    return 0;
}