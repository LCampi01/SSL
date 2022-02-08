
#include "commentReplacer.h"

enum {
    outOfCommentary = 0,
    possibleComment = 1,
    commentaryWithDoubleBar = 2,
    commentaryWithAsterisk = 3
};


void commentReplacer(char c, char aux, int state) {

    if(state == outOfCommentary) {
        if ( c == '/' ) {
            commentReplacer(c, aux, possibleComment);
            return;
        } else {
            putchar(c);
            return;
        }
    }

    if(state == possibleComment) {
        if ( ( aux = getchar() ) == '/') {
            commentReplacer(c, aux, commentaryWithDoubleBar);
            return;
        } else if (aux == '*') {
            commentReplacer(c, aux, commentaryWithAsterisk);
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
}