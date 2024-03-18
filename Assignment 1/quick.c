#include<stdio.h>
#include<stdlib.h>
void quicksort(int arr[],int low,int high)
{
	int pivot,i,j;
	if(low<high)
	{
		pivot=low;
		i=low;
		j=high;
		while(i<j)
		{
			while(i<=high && arr[i]<arr[pivot])
			{
				i++;
			}
			while(j>=low && arr[j]>arr[pivot])
			{
				j--;
			}
			if(i<j)
			{
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		int temp=arr[j];
		arr[j]=arr[pivot];
		arr[pivot]=temp;
		quicksort(arr,low,j-1);
		quicksort(arr,j+1,high);
	}
}
void main()
{
	int n;
	printf("Enter size of array : ");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter element : ");
		scanf("%d",&arr[i]);
	}
	printf("Original array is :\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	quicksort(arr,0,n-1);
	printf("\nSorted array is : ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
