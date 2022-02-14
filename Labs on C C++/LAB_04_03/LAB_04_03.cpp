#include <iostream>
#include <stdio.h>
#include <time.h>
#include <clocale>
using namespace std;

int minimum(int **arr, size_t y, size_t x)
{
	int min = 9;
	for (int i = 0; i < y; i++)
	{
		if (min > *(*(arr + i) + x))
		{
				min = *(*(arr + i) + x);
		}
	}
	return min;
}

void rand_array(int** arr, size_t y, size_t x)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			*(*(arr + i) + j) = rand() % 10;
			cout << *(*(arr + i) + j) << "  ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

int main()
{
	const int N1 = 10;
	const int N2 = 10;
	int** arr = new int* [N1]; // выделяем массив из N1 указателей типа int — это наши строки
	for (int count = 0; count < N1; ++count)
	{
		arr[count] = new int[N2]; // а это наши столбцы
	}

	rand_array(arr, N1, N2);
	int min[N2];
	
	for (int j = 0; j < N2; j++)
	{
		min[j] = minimum(arr, N1, j);
	}

	cout << "\n\n";

	for (int j = 0; j < N2; j++)
	{
		cout << *(min + j) << "  ";
	}
}