#include<stdio.h>
#include<stdlib.h>
void merge(float arr[],int item[],int low,int mid,int high)
{
	int i,j,t,k;
	i=t=low;
	j=mid+1;
	float temp[high+1];
	int ind[high+1];
	while(i<=mid && j<=high)
	{
		if(arr[i]>=arr[j])
		{
			temp[t]=arr[i];
			ind[t++]=item[i++];
		}
		else
		{
			temp[t]=arr[j];
			ind[t++]=item[j++];
		}
	}
	while(i<=mid)
	{
		temp[t]=arr[i];
		ind[t++]=item[i++];
	}
	while(j<=high)
	{
		temp[t]=arr[j];
		ind[t++]=item[j++];
	}
	for(k=low;k<=high;k++)
	{
		arr[k]=temp[k];
		item[k]=ind[k];
	}
}
void mergesort(float arr[],int item[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(arr,item,low,mid);
		mergesort(arr,item,mid+1,high);
		merge(arr,item,low,mid,high);
	}
}
float knapsack(int item[],float val[],float wt[],int n,float w)
{
	int i,index;
	float profit,t;
	for(int i=0;i<n;i++)
	{
		index=item[i]-1;
        if(wt[index] <= w)
        {
            profit += val[index];
            w-= wt[index];
        }
        else
        {
            t = w/wt[index];
            profit+=(t*val[index]);
            w-=(t*wt[index]);
        }
	}
	return profit;
}
float knapsack_frac(int a[], int b[], int n, int c)
{
	int i,item[n];
    float val[n],wt[n], w = c;
    float fraction[n],temp[n];
    for(i=0; i<n; i++){
        item[i] = i+1;
        val[i] = a[i];
        wt[i] = b[i];
    }
    for(i=0; i<n; i++){
        fraction[i] = val[i] / wt[i];
        temp[i] = fraction[i];
    }
    mergesort(fraction,item,0,n-1);
    return knapsack(item, val, wt, n, w);
}
int max(int a,int b)
{
	return a>b?a:b;
}
int knapsack_01(int n,int w,int val[],int wt[])
{
	int dp[n+1][w+1];
	for(int i=0;i<=w;i++)
		dp[0][i]=0;
	for(int i=1;i<=n;i++)
		dp[i][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(j<wt[i-1])
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
		}
	}
	return dp[n][w];
}
void main()
{
	int n,w;
	printf("Enter the number of items : ");
	scanf("%d",&n);
	printf("Enter the total weight : ");
	scanf("%d",&w);
	int val[n],wt[n];
	printf("Enter weight of each item : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("Enter value of each item : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&val[i]);
	}
	printf("Profit for 0/1 Knapsack : %d\n",knapsack_01(n,w,val,wt));
	printf("Profit for Fractional knapsack : %0.2f\n",knapsack_frac(val,wt,n,w));
}
