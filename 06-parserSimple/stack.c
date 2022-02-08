#include "stack.h"
enum Stack {espacio = 100} ;

int pila[espacio]; /* valores de la pila */
int sp = 0; /* siguiente posición libre en la pila */
States checkBrackets(char c, States state) {
    double top;
    switch (state) {
        case STARTING:
            switch (c) {
                case '[':
                case '{':
                case '(':
                    push(c);
                    return OPENING;    
                case 39: // ASCII COMILLA SIMPLE '
                    return BETWEEN_SINGLE_QUOTES_FROM_STARTING;
                case 34: // ASCII COMILLA DOBLE "
                    return BETWEEN_DOUBLE_QUOTES_FROM_STARTING;
                case EOF:
                    return EQUILIBRATE;
                case ']':
                case '}':
                case ')':                    
                    return FAIL;
                default:
                    return STARTING;
            }
            break;
        
        case OPENING:

            switch (c) {
                case '[':
                case '{':
                case '(':
                    push(c);
                    return OPENING;    
                case ']':
                    top = pop();
                    if(top != '[')
                        return FAIL;
                    return CLOSING;
                case '}':
                    top = pop();
                    if(top != '{')
                        return FAIL;
                    return CLOSING;
                case ')':
                    top = pop();
                    if(top != '(')
                        return FAIL;
                    return CLOSING;
                case 39: // ASCII COMILLA SIMPLE '
                    return BETWEEN_SINGLE_QUOTES_FROM_OPENING;
                case 34: // ASCII COMILLA DOBLE "
                    return BETWEEN_DOUBLE_QUOTES_FROM_OPENING;
                case EOF:
                    return FAIL;
                default:
                    return OPENING;
            }

            break;

        case BETWEEN_SINGLE_QUOTES_FROM_STARTING:
            switch (c) {
                case 39: // ASCII COMILLA SIMPLE '
                    return STARTING;
                case EOF:
                    return FAIL;
                default:
                    return BETWEEN_SINGLE_QUOTES_FROM_STARTING;
            }
            break;

        case BETWEEN_SINGLE_QUOTES_FROM_OPENING:
            switch (c) {
                case 39: // ASCII COMILLA SIMPLE '
                    return OPENING;
                case EOF:
                    return FAIL;
                default:
                    return BETWEEN_SINGLE_QUOTES_FROM_OPENING;
            }
            break;

        case BETWEEN_SINGLE_QUOTES_FROM_CLOSING:
            switch (c) {
                case 39: // ASCII COMILLA SIMPLE '
                    return CLOSING;
                case EOF:
                    return FAIL;
                default:
                    return BETWEEN_SINGLE_QUOTES_FROM_CLOSING;
            }
            break;

        case BETWEEN_DOUBLE_QUOTES_FROM_STARTING:
            switch (c) {
                case 34: // ASCII COMILLA DOBLE "
                    return STARTING;
                case EOF:
                    return FAIL;
                default:
                    return BETWEEN_DOUBLE_QUOTES_FROM_STARTING;
            }
            break;

        case BETWEEN_DOUBLE_QUOTES_FROM_OPENING:
            switch (c) {
                case 34: // ASCII COMILLA DOBLE "
                    return OPENING;
                case EOF:
                    return FAIL;
                default:
                    return BETWEEN_DOUBLE_QUOTES_FROM_OPENING;
            }
            break;

        case BETWEEN_DOUBLE_QUOTES_FROM_CLOSING:
            switch (c) {
                case 34: // ASCII COMILLA DOBLE "
                    return CLOSING;
                case EOF:
                    return FAIL;
                default:
                    return BETWEEN_DOUBLE_QUOTES_FROM_CLOSING;
                
            }
            break;

        case CLOSING:

            switch (c) {
                case '[':
                case '{':
                case '(':
                    push(c);
                    return OPENING;    
                case ']':
                    top = pop();
                    if(top != '[')
                        return FAIL;
                    return CLOSING;
                case '}':
                    top = pop();
                    if(top != '{')
                        return FAIL;
                    return CLOSING;
                case ')':
                    top = pop();
                    if(top != '(')
                        return FAIL;
                    return CLOSING;
                case 39: // ASCII COMILLA SIMPLE '
                    return BETWEEN_SINGLE_QUOTES_FROM_CLOSING;
                case 34: // ASCII COMILLA DOBLE "
                    return BETWEEN_DOUBLE_QUOTES_FROM_CLOSING;
                case EOF:
                    if (pop() == 0.0){
                        return EQUILIBRATE;
                    }
                    return FAIL;
                default:
                    return CLOSING;
            }

        break;

    }
}

void push(double c)
{
    if (sp < espacio)
        pila[sp++] = c;
    else
        printf("error: pila llena, no puede efectuar push %g\n", c);
}

double pop(void)
{
    if (sp > 0)
        return pila[--sp];
    else {
        return 0.0;
    }
}

int getSize (char * s) {
    char * t;
    int tamanio = 0;

    for (t = s; *t != '\0'; t++) {
        tamanio++;
    }

    return tamanio;
}

void pushString(char *cadena){
    int tamanio = getSize(cadena);
    for(int i=0; i < tamanio; i++){
        push(cadena[i]);
    }
}

