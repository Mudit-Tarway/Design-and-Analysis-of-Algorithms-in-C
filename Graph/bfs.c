#include <stdio.h>
#define MAX 100

void bfs(int graph[MAX][MAX], int visited[], int start, int n) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    printf("BFS Traversal: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
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
    printf("Enter starting node: ");
    scanf("%d", &start);
    bfs(graph, visited, start, n);
    return 0;
}
