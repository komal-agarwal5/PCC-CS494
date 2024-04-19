#include<stdio.h>
#include<limits.h>
#define MAX 100
void bellFord(int graph[MAX][3],int edges,int vertex,int dist[],int src)
{
	dist[src]=0;
	int i,j;
	for(i=1;i<vertex;i++)
	{
		int u,v,wt;
		for(j=0;j<edges;j++)
		{
			u=graph[j][0];
			v=graph[j][1];
			wt=graph[j][2];
			if(dist[u]!=INT_MAX && (dist[u]+wt<dist[v]))
				dist[v]=dist[u]+wt;
		}
	}
}
void print(int dist[],int src,int vertex)
{
	printf("The shortest distances from source %d are \n",src);
	printf("Vertex\tDistance\n");
	for(int i=0;i<vertex;i++)
	{
		if(i==src)
			continue;
		printf("%d\t%d\n",i,dist[i]);
	}
}
void main()
{
	int vertex,edges,i,src,dest;
	printf("Enter number of verices : ");
	scanf("%d",&vertex);
	printf("Enter number of edges : ");
	scanf("%d",&edges);
	printf("Enter adjacency list : \n");
	int dist[vertex];
	int graph[edges][3];
	for(i=0;i<edges;i++)
	{
		printf("Enter source destination weight : ");
		scanf("%d %d %d",&graph[i][0],&graph[i][1],&graph[i][2]);
	}
	for(i=0;i<vertex;i++)
	{
		dist[i]=INT_MAX;
	}
	printf("Enter source vertex : ");
	scanf("%d",&src);
	bellFord(graph,edges,vertex,dist,src);
	print(dist,src,vertex);
}
