#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int* findmm(int** arr, int size)
{
	int max = arr[0][0];
	int min = arr[0][0];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] > max)
				max = arr[i][j];
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] < min)
				min = arr[i][j];
		}
	}
	int* mm = new int[2];
	mm[0] = max;
	mm[1] = min;
	return mm;
}

int main()
{
	srand(time(0));
	int N;
	printf("Insert matrix rank: ");
	scanf("%d", &N);
	int** array = new int* [N];
	for (int i = 0; i < N; i++)
	{
		array[i] = new int[N];
		for (int j = 0; j < N; j++)
			array[i][j] = rand() % 199 - 99;
	}
	int* maxmin = new int[2];
	maxmin = findmm(array, N);
	printf("\n Max is %d\n Min is %d", maxmin[0], maxmin[1]);
	for (int i = 0; i < N; i++)
		delete[] array[i];
	delete[] array, maxmin;
}