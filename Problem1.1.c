/**
Write a function int IsIncreasingOrder(int A[], int n) which will return 1 if A[i] < A[i+1] for i = 0 to n-2, otherwise it will return 0.
Assume that elements are unique, i.e, no two elements have the same value.
**/
#include <stdio.h>

#define MAX 8

int IsIncreasingOrder(int A[], int n)
{
	int i;
	for (i=0;i<n-2;i++)
	{
		if (A[i] > A[i+1])
			return 0;
	}
	return 1;
}

int main()
{
	int A[MAX] = {10, 23, 31, 43, 55, 69, 70, 88};
	printf("%d", IsIncreasingOrder(A, MAX));
	return 0;
}
