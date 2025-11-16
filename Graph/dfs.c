#include <stdio.h>
#define MAX 100

void dfs(int graph[MAX][MAX], int visited[], int node, int n) {
    printf("%d ", node);
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(graph, visited, i, n);
        }
    }
}

int main() {
    int n;
    int graph[MAX][MAX];
    int visited[MAX] = {0};
    int start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("DFS Traversal: ");
    dfs(graph, visited, start, n);
    return 0;
}
