#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct PriorityQueue PriorityQueue;
typedef struct QueueNode QueueNode;

struct PriorityQueue{
    QueueNode *front, *rear;
    int size;
};

struct QueueNode{
    char value;
    int priority;
    QueueNode *next;
};

bool is_empty(PriorityQueue *q){
    return (q->size==0);
}

PriorityQueue *create_queue(){
    PriorityQueue *q = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(PriorityQueue *q, char value, int priority){
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->value = value;
    newNode->priority = priority;
    newNode->next = NULL;

    if(is_empty(q))
        q->rear = q->front = newNode;
    else{
        QueueNode *currentNode = q->front;
        int flag = 1;
        if(currentNode->priority<priority){
            newNode->next = currentNode;
            q->front = newNode;
            flag = 0;
        }
        while(flag){
            if(currentNode->next==NULL){
                currentNode->next = newNode;
                break;
            }
            else if(currentNode->next->priority<priority){
                newNode->next = currentNode->next;
                currentNode->next = newNode;
                break;
            }
            else
                currentNode = currentNode->next;
        }
    }
    q->size++;
}

void dequeue(PriorityQueue *q){
    if(!is_empty(q)){
        char value = q->front->value;
        int priority = q->front->priority;
        QueueNode* temp = q->front;
        q->front = q->front->next;
        free(temp);
        q->size--;
        printf("Value: [%c], Priority: [%d]\n", value, priority);
    }
    else
        printf("Queue is Empty\n");
}
