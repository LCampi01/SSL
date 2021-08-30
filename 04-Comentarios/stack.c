#include "stack.h"
#define ESPACIO 100 
int pila[ESPACIO]; /* valores de la pila */
int sp = 0; /* siguiente posición libre en la pila */

int checkBrackets(char c) {
    char top;
    switch (c) {
    case '[':
    case '{':
    case '(':
        push(c);
        break;
    case ']':
        top = pop();
        if(top != '[')
            return 1;
        break;
    case '}':
        top = pop();
        if(top != '{')
            return 1;
        break;
    case ')':
        top = pop();
        if(top != '(')
            return 1;
        break;
    default:
        break;
    }
    return 0;
}

void push(double c)
{
    if (sp < ESPACIO)
        pila[sp++] = c;
    else
        printf("error: pila llena, no puede efectuar push %g\n", c);
}

double pop(void)
{
    if (sp > 0)
        return pila[--sp];
    else {
        printf("error: pila vacía\n");
        return 0.0;
    }
}
