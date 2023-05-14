#include <stdio.h>
#include <limits.h>

#define INF 100
#define V 4

void printSolution(int graph[][V]) {
    printf("Shortest graphances between all pairs of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INF)
                printf("%s \t", "INF");
            else
                printf("%d \t", graph[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][V]) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF
                    && graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    printSolution(graph);
}

void main() {
    int graph[][V]={{0, INF, 3, INF},
                    {2, 0, INF, INF},
                    {INF, 7, 0, 1},
                    {6, INF, INF, 0}};
    floydWarshall(graph);
}