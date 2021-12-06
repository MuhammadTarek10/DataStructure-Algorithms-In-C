#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Heap Heap;

struct Heap{
    int *arr;
    int size;
};

Heap* create_heap(int max_size){
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->arr = (int*)malloc(sizeof(int)*max_size);
    h->size = 0;

    return h;
}

bool is_empty(Heap* h){
    return (h->size==0);
}

void swap(int* num1, int* num2){
    *num1 = *num1+*num2;
    *num2 = *num1-*num2;
    *num1 = *num1-*num2;
}

int max(int num1, int num2){
    return num1>num2? num1:num2;
}

int min(int num1, int num2){
    return num1<num2? num1:num2;
}

void insert_max_heap(Heap* h, int value){
    h->arr[++h->size] = value;
    int child_idx = h->size;
    while(child_idx>1 && h->arr[child_idx]>h->arr[child_idx/2])
        swap(&h->arr[child_idx], &h->arr[child_idx/2]);
}

int extract_from_heap(Heap *h){
    if(is_empty(h))
        return -1;
    
    int value = h->arr[1];
    h->arr[1] = h->arr[h->size--];
    int parent_idx = 1;
    int left_child_idx, right_child_idx;
    do{
        left_child_idx = parent_idx*2;
        right_child_idx = parent_idx*2+1;

        if(h->arr[parent_idx] > max(h->arr[left_child_idx], h->arr[right_child_idx]))
            break;

        if(h->size == left_child_idx || h->arr[left_child_idx] > h->arr[right_child_idx]){
            swap(&h->arr[parent_idx], &h->arr[left_child_idx]);
            parent_idx = left_child_idx;
        }
        else if(h->arr[right_child_idx] > h->arr[left_child_idx]){
            swap(&h->arr[parent_idx], &h->arr[right_child_idx]);
            parent_idx = right_child_idx;
        }
    }while(parent_idx>h->size);
    return value;
}