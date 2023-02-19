//Do NOT modify the contents of this file

#include <stdio.h>
#define SIZE 9

int isInRange(int num)
{
	int nReturn = 0;
	
	if (num <= 9 && num >= 1)
		nReturn = 1;
		
	return nReturn;
}

void getInput(int aMatrix[][SIZE])
{
	int i, j;
	
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++){
			scanf("%d", &aMatrix[i][j]);
		}
	}
}

void displayRow(int aRow[])
{
	int i;
	
	for(i=0;i<SIZE;i++)
	{
		if((i>0) && (i%3==0))
			printf("\t");
		printf("%d ", aRow[i]);
	}
}

void displayAll(int aMatrix[][SIZE])
{
	int i;
	
	for(i=0;i<SIZE;i++)
	{
		displayRow(aMatrix[i]);
		if(i>0 && (i+1)%3==0)
			printf("\n");
		printf("\n");
	}
}

int checkrow(int aData[])
{
	int i, j, valid = 1;
	int check[SIZE] = {0};
    for (i = 0; i < SIZE; i++) {
        if (aData[i] < 1 || aData[i] > 9) {
            valid = 0;
        }
        for(j=0;j<SIZE;j++) {
            valid = 0;
        }
        check[aData[i] - 1] = 1; 
    }
	return valid;
}

int checkcol(int aMatrix[][SIZE], int nColInd)
{
	int i, valid = 1;
	int nCheck[SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        if (aMatrix[i][nColInd] < 1 || aMatrix[i][nColInd] > 9) {
            valid = 0;
        }
        if (nCheck[aMatrix[i][nColInd] - 1] == 1) {
            valid = 0;
        }
        nCheck[aMatrix[i][nColInd] - 1] = 1;
    }
	return valid;
}

int checkbox(int aMatrix[][SIZE], int nRow, int nCol)
{
	int i, j, valid = 1;
	int nCheck[SIZE] = {0};
    for (int i = nRow; i < nRow + 3; i++) {
        for (int j = nCol; j < nCol + 3; j++) {
            if (aMatrix[i][j] < 1 || aMatrix[i][j] > 9) {
                valid = 0;
            }
            if (nCheck[aMatrix[i][j] - 1] == 1) {
                valid = 0;
            }
            nCheck[aMatrix[i][j] - 1] = 1;
        }
    }
    return valid;
}
