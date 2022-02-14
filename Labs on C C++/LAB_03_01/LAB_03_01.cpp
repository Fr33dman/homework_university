#include <iostream>
#include <stdio.h>
#include <time.h>
#include <clocale>
using namespace std;
int index_zero(int arr[])
{
    int size = sizeof(arr);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
            return i;
    }
    return -1;
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    const int N1 = 10;
    const int N2 = 10;
    int arr1[N1];
    int arr2[N2];

    for (int i = 0; i < N1; i++)
    {
        arr1[i] = rand() % 5;
        cout << arr1[i] << " ";
    }
    cout << "\n\n";
    for (int i = 0; i < N2; i++)
    {
        arr2[i] = rand() % 5;
        cout << arr2[i] << " ";
    }
    cout << "\n\n";

    int index1 = index_zero(arr1);
    int index2 = index_zero(arr2);

    int sum1_left = 0, sum1_right = 0, sum2_left = 0, sum2_right = 0;

    for (int i = 0; i < index1; i++)
    {
        sum1_left += arr1[i];
    }
    for (int i = index1; i < N1; i++)
    {
        sum1_right += arr1[i];
    }

    for (int i = 0; i < index2; i++)
    {
        sum2_left += arr2[i];
    }
    for (int i = index2; i < N2; i++)
    {
        sum2_right += arr2[i];
    }
    cout << "Сумма левой части для 1 массива: " << sum1_left << "\nСумма правой части для 1 массива: " << sum1_right << "\n\n";
    cout << "Сумма левой части для 2 массива: " << sum2_left << "\nСумма правой части для 2 массива: " << sum2_right << "\n\n";

}