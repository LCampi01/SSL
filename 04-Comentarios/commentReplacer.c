
#include "commentReplacer.h"

enum {
    outOfCommentary = 0,
    possibleComment = 1,
    commentaryWithDoubleBar = 2,
    commentaryWithAsterisk = 3
};


void commentReplacer(char c, char aux, int state, FILE *source, FILE *destination) {

    if(state == outOfCommentary) {
        if ( c == '/' ) {
            commentReplacer(c, aux, possibleComment, source, destination);
            return;
        } else {
            fputc(c, destination);
            return;
        }
    }

    if(state == possibleComment) {
        if ( ( aux = fgetc(source) ) == '/') {
            commentReplacer(c, aux, commentaryWithDoubleBar, source, destination);
            return;
        } else if (aux == '*') {
            commentReplacer(c, aux, commentaryWithAsterisk, source, destination);
            return;
        } else {
            fputc(c, destination);
            fputc(aux, destination);
            return;
        }
    }

    if (state == commentaryWithDoubleBar) {
        char current;
        while( ( current = fgetc(source) ) != EOF ) {
            if( current == '\n') {
                fputc(current, destination);
                return;
            }
        }
    }
    
    if (state == commentaryWithAsterisk) {
        char current, currentAux;
        while((current = fgetc(source) ) !=EOF ) {
            if(current == '*')
            {
                currentAux = fgetc(source);
                if(currentAux == '/')
                    return;
            }
        }
    }
}