#include<stdio.h>

void dfs(int vCount, int adjMatrix[][vCount], int start, int visited[]) {
    visited[start] = 1;
    printf("%d ", start);

    for(int i = 0; i < vCount; i++) {
        if(adjMatrix[start][i] && !visited[i]) {
            dfs(vCount, adjMatrix, i, visited);
        }
    }
}

int main() {
    int v, s;
    printf("Enter the no. of vertices: \n");
    scanf("%d", &v);
    int adj[v][v];

    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the source vertex: \n");
    scanf("%d", &s);

    int visited[v];
    for(int i = 0; i < v; ++i) {
        visited[i] = 0;
    }

    printf("\nDFS Traversal: ");
    dfs(v, adj, s, visited);

    return 0;
}

