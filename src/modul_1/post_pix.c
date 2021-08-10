#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
int stack_pop(Stack *stack);
int stack_top(Stack *stack);
void infix_to_postfix(char infix[], char postfix[]);
int precedence(char x);

/* Function definition below */

void stack_init(Stack *stack) {
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) {
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;

        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

int stack_pop(Stack *stack) {
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        return temp->data;
        free(temp);
        stack->_size--;
    }
    return 0;
}

int stack_top(Stack *stack) {
    if (!stack_isEmpty(stack))
        return stack->_top->data;
    return 0;
}

void infix_to_postfix(char infix[],char postfix[])
{
    Stack myStack;
    char out, in;
    int i, j;
    stack_init(&myStack);
    j=0;

    for(i = 0; infix[i] != '\0'; i++)
    {
        in = infix[i];
        if((in >= 'A' && in <= 'Z') || (in >= 'a' && in <= 'z') || (in >= '1' && in <= '9'))
            postfix[j++] = in;
        else if(in == '(')
            stack_push(&myStack, '(');
        else if(in == ')')
            while((out = stack_pop(&myStack)) != '(')
                postfix[j++] = out;
        else
        {
            while(precedence(in) <= precedence(stack_top(&myStack)) && !stack_isEmpty(&myStack))
            {
                out = stack_pop(&myStack);
                postfix[j++] = out;
            }
            stack_push(&myStack,in);
        }
    }

    while(!stack_isEmpty(&myStack))
    {
        out = stack_pop(&myStack);
        postfix[j++] = out;
    }

    postfix[j] = '\0';
}

int precedence(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/' || x == '%')
        return 2;

    return 3;
}

int main(int argc, char const *argv[]) 
{
    char infix[100], postfix[100];
    int N, i;
    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%s", infix);
        infix_to_postfix(infix, postfix);
        printf("%s\n", postfix);
    }

    puts("");
    return 0;
}
