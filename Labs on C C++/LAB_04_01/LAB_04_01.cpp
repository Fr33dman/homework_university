#include <iostream>
#include <stdio.h>
#include <time.h>
#include <clocale>
using namespace std;

struct Tuple
{
	int* pointer;
	int index;
};

Tuple max(int *arr, size_t lenth)
{
	int m = 0;
	int n = NULL;
	size_t index = NULL;
	
	for (int i = 0; i < lenth; i++)
	{
		if (m < arr[i])
		{
			m = arr[i];
			n = *(arr + i);
			index = i;
		}
	}
	Tuple out;
	out.pointer = &n;
	out.index = index;
	return out;
}

int summ(int arr[], size_t index, size_t lenth)
{
	int s = 0;
	
	for (int i = index; i < lenth; i++)
	{
		s += arr[i];
	}
	
	return s;
}

void rand_array(int arr[], size_t lenth)
{	
	for (int i = 0; i < lenth; i++)
	{
		arr[i] = rand() % 10 - rand() % 10;
		cout << arr[i] << "  ";
	}
	cout << "\n\n";
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	const int N1 = 10;
	const int N2 = 10;
	int arr1[N1];
	rand_array(arr1, N1);
	int arr2[N2];
	rand_array(arr2, N2);
	int max1 = *max(arr1, N1).pointer;
	int index1 = max(arr1, N1).index;
	int max2 = *max(arr2, N2).pointer;
	int index2 = max(arr2, N2).index;
	int summ1 = summ(arr1, index1, N1);
	int summ2 = summ(arr2, index2, N2);
	cout << "\n\n" << "Array 1\nMax: " << max1 << "\nPointer: " << &max1 << "\nIndex: " << index1;
	cout << "\n\n" << "Array 2\nMax: " << max2 << "\nPointer: " << &max2 << "\nIndex: " << index2;;
	if (summ1 > summ2)
	{
		cout << "\n\n" << "Maximum summ in right part: " << summ1 << " from array 1\n\n";
	}
	else
	{
		cout << "\n\n" << "Maximum summ in right part: " << summ2 << " from array 2\n\n";
	}
}