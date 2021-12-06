#include "heap.h"


int main(){

    Heap* h = create_heap(100);
    insert_max_heap(h, 8);
    insert_max_heap(h, 5);
    insert_max_heap(h, 213);
    insert_max_heap(h, 2);
    insert_max_heap(h, 66);
    insert_max_heap(h, 0);

    printf("[%d]\n", extract_from_heap(h));
    printf("[%d]\n", extract_from_heap(h));
    printf("[%d]\n", extract_from_heap(h));
    printf("[%d]\n", extract_from_heap(h));

    return 0;
}

