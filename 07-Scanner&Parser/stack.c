#include "stack.h"

char* pila[100]; /* valores de la pila */
int sp = 0; /* siguiente posición libre en la pila */

void push(char* c)
{
    if (sp < 100)
        pila[sp++] = c;
}

char* pop(void)
{
    if (sp > 0)
        return pila[--sp];
    else {
        return 0;
    }
}