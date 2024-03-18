#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void heapify(int arr[],int i,int n)
{
	int max=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && arr[left]>arr[max])
	{
		max=left;
	}
	if(right<n && arr[right]>arr[max])
	{
		max=right;
	}
	if(max!=i)
	{
		swap(&arr[i],&arr[max]);
		heapify(arr,max,n);
	}
}
void heapsort(int arr[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		heapify(arr,i,n);
	}
	for(int i=n-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);
		heapify(arr,0,i);
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
	display(arr,n);
	heapsort(arr,n);
	printf("Sorted array is :\n");
	display(arr,n);
}
