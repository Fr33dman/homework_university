#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int a = 1, b = 1, right;
    float num1, num2, answer;
    char oper;
    printf("Вводите операцию в формате ЧИСЛОзнакЧИСЛО (без пробелов)\nДробные числа пишите через запятую\nДоступные операции:\n+ (сложение)\n- (вычитание)\n* (умножение)\n/ (деление)\n\n");
    while (a == 1)
    {
        printf("Введите операцию: ");
        right = scanf_s("%f%c%f", &num1, &oper, 1, &num2);
        int c;
        do {
            c = getchar();
        } while (c != '\n' && c != EOF);
        fflush(stdin);
        if (right == 3)
        {
            switch (oper)
            {
            case '+':
                answer = num1 + num2;
                printf("\nОтвет: %g\n", answer);
                break;
            case '-':
                answer = num1 - num2;
                printf("\nОтвет: %g\n", answer);
                break;
            case '*':
                answer = num1 * num2;
                printf("\nОтвет: %g\n", answer);
                break;
            case '/':
                if (num2 == 0)
                {
                    printf("\nНа ноль делить нельзя!\nВы ввели неправильно, введите заново!\n");
                }    
                else
                {
                    answer = num1 / num2;
                    printf("\nОтвет: %g\n", answer);
                }
                break;
            case '.':
                printf("\nПожалуйста, пишите дробные числа через запятую\n");
                break;
            default:
                printf("\nВы ввели неправильно, введите заново!\n");
                break;
            }
        }
        else
        {
            printf("\nВы ввели неправильно, введите заново!\n");
        }
    }
    return 0;
}