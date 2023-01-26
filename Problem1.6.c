/**
Write a function foat Average(int A[], int n) which will determine and return the average of the elements in array A
**/

#include <stdio.h>
#define MAX 8

float Average(int A[], int n)
{
	int i;
	float num;
	for (i=0;i<n;i++)
	{
		num += A[i];
	}
	return num / n;
}

int main()
{
	int A[MAX] = {10, 23, 91, 43, 55, 97, 70, 88};
	printf("%.2f", Average(A, MAX));
	return 0;
}
