#include "binary_tree.h"

int main(){
    Tree* t = create_tree();
    insert_to_tree(t, 10);
    insert_to_tree(t, 8);
    insert_to_tree(t, 12);
    insert_to_tree(t, 7);
    insert_to_tree(t, 11);
    insert_to_tree(t, 9);
    insert_to_tree(t, 13);

    print_tree(t->root);
    
    return 0;
}