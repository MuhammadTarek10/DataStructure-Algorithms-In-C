#include "queue.h"

int main(){
    Queue *q = creat_queue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    while(!is_empty(q)){
        dequeue(q);
    }

    return 0;
}