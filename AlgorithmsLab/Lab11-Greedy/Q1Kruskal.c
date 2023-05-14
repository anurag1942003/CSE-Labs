#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_EDGES 10

typedef struct {
    int u;//source u
    int v;//destination v
    int w;//weight
} Edge;

int find(int parent[], int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

/*The line Edge* a1 = (Edge*)a; is used to cast the generic void pointer a to a pointer of type Edge.*/

int compare(const void* a, const void* b) {
    /*Edge* a1 is a pointer to an object of type Edge, 
    while (Edge*)a is a type cast of a void pointer a to a pointer to Edge.*/
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->w - b1->w;
}

void kruskalMST(int graph[][MAX_EDGES], int n) {
    Edge edges[n * n];
    int e = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                edges[e].u = i;
                edges[e].v = j;
                edges[e].w = graph[i][j];
                e++;
            }
        }
    }

    qsort(edges, e, sizeof(Edge), compare);
    /*quicksort algorithm that has base aka pointer to array, num of ele, size of each ele, compare function basis*/

    Edge result[n - 1]; //size n-1 and is used to store the edges of MST
    int parent[n];
    memset(parent, -1, sizeof(parent));
    /*The memset function is used to initialize all elements of the parent array to -1
    element is not yet associated with any parent node in the disjoint set forest.*/

    int count = 0;
    int i = 0;
    while (count < n - 1 && i < e) {
        Edge next_edge = edges[i++];
        /*next_edge is set to the i-th edge in the edges array,and then 
        i is incremented to consider the next edge in the next iteration of the loop.*/
        int x = find(parent, next_edge.u);
        int y = find(parent, next_edge.v);
        if (x != y) {
            result[count++] = next_edge;
            unionSet(parent, x, y);
        }
    }

    printf("Minimum Spanning Tree Edges:\n");
    for (i = 0; i < count; ++i) {
        printf("%d - %d \tWeight: %d\n", result[i].u, result[i].v, result[i].w);
    }
}   

int main() {
    int graph[][MAX_EDGES] = {{0, 5, 7, 0, 2},
                              {5, 0, 0, 6, 3},
                              {7, 0, 0, 4, 4},
                              {0, 6, 4, 0, 5},
                              {2, 3, 4, 5, 0}};
    kruskalMST(graph, 5);
    return 0;
}