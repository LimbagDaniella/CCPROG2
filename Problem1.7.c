/**
Write a function int CountUpper(char S[], int n) which will count the number of upper case letters in array S.
For example, assume an array S defined as follows: char S[7] = {'C', 'o', 'M', 'p', 'r', 'o', '2'};
A call to CountUpperCase(S, 7) will return 2 since there are two upper case letters, namely, 'C' and 'M'
**/

#include <stdio.h>

int CountUpper(char S[], int n)
{
	int i, num = 0;
	for (i=0;i<n;i++)
	{
		if (S[i] >= 65 && S[i] <= 90)
			num++;
	}
	return num;
}

int main()
{
	char S[7] = {'C', 'o', 'M', 'p', 'r', 'o', '2'};
	printf("%d", CountUpper(S, 7));
	
	return 0;
}
