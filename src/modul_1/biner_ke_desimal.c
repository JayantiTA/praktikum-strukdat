#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

/* Struktur Node */

typedef struct queueNode_t {
    int data;
    struct queueNode_t *next;
} QueueNode;

/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

/* Function prototype */

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, int value);
void queue_pop(Queue *queue);
int  queue_front(Queue *queue);
int  queue_size(Queue *queue);

/* Function definition below */

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, int value)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;

        queue->_size--;
    }
}

int queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size;
}

int main(int argc, char const *argv[])
{
    // Buat objek QueueArray
    Queue myQueue;

    // PENTING! Jangan lupa diinisialisasi
    queue_init(&myQueue);

    int n, i;
    scanf("%d", &n);

    char arr[n];
    int bil[n];
    for(i = 0; i <= n; i++)
    {
        scanf("%c", &arr[i]);
        bil[i] = arr[i] - 48;
        queue_push(&myQueue, bil[i]);
    }
    
    int angka[n], j = 0;
    for(i = 0; i <= n; i++)
    {
        if(queue_front(&myQueue) == 0 || queue_front(&myQueue) == 1)
        {
            angka[j] = queue_front(&myQueue);
            j++;
        }
        queue_pop(&myQueue);
    }
 
    
    int a = 0, b = 0,c = 0;
    
    for(i = 0; i < j - 2; i ++)
    {
        a += angka[i] * pow(2, (j-3-i));
    }
    printf("%d ", a);
    
    for(i = 0; i < j - 1; i ++)
    {
        b += angka[i] * pow(2, (j-2-i));
    }
    printf("%d ", b);
    
    for(i = 0; i < j; i ++)
    {
        c += angka[i] * pow(2, (j-1-i));
    }
    printf("%d ", c);
    

    puts("");
    return 0;
}