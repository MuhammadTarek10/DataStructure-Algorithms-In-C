#include "doubly_linked_list.h"


int main(){
    DoublyLinkedList *l = create_doubly_linked_list();

    insert_node_in_doubly_linked_list(l, 10);
    insert_node_in_doubly_linked_list(l, 11);
    insert_node_in_doubly_linked_list(l, 12);
    insert_node_in_doubly_linked_list(l, 13);

    print_doubly_linked_list_forward(l);
    printf("\n\n");
    print_doubly_linked_list_backward(l);

    return 0;
}