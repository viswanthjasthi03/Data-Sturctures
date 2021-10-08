//Use insertion sorting for an unsorted array//


#include<stdio.h>
int main()
{
        int n; 
	int i,j,temp;
	printf("Enter the number of elements to be print:\n");
	scanf("%d",&n);// Number of index numbers // 
	int a[n];

	for(i=0;i<n;i++)
	{
	printf("Enter the elements a[%d]=",i);
		scanf("\n%d",&a[i]);
	}
	printf("\nUnsoted array is :");
	for(i=0;i<n;i++)
	{
		printf("\n%d",a[i]);
	}	
//Insertion sorting//
 
	for(i=1;i<n;i++)
	{
		temp = a[i];
		j=i-1;
		
		while(j>=0 && a[j]>temp)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
	printf("\nArray is Sorted by using the insertion sorting");
	
	for(i=0;i<n;i++)
	{
		printf("\na[%d] = %d",i,a[i]);
		
	}
	
}

