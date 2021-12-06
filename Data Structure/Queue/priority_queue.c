#include "priority_queue.h"

int main(){
    PriorityQueue *q = create_queue();
    enqueue(q, 'x', 10);
    enqueue(q, 'A', 20);
    enqueue(q, 'V', 30);
    enqueue(q, 'V', 13);

    while(!is_empty(q)){
        dequeue(q);
    }
    return 0;
}