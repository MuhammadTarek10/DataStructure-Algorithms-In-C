#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Graph Graph;
typedef struct EdgeNode EdgeNode;

struct Graph {
    EdgeNode** edges;
    int number_of_nodes;
    int number_of_edges;
    bool is_directed;
};

struct EdgeNode{
    int v;
    int weight;
    EdgeNode *next;
};

Graph* create_graph(int number_of_nodes, bool is_directed){
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->number_of_nodes = number_of_nodes;
    g->number_of_edges = 0;
    g->is_directed = is_directed;
    g->edges = (EdgeNode**)malloc(sizeof(EdgeNode*)*number_of_nodes);
    for(int i = 0; i<number_of_nodes; i++)
        g->edges[i] = NULL;
    return g;
}

void print_graph(Graph *g){
    for(int i=0; i<g->number_of_nodes; i++){
        printf("For [%d]", i);
        EdgeNode *e = g->edges[i];
        while(e!=NULL){
            printf(", connected to: [%d]", e->v);
            e = e->next;
        }
        printf("\n");
    }
}

void add_to_graph(Graph *g, int i, int v, int weight){
    EdgeNode *e = (EdgeNode*)malloc(sizeof(EdgeNode));
    e->v = v;
    e->weight = weight;
    e->next = g->edges[i];
    g->edges[i] = e;
    if(!g->is_directed){
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        e->v = i;
        e->weight = weight;
        e->next = g->edges[v];
        g->edges[v] = e;
    }
    g->number_of_edges++;
}