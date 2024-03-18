#include<stdio.h>
#include<stdlib.h>
int maxfind(int arr[],int low,int high)
{
	int mid=low+(high-low)/2;
	if(low==high)
		return arr[low];
	if(low==high-1)
		return arr[low]>arr[high]?arr[low]:arr[high];
	int max1=maxfind(arr,low,mid);
	int max2=maxfind(arr,mid+1,high);
	return max1>max2?max1:max2;
}
int minfind(int arr[],int low,int high)
{
	int mid=low+(high-low)/2;
	if(low==high)
		return arr[low];
	if(low==high-1)
		return arr[low]<arr[high]?arr[low]:arr[high];
	int min1=minfind(arr,low,mid);
	int min2=minfind(arr,mid+1,high);
	return min1<min2?min1:min2;
}
void main()
{
	int n;
	printf("Enter size of array : ");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter value : ");
		scanf("%d",&arr[i]);
	}
	printf("\nArray is : \n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	int max=maxfind(arr,0,n-1);
	printf("\nMaximum value is : %d\n",max);
	int min=minfind(arr,0,n-1);
	printf("Minimum value is  : %d\n",min);
}
