#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

struct Student {
    char famil[30];
    char name[30];
    char facult[30];
    int Nomzach;
};

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("ПРОГРАММА 1\n");
    {
        int maxum = -10 * 100;
        int minum = 10 * 100;
        int n = 10, i = 0;
        int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        while (i < n) {
            if (a[i] > maxum)
                maxum = a[i];
            if (a[i] < minum)
                minum = a[i];
            i++;
        }
        printf("max=%d min=%d diff=%d\n\n", maxum, minum, maxum - minum);
    }

    printf("ПРОГРАММА 2\n");
    {
        int a[10];
        int n = 10;

        srand((unsigned int)time(NULL));

        for (int i = 0; i < n; i++) {
            a[i] = rand() % 100;
            printf("a[%d] = %d\n", i, a[i]);
        }
        printf("\n");
    }

    printf("ПРОГРАММА 3\n");
    {
        int n;
        int* a;

        printf("Введите размер массива: ");
        scanf_s("%d", &n);

        if (n <= 0) {
            printf("Массив должен быть положительным\n\n");
        }
        else {
            a = (int*)malloc(n * sizeof(int));

            if (a == NULL) {
                printf("Недостаточно памяти\n\n");
            }
            else {
                printf("Введите %d элементов массива\n", n);
                for (int i = 0; i < n; i++) {
                    printf("a[%d] = ", i);
                    scanf_s("%d", &a[i]);
                }

                printf("Введённый массив: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", a[i]);
                }
                printf("\n\n");

                free(a);
            }
        }
    }

    printf("ПРОГРАММА 4\n");
    {
        int rows = 3, cols = 4;
        int a[3][4] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        };

        printf("Двумерный массив %dx%d:\n", rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%4d ", a[i][j]);
            }
            printf("\n");
        }

        printf("\nСумма по столбцам:\n");
        for (int j = 0; j < cols; j++) {
            int sum = 0;
            for (int i = 0; i < rows; i++) {
                sum += a[i][j];
            }
            printf("Столбец %d: %d\n", j + 1, sum);
        }
        printf("\n");
    }

    printf("ПРОГРАММА 5\n");
    {
        struct Student stud[3];
        char search[30];
        int found = 0;

        printf("ВВОД ДАННЫХ СТУДЕНТОВ\n");

        for (int i = 0; i < 3; i++)
        {
            printf("\nСтудент %d:\n", i + 1);
            printf("Введите фамилию: ");
            scanf("%29s", stud[i].famil);
            printf("Введите имя: ");
            scanf("%29s", stud[i].name);
            printf("Введите факультет: ");
            scanf("%29s", stud[i].facult);
            printf("Введите номер зачётной книжки: ");
            scanf("%d", &stud[i].Nomzach);
        }

        printf("\nВведите фамилию для поиска: ");
        scanf("%29s", search);

        printf("\nРЕЗУЛЬТАТЫ ПОИСКА\n");
        for (int i = 0; i < 3; i++)
        {
            if (strcmp(stud[i].famil, search) == 0)
            {
                printf("\nНайден студент:\n");
                printf("Фамилия: %s\n", stud[i].famil);
                printf("Имя: %s\n", stud[i].name);
                printf("Факультет: %s\n", stud[i].facult);
                printf("Номер зачётной книжки: %d\n", stud[i].Nomzach);
                found = 1;
            }
        }

        if (!found)
        {
            printf("Студент с фамилией '%s' не найден.\n", search);
        }
        printf("\n");
    }

    return 0;
}