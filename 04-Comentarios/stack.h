#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED;


struct Stack* createStack(unsigned capacity);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, char item);
int pop(struct Stack* stack);
int peek(struct Stack* stack);
int checkBrackets(char c, struct Stack* stack); 

#endif
