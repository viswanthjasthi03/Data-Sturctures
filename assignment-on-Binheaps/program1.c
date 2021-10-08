//Write a program to check input array is maxheap or not.


#include <stdio.h>
int checkMinHeap(int A[], int i, int n)
{
    if (2*i + 2 > n) {
        return 1;
    }
    int left = (A[i] <= A[2*i + 1]) && checkMinHeap(A, 2*i + 1, n);
    int right = (2*i + 2 == n) || (A[i] <= A[2*i + 2] && checkMinHeap(A, 2*i + 2, n));
    return left && right;
}
int main()
{
    int A[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(A) / sizeof(A[0]);
    int index = 0;
    if (checkMinHeap(A, index, n)) {
        printf("The given array is a min-heap\n");
    }
    else {
        printf("The given array is not a min-heap\n");
    }
 
    return 0;
}
