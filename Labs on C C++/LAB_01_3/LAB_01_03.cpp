#include <stdio.h>
#include <locale.h>
#include <math.h>
int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b, start, end, i, e, summ, per;
    int right, access = 1;
    while (access == 1)
    {
        printf("¬ведите два числа A и B через пробел:");
        right = scanf_s("%d %d", &a, &b);
        int c;
        do {
            c = getchar();
        } while (c != '\n' && c != EOF);
        fflush(stdin);
        if (right == 2)
        {
            if (a > b)
            {
                per = a;
                a = b;
                b = per;
            }
            i = a % 7;
            e = b % 7;
            if (i == 3)
            {
                start = a;
            }
            else if (i < 3)
            {
                start = a + 3 - i;
            }
            else
            {
                start = a - 3 + i;
            }
            if (e == 3)
            {
                end = b;
            }
            else if (e < 3)
            {
                end = b - 3 + e;
            }
            else
            {
                end = b + 3 - e;
            }
            summ = ((end + start) * ((end - start) / 7 + 1))/2;
            printf("—умма равна = %d", summ);
            access = 0;
        }
        else
        {
            printf("\n¬ведите правильно числа:\n");
        }
    }
    return 0;
}