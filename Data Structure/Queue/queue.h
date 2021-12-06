#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue Queue;
typedef struct QueueNode QueueNode;

struct QueueNode{
    int value;
    QueueNode* next;
};

struct Queue{
    QueueNode *front;
    QueueNode *rear;
    int size;  
};

bool is_empty(Queue *q){
    return (q->size==0);
}

Queue* creat_queue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue* q, int value){
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->value = value;
    newNode->next = NULL;
    if(is_empty(q))
        q->rear = q->front = newNode;
    else
        q->rear->next = newNode, q->rear = newNode;
    q->size++;
    printf("[%d] had been enqueued into the queue\n", q->rear->value);
    printf("Now size is [%d]\n", q->size);
}

void dequeue(Queue *q){
    if(!is_empty(q)){
        int value = q->front->value;
        QueueNode* temp = q->front;
        q->front = q->front->next;
        free(temp);
        q->size--;
        printf("[%d] had been dequeued from queue\n", value);
        printf("Now size is [%d]\n", q->size);
    }
    else
        printf("Queue is Empty\n");
}