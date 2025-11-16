#include <stdio.h>
#define INF 9999
#define V 5 

int minDistance(int dist[], int visited[]) {
    int min = INF, min_index;
    for (int i = 0; i < V; i++) {
        if (visited[i] == 0 && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];     
    int visited[V];   
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;  
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);  
        visited[u] = 1;  
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 && 
                dist[u] + graph[u][v] < dist[v]) {
                
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    dijkstra(graph, 0);  
    return 0;
}
