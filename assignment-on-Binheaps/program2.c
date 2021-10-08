//Write program to convert maxheap to minheap

#include<stdio.h>
void MaxHeapify(int arr[], int i, int n)
{
    int temp;
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest = i;
	if (l < n && arr[l] > arr[i])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		MaxHeapify(arr, largest, n);
	}
}
void convertMaxHeap(int arr[], int n)
{
	
	for (int i = (n-2)/2; i >= 0; --i)
		MaxHeapify(arr, i, n);
}

int main()
{
	
	int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i;
	printf("Min Heap array : ");
	for(i=0;i<n;i++)
	{
	printf("%d\t",arr[i]);
	}

	convertMaxHeap(arr, n);

	printf("\nMax Heap array : ");
	for(i=0;i<n;i++)
	{
	printf("%d\t",arr[i]);
	}
	return 0;
}








