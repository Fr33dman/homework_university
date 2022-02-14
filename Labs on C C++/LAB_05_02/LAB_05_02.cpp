
#include <iostream>
#include <clocale>
#include <stdio.h>
#include <iomanip>
#include <time.h>

using namespace std;

int** memory(int** matrix, int n, int m)
{
	matrix = new int*[n];

	for (int i = 0; i < n; i++)

		matrix[i] = new int[m];

	return matrix;

}

void initialize(int** matrix, int n, int m)
{

	for (int i = 0; i < n; i++)

		for (int j = 0; j < m; j++)

			matrix[i][j] = rand() % 10 - 5;

}

void draw(int** matrix, int n, int m)
{

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++)

			cout << setw(3) << matrix[i][j];

		cout << endl;

	}

}

int* findMin(int** matrix, int n, int m)
{

	cout << endl;

	int* min = new int[n];

	for (int i = 0; i <= n / 2; i++) {

		min[i] = matrix[i][i];

		for (int j = i; j < m - i; j++)

			if (min[i] > matrix[i][j])

				min[i] = matrix[i][j];

	}

	for (int i = n - 1; i > (n - 1) / 2; i--) {

		min[i] = matrix[i][i];

		for (int j = n - i; j < i; j++)

			if (min[i] > matrix[i][j])

				min[i] = matrix[i][j];

	}

	return min;
}

void answer(int* min, int n)
{

	cout << endl;

	for (int i = 0; i < n; i++)

		cout << "строка " << i << ": " << min[i] << endl;

}

int main()
{

	srand(time(0));
	setlocale(LC_ALL, "Russian");

	int n, m;
	cout << " n = "; 
	cin >> n;
	cout << " m = "; 
	cin >> m;
	cout << endl;

	int** matrix = 0;

	matrix = memory(matrix, n, m);
	initialize(matrix, n, m);
	draw(matrix, n, m);

	int* min = new int[n];
	min = findMin(matrix, n, m);

	answer(min, n);

	return 0;
}