//implement the bubble sort to sort any array of elements.

#include<stdio.h>
int main()
{
int i,j,temp,n;
printf("Enter the number of elements:");
scanf("%d",&n);
int arr[n];
for(i=0;i<n;i++)
{
printf("Enter the array of elements a[%d]=",i);
	scanf("%d",&arr[i]);
}
for(i=0;i<n-1;i++)
{
	for(j=0;j<n-1-i;j++)
	{
	    
		if(arr[j]>arr[j+1])
	    {
		temp = arr[j+1];
		arr[j+1] = arr[j];
		arr[j] = temp;
	    }
	}
}

printf("The sorted array is=");
for(i=0;i<n;i++)
{
    printf("%d\t",arr[i]);
}
}


