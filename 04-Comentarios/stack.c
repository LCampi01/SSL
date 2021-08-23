#include "stack.h"

int checkBrackets(char c, struct Stack* stack) {
    char top;
    switch (c) {
    case '[':
    case '{':
    case '(':
        push(stack, c);
        break;
    case ']':
        top = pop(stack);
        if(top != '[')
            return 1;
        break;
    case '}':
        top = pop(stack);
        if(top != '{')
            return 1;
        break;
    case ')':
        top = pop(stack);
        if(top != '(')
            return 1;
        break;
    default:
        break;
    }
    return 0;
}


#define MAX 100

struct Stack {
    char top;
    unsigned capacity;
    char* array;
};


struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}