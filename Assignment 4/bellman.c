#include <stdio.h>
#include <limits.h>

#define MAX 100

void bellmanFord(int graph[MAX][3], int edges, int vertex, int dist[], int pred[], int src)
{
    dist[src] = 0;

    // Initialize predecessor array
    for (int i = 0; i < vertex; i++)
    {
        pred[i] = -1; // -1 indicates no predecessor
    }

    for (int i = 1; i < vertex; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            int u = graph[j][0];
            int v = graph[j][1];
            int wt = graph[j][2];
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                pred[v] = u; // Update predecessor
            }
        }
    }
}

void printShortestPath(int src, int vertex, int dist[], int pred[])
{
    printf("Shortest paths from source %d:\n", src);
    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < vertex; i++)
    {
        if (i == src)
            continue;

        // Print vertex and distance
        printf("%d\t%d\t\t", i, dist[i]);

        // Print path by backtracking through predecessors
        int current = i;
        printf("%d ", current);
        while (pred[current] != -1)
        {
            printf("<- %d ", pred[current]);
            current = pred[current];
        }
        printf("\n");
    }
}

int main()
{
    int vertex, edges, src;
    printf("Enter number of vertices: ");
    scanf("%d", &vertex);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    int dist[vertex], pred[vertex];
    int graph[edges][3];

    printf("Enter adjacency list:\n");
    for (int i = 0; i < edges; i++)
    {
        printf("Enter source destination weight: ");
        scanf("%d %d %d", &graph[i][0], &graph[i][1], &graph[i][2]);
    }

    for (int i = 0; i < vertex; i++)
    {
        dist[i] = INT_MAX;
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    bellmanFord(graph, edges, vertex, dist, pred, src);
    printShortestPath(src, vertex, dist, pred);

    return 0;
}
