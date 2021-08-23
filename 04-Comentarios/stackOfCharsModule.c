
#include "stackOfCharsModule.h"

int checkBrackets(char c, struct Stack* stack) {
    char top;
    switch (c)
    {
    case '[':
    case '{':
    case '(':
        push(stack, c);
        break;
    case ']':
        top = pop(stack);
        printf("Character is %d \n", top);
        if(top != '[')
            return 0;
        break;
    case '}':
        top = pop(stack);
        printf("Character is %d \n", top);
        if(top != '{')
            return 0;
        break;
    case ')':
        top = pop(stack);
        printf("Character is %d \n", top);
        if(top != '(')
            return 0;
        break;
    default:
        break;
    }
    return 1;
}


#define MAX 100

struct Stack {
    char top;
    unsigned capacity;
    char* array;
};
 
// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}
 
// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 
// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
 
// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}
 
// Function to return the top from stack without removing it
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}
