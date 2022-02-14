#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;


int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    const int N = 10;
    int J = 10, K = 0, numzeros = 0, minimum = 0, unsignednum = 0;
    int a[N][N], min[N];
    // Задаем массив
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = rand() % 10 - rand() % 10;
            if (a[i][j] < 0) {
                cout << a[i][j] << '\ ';
            }
            else {
                cout << '\ '<< a[i][j] << '\ ';
            }
        }
        cout << '\n';
    }
    // Делаем поиск по областям
    for (int i = 0; i < N; i++) {
        if (i > (int)(N / 2) - 1) {
        K--;
        J++;
        }
        cout << K << '\t' << J << '\n';
        for (int j = K; j < J; j++) {
            // Ищем нули
            if (i <= N / 2) {
                if (a[i][j] == 0) {
                    numzeros++;
                }
            }
            // Ищем положительные
            else if (i > N / 2) {
                if (a[i][j] > 0) {
                    unsignednum++;
                }
            }
        }
        // Отсекаем области поиска в алгоритме
        if (i <= (int)(N / 2)-1) {
            K++;
            J--;
        }
    }
    // Ищем минимум
    for (int j = 0; j < N; j++) {
        minimum = (a[0][j] > 0) ? a[0][j] : (-1)*a[0][j];
        for (int i = 0; i < N; i++) {
            if (((a[i][j] > 0) ? a[i][j] : (-1) * a[i][j]) < minimum) {
                minimum = (a[i][j] > 0) ? a[i][j] : (-1) * a[i][j];
            }
        }
        min[j] = minimum;
    }
    cout << "\n\n" <<"Колличество нулей в верхней части: " << numzeros << "\n\n";
    cout << "Колличество положительных элементов в нижней части: " << unsignednum << "\n\n";
    cout << "Массив минимумов в каждом столбце: ";
    for (int i = 0; i < N; i++) {
        cout << min[i] << '\ ';
    }
    cout << "\n\n\n";
    return 0;
}