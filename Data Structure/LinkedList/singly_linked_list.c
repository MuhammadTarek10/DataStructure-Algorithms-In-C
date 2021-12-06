#include "singly_linked_list.h"


int main(){
    SinglyLinkedList *l = create_singly_linked_list();

    insert_node_in_singly_linked_list(l, 10);
    insert_node_in_singly_linked_list(l, 11);
    insert_node_in_singly_linked_list(l, 12);
    insert_node_in_singly_linked_list(l, 13);

    print_singly_linked_list(l);

    return 0;
}