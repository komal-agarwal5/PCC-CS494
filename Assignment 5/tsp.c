#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct Graph
{
    int v;
    int *vertices;
    int **adjMatrix;
}graph;

int search(int arr[], int n, int key)
{
    int i;
    for (i=0; i<n; i++)
        if (arr[i] == key)
            return i;
}

graph create()
{
    graph g;
    int i, j, n, s, d, w;

    printf("Enter the number of vertices : ");
    scanf("%d", &g.v);
    
    g.vertices = (int *)malloc(g.v * sizeof(int));
    
    g.adjMatrix = (int **)malloc(g.v * sizeof(int *));
    for (i=0; i<g.v; i++)
        g.adjMatrix[i] = (int *)malloc(g.v * sizeof(int));
    for (i=0; i<g.v; i++)
            for (j=0; j<g.v; j++)
            {
                if (i != j)
                    g.adjMatrix[i][j] = INT_MAX;
                else
                    g.adjMatrix[i][j] = 0;
            }

    printf("Enter the vertices : ");
    for (i=0; i<g.v; i++)
        scanf("%d", &g.vertices[i]);
    
    printf("Enter the number of edges : ");
    scanf("%d", &n);
    printf("Enter the source, destination and weights :\n");
    for (i=0; i<n; i++)
    {
        scanf("%d %d %d", &s, &d, &w);
        g.adjMatrix[search(g.vertices, g.v, s)][search(g.vertices, g.v, d)] = w;
        g.adjMatrix[search(g.vertices, g.v, d)][search(g.vertices, g.v, s)] = w;
    }
    
    return g;
}

int salesman(graph g, int src, int i, int mask, int dp[][g.v], int pred[])
{
    if (mask == (1 << g.v)-1)
    {
        return g.adjMatrix[i][src];
    }
    
    if (dp[i][mask] != -1)
    {
        return dp[i][mask];
    }

    int dist = INT_MAX, j, x;
    for (j=0; j<g.v; j++)
    {
        if (((mask & (1 << j)) == 0) && (j != i) && (j != src))
        {
            x = salesman(g, src, j, mask | (1 << j), dp, pred) + g.adjMatrix[i][j];
            if (x < dist)
            {
                dist = x;
                pred[mask] = j;
            }
        }
    }
    dp[i][mask] = dist;
    return dist;
}

void display(graph g, int pred[], int src)
{
    int i, mask = 1 << src, t;
    printf("Path :\t%d -> ", g.vertices[src]);
    while (mask != (1<<g.v)-1)
    {
    	t = pred[mask];
    	printf("%d -> ", g.vertices[t]);
    	mask |= (1<<t);
    }
    printf("%d\n", g.vertices[src]);
}

int main()
{
    graph g = create();
    
    int src, i;
    printf("Enter the source : ");
    scanf("%d", &src);
    src = search(g.vertices, g.v, src);
    
    int mask = 1<<src;
    
    int dp[g.v][1<<g.v];
    memset(dp, -1, sizeof(dp));
    
    int pred[1<<g.v];
    memset(pred, -1, sizeof(pred));

    printf("Distance : %d\n", salesman(g, src, src, mask, dp, pred));
    display(g, pred, src);

    return 0;
}

