#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode StackNode;
typedef struct Stack Stack;

struct StackNode{
    int value;
    StackNode *next;
};


struct Stack{
    StackNode *top;
    int size;
};


Stack* create_stack(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->size = 0;
    s->top = NULL;
    return s;
}

int is_empty(Stack* s){
    return (s->size==0);
}


void push(Stack* s, int value){
    StackNode *newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->value = value;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
    printf("[%d] had been pushed into stack\n", value);
    printf("Now size is = [%d]\n", s->size);
}

void pop(Stack* s){
    if(!is_empty(s)){
        StackNode* temp = s->top;
        s->top = s->top->next;
        printf("[%d] had been poped from the stack\n", temp->value);
        free(temp);
        s->size--;
        printf("Now size is = [%d]\n", s->size);
    }
    else
        printf("Stack is Empty\n");
}


int peek(Stack* s){
    return s->top->value;
}