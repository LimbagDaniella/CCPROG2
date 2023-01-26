/**
Write a function int Maximum(int A[], int n) which will determine and return the largest element in array A
**/

#include <stdio.h>
#define MAX 8

int Maximum(int A[], int n)
{
	int i, num = A[0];
	for (i=0;i<n;i++)
	{
		if (A[i]>=num)
			num = A[i];
	}
	return num;
}

int main()
{
	int A[MAX] = {10, 23, 91, 43, 55, 97, 70, 88};
	printf("%d", Maximum(A, MAX));
	return 0;
}
