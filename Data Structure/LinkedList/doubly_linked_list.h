#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct DoublyLinkedList DoublyLinkedList;
typedef struct DoublyLinkedListNode DoublyLinkedListNode;

struct DoublyLinkedList{
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;
    int size;
};

struct DoublyLinkedListNode{
    int value;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *previous;
};

DoublyLinkedList *create_doubly_linked_list(){
    DoublyLinkedList *l = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    l->head = l->tail = NULL;
    l->size = 0;
    return l;
}

bool is_empty(DoublyLinkedList *l){
    return (l->size==0);
}

void insert_node_in_doubly_linked_list(DoublyLinkedList *l, int value){
    DoublyLinkedListNode *newNode = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
    newNode->value = value;
    newNode->next = newNode->previous = NULL;

    if(l->head==NULL)
        l->head = l->tail = newNode;
    else{
        newNode->previous = l->tail;
        l->tail->next = newNode;
        l->tail = newNode;
    }
    l->size++;
}

void print_doubly_linked_list_forward(DoublyLinkedList *l){
    DoublyLinkedListNode *temp = l->head;
    while(temp!=NULL){
        printf("[%d]\n", temp->value);
        temp = temp->next;
    }
}


void print_doubly_linked_list_backward(DoublyLinkedList *l){
    DoublyLinkedListNode *temp = l->tail;
    while(temp!=NULL){
        printf("[%d]\n", temp->value);
        temp = temp->previous;
    }
}