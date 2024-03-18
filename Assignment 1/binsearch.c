#include<stdio.h>
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
	printf("Array is : \n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("\nSorted Array is : \n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	int key,flag=0,pos;
	printf("\nEnter value to be searched : ");
	scanf("%d",&key);
	int l=0,u=n-1,mid;
	while(l<=u)
	{
		mid=(l+u)/2;
		if(arr[mid]==key)
		{
			flag=1;
			pos=mid+1;
			break;
		}
		else if(arr[mid]>key)
			u=mid-1;
		else
			l=mid+1;
	}
	if(flag==0)
		printf("Element not found\n");
	else
		printf("Element found at position : %d\n",pos);	
}
