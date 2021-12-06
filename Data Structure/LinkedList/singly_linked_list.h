#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct SinglyLinkedList SinglyLinkedList;
typedef struct SinglyLinkedListNode SinglyLinkedListNode;

struct SinglyLinkedList{
    SinglyLinkedListNode *head;
    int size;
};

struct SinglyLinkedListNode{
    int value;
    SinglyLinkedListNode *next;
};

SinglyLinkedList *create_singly_linked_list(){
    SinglyLinkedList *l = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    l->head = NULL;
    l->size = 0;
    return l;
}

bool is_empty(SinglyLinkedList *l){
    return (l->size==0);
}

void insert_node_in_singly_linked_list(SinglyLinkedList *l, int value){
    SinglyLinkedListNode *newNode = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    newNode->value = value;
    newNode->next = NULL;

    SinglyLinkedListNode *temp = l->head;

    while(temp!=NULL && temp->next!=NULL)
        temp = temp->next;

    if(temp==NULL)
        l->head = newNode;
    else
        temp->next = newNode;
     
    l->size++;
}

void print_singly_linked_list(SinglyLinkedList *l){
    SinglyLinkedListNode *temp = l->head;
    while(temp!=NULL){
        printf("[%d]\n", temp->value);
        temp = temp->next;
    }
}