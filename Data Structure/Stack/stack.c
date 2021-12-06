#include "stack.h"


int main(){
    Stack *s = create_stack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);

    while(!is_empty(s)){
        pop(s);
    }
    return 0;
}