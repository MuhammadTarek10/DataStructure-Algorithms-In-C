#include "graph.h"


int main(){
    Graph *g = create_graph(6, false);
    add_to_graph(g, 2, 4, 5);
    add_to_graph(g, 2, 5, 10);

    print_graph(g);
    return 0;
}