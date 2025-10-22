#include <stdio.h>
#define MAX 30

int parent[MAX];

// Function to find the root parent of a vertex
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to perform union of two sets
void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int n, edges = 1;
    int cost[MAX][MAX];
    int mincost = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix (enter 999 for no edge):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;  // No self loop
        }
    }

    // Initialize each vertex as its own parent
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    printf("\nThe edges of Minimum Cost Spanning Tree are:\n");
    while (edges < n) {
        int min = 999, a = -1, b = -1;

        // Find the edge with the smallest cost
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        // If an edge is found
        if (a != -1 && b != -1) {
            union_set(a, b);
            printf("Edge %d: (%d, %d) cost: %d\n", edges++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999; // Mark edge as used
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}


//0 is represented self loop and 999 is represented no edge