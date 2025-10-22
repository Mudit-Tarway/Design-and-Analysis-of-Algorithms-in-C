#include<stdio.h>
#include<limits.h>
#define MAX 20

int main(){
    int n,i,j;
    int cost [MAX] [MAX]; //Store the graph 
    int visited [MAX] = {0}; 
    int edges = 0; 
    int min, a, b; 
    int totalCost=0; 
    printf("Enter the number of verties: "); 
    scanf("%d", &n); 
    printf("Enter the Cost adjacency matrix (use 0 for no edge) \n"); 
    for (i=0; i<n; i++){ 
        for (j=0;j<n;j++) 
        { 
            scanf ("%d", &cost [i][j]); 
            if (cost[i][j] == 0)
            { 
                cost[i][j] = INT_MAX; 
            } 
        }
    }
    visited [0]=1; //Start from vertex 0
    printf ("\n Edges in the Minimum Spanning Tree:\n");
    printf("Edges It It Weight\n");
    printf("-----------------------\n");
    while (edges < (n-1)){
        min = INT_MAX;
        for (i=0; i<n; i++){
            if (visited[i]){
                for (j=0; j<n; j++) {
                    if (visited[j] && cost[i][j] < min)
                    { 
                        min = cost[i][j]; 
                        a = i; 
                        b = j; 
                    }
                }
            }
        }
        visited[b] = 1;
        printf ("%d \t %d \t %d\n", a, b, min);
        totalCost += min;
        edges++;
    }
    printf ("Total Cost of Minimum Spanning Tree = %d\n", totalCost);
    return 0;
}