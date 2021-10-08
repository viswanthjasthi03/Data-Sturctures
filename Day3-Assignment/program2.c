//Write a program for the unsorted aray to sorted array using Selection sort.

#include<stdio.h>
int main()
{
int min;
int i,j,temp;
int arr[10] = {1,3,4,7,8,6,2,9,0,5};
for(i=0;i<10;i++)
	{
		min = i;
		for(j=i+1;j<10;j++)
		{
			if(arr[j]<arr[min])          // Checking the arr[j] is lessthan the arr[min]//
		{
			min = j;
		}
		}

		if(min!=i)    //Swapping of elements//
		{
			temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
printf("\nSorted array:\n");	
for(i=0;i<10;i++)
{
	printf("%d",arr[i]);
}
}

