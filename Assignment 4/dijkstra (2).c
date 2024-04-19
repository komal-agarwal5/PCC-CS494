#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void dj (int g[5][5], int a[5])
{
	int s[5];
	s[0]=1;
	int cnt=0;
	 int vis[5]={0,-1,-1,-1,-1};
	for(int i=0;i<5;i++)
	{
		s[i]=cnt;
		vis[cnt]=0;
		for(int j=0;j<5;j++)
		{
			if(g[cnt][j]!=INT_MAX && a[cnt]+g [cnt][j]<a[j])
			{
				a[j]=a[cnt]+g[cnt][j];
			}
		}		
		int min=INT_MAX;
		for(int k=0;k<5;k++)
		{
			if(a[k]<min&&vis[k]==-1)
			{
				min=a[k];
				cnt=k;
			}
		}
	}
	printf("The shortest path is \n");
	for(int i=0;i<5;i++)
		printf("%d ",s[i]+1);
	printf("\n");
}

int main()
{
int g[][5]={{0,5,2,10,6}, 
			{5,0,13,4,INT_MAX}, 
			{2,13,0,9,3}, 
			{10,4,9,0,4}, 
			{6, INT_MAX,3,4,0}};

int a[5]={0,INT_MAX, INT_MAX, INT_MAX, INT_MAX}; 
dj(g,a);
return 0;
}

