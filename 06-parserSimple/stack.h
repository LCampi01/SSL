#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED;
typedef enum {
    STARTING, 
    OPENING, 
    CLOSING, 
    BETWEEN_SINGLE_QUOTES_FROM_STARTING, 
    BETWEEN_DOUBLE_QUOTES_FROM_STARTING,
    BETWEEN_SINGLE_QUOTES_FROM_OPENING, 
    BETWEEN_DOUBLE_QUOTES_FROM_OPENING, 
    BETWEEN_SINGLE_QUOTES_FROM_CLOSING, 
    BETWEEN_DOUBLE_QUOTES_FROM_CLOSING,
    EQUILIBRATE,
    FAIL
} States;

void push(double c);
double pop();
States checkBrackets(char c, States state); 
void pushString(char *cadena);

#endif
