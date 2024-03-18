#include<stdio.h>
#include<stdlib.h>
int find(int n,int k)
{
	int dp[n+1][k+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i && j<=k;j++)
		{
			if(j==0 || j==i)
				dp[i][j]=1;
			else
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
		}
	}
	return dp[n][k];
}
void main()
{
	int n,k;
	printf("Enter value of n : ");
	scanf("%d",&n);
	printf("Enter value of k : ");
	scanf("%d",&k);
	int ans=find(n,k);
	printf("Binomial coefficient B[%d,%d] is : %d\n",n,k,ans);
}
