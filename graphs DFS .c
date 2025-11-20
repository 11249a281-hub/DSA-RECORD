#include <stdio.h>

#define MAX 100

int graph[MAX][MAX]; // adjacency matrix
int visited[MAX];
int n; // number of vertices

// DFS function
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    // Input edges
    printf("Enter edges (u v): \n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // remove this line if graph is directed
    }

    printf("DFS Traversal starting from vertex 0: ");
    dfs(0);
    printf("\n");

    return 0;
}
