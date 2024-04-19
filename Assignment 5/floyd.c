#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 5
void printpath(int src,int dest,int v,int pred[MAX][MAX])
{
	if(src==dest)
	{
		printf("%d",src);
		return;
	}
	if(pred[src][dest]==-1)
	{
		printf("No path from source to destination");
		return;
	}
	printpath(src,pred[src][dest],v,pred);
	printf("->%d",dest);
}
void printdistance(int a[MAX][MAX],int v)
{
	int i,j;
	printf("The distance matrix is :\n");
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(a[i][j]==99999)
				printf("INF");
			else
				printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
void find(int a[MAX][MAX],int v)
{
	int pred[v][v];
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			pred[i][j]=i==j?-1:i;
		}
	}
	for(int k=0;k<v;k++)
	{
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				if(a[i][k]+a[k][j]<a[i][j])
				{
					a[i][j]=a[i][k]+a[k][j];
					pred[i][j]=pred[k][j];
				}
			}
		}
	}	
	printdistance(a,v);
	printf("The shortest path is : \nSource\tDest\tPath\n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(i!=j)
			{
				printf("%d\t%d\t",i,j);
				printpath(i,j,v,pred);
				printf("\n");
			}
		}
	}
}
void main()
{
	int v;
	printf("Enter number of vertices : ");
	scanf("%d",&v);
	printf("Enter adjacency matrix : \n");
	int a[v][v];
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	find(a,v);
}
