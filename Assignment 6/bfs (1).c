#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void Graph_BFS(int n, int adj[n][n], int s)
{
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    int queue[n];
    int front = 0, rear = 0;

    visited[s] = true;
    queue[rear++] = s;

    while (front != rear) {
        s = queue[front++];
        printf("%d ", s);

        for (int adjacent = 0; adjacent < n; adjacent++) {
            if (adj[s][adjacent] && !visited[adjacent]) {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }
}

int main()
{
    int n, s;
    printf("Enter the number of vertices: \n");
    scanf("%d", &n);
    int adj[n][n];

    printf("Enter the Adjacency matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the source vertex: \n");
    scanf("%d", &s);

    printf("Following is Breadth First Traversal: \n");
    Graph_BFS(n, adj, s);
    return 0;
}

