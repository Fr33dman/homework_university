#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    srand((unsigned int)(time(0)));
    setlocale(LC_ALL, "Russian");
    const int N = 20;
    int a[N], max = 0, numminus = 0;
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 100 - 50;
        cout << a[i] << "\ ";
    }
    for (int i = 0; i < N; i++) {
        if ((a[i] > 0) && (a[i] > max)) {
            max = a[i];
        }
        else if (a[i] < 0) {
            numminus++;
        }
    }
    cout << endl << "Самое большое положительное число: " << max << endl << "Колличество отрицательных чисел: " << numminus;
}

