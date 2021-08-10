#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
int stack_search(Stack *stack, int search, int len) ;
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack))
        return stack->_top->data;
    return 0;
}

int stack_search(Stack *stack, int search, int len) 
{
    int index = -1, i;
    if (!stack_isEmpty(stack))
    {
        for(i = 0; i < len; i++)
        {
            if(search == stack_top(stack))
            {
                index = i;
                return index;
            }
            else
                stack_pop(stack);
        }
    }
    
    return -1;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main(int argc, char const *argv[])
{
    Stack myStack;

    stack_init(&myStack);

    int i, j, S;
    unsigned int T, N;
    scanf("%u", &T);
    for(i = 0; i < T; i++)
    {
        scanf("%u", &N);
        int X[N];
        for(j = 0; j < N; j++)
        {
            scanf("%d", &X[j]);
            stack_push(&myStack, X[j]);
        }
        scanf("%d", &S);
        printf("%d", stack_search(&myStack, S, N));
        
        while (!stack_isEmpty(&myStack))
        {
            stack_pop(&myStack);
        }
        
        puts("");
    }

    return 0;
}
