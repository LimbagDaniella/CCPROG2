/**
Write a function int Sum(int A[], int n) which will determine and return the sum of all the elements in array A
**/

#include <stdio.h>
#define MAX 8

int Sum(int A[], int n)
{
	int i, num;
	for (i=0;i<n;i++)
	{
		num += A[i];
	}
	return num;
}

int main()
{
	int A[MAX] = {10, 23, 91, 43, 55, 97, 70, 88};
	printf("%d", Sum(A, MAX));
	return 0;
}
