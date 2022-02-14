#include <iostream>
#include <stdio.h>
#include <time.h>
#include <clocale>
using namespace std;

int nules(int arr[10][10])
{
	int n = 0;
	for (int i = 0; i < 10 / 2; i++)
	{
		for (int j = i; j < 10 - i; j++)
		{
			if (arr[i][j] == 0)
			{
				n++;
			}
		}
	}
	for (int i = 10/2; i < 10; i++)
	{
		for (int j = 10 - i; j < i; j++)
		{
			if (arr[i][j] == 0)
			{
				n++;
			}
		}
	}
	return n;
}

void rand_array(int arr[10][10])
{
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			arr[i][j] = rand() % 10 - rand() % 10;
			if (arr[i][j] < 0)
			{
				cout << arr[i][j] << "  ";
			}
			else
			{
				cout << " "<< arr[i][j] << "  ";
			}
		}
		cout << "\n";
	}
	cout << "\n\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int arr[10][10];
	rand_array(arr);
	cout << "Nules quanity: " << nules(arr);
}