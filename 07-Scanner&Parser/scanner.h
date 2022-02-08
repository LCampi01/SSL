#include <stdio.h>

#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED


enum TokenType {
    comment,
    numeral,
    define,
    undef,
    include,
    ifdef,
    endif,
    identifier,
    replaceText,
    lPar,
    rPar,
    lBrace,
    rBrace,
    lBracket,
    rBracket,
    punctuator,
    newLine,
    eof
};

typedef enum TokenType TokenType;

struct Token {
    TokenType type;
    char* value;
};

typedef struct Token Token; 

Token getNextToken(void);

#endif