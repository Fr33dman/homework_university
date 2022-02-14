#include <iostream>
#include <stdio.h>
#include <time.h>
#include <clocale>
using namespace std;

int average(int a[], size_t m, size_t n, int unsigned l)
{
    int sum = 0;
    if (l - 1 < n / 2)
    {
        for (size_t i = 0; i < m / 2; i++)
        {
            sum += a[i * n + l - 1];
        }
        return sum;
    }
    else if (l - 1 >= n / 2)
    {
        for (size_t i = (int)(m / 2); i < m; i++)
        {
            sum += a[i * n + l - 1];
        }
        return sum;
    }
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    const int N1 = 10;
    const int N2 = 10;
    int arr[N1][N2];

    for (int i = 0; i < N1; i++)
    {
        for (int j = 0; j < N2; j++)
        {
            arr[i][j] = rand() % 10;
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    int arr1[N1 * N2];

    for (int i = 0; i < N1; i++)
    {
        for (int j = 0; j < N2; j++)
        {
            arr1[i * N2 + j] = arr[i][j];
            cout << arr1[i * N2 + j] << " ";
        }
    }
    cout << "\n\n";
    cout << "\n\nСумма: " << average(arr1, N1, N2, 10)<< "\n\n";
}