#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    int right, a, b, cc, access = 1;
    float answer;
    setlocale(LC_ALL, "Russian");
    printf("Введите три числа через пробелы\n");
    while (access == 1)
    {
        printf("Введите операцию: ");
        right = scanf_s("%d %d %d", &a, &b, &cc);
        int c;
        do {
            c = getchar();
        } while (c != '\n' && c != EOF);
        fflush(stdin);
        if (right == 3)
        {
            if (cc != 0)
            {
                answer = ((float)a / (float)cc) + (float)b;
                printf("Ответ: %g", answer);
                access = 0;
            }
            else
            {
                printf("На ноль делить нельзя! Введите заново.");
            }
        }
        else
        {
            printf("Введите в правильном формате пожалуйста.");
        }
    }
    return 0;
}