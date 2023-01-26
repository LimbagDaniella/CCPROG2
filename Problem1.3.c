/**
Write a function int Minimum(int A[], int n) which will determine and return the smallest element in array A
**/
#include <stdio.h>
#define MAX 8

int Minimum(int A[], int n)
{
	int i, num = A[0];
	for (i=0;i<n;i++)
	{
		if (A[i]<=num)
			num = A[i];
	}
	return num;
}

int main()
{
	int A[MAX] = {10, 23, 31, 43, 55, 9, 70, 88};
	printf("%d", Minimum(A, MAX));
	return 0;
}
