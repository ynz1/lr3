#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int main()
{
    int order, c, d, matrix[10][10], temp = 0, tempC = 0, tempD = 0, newmatrix[9][9], x =0 , y=0; // объявление массивов и переменных
    
    printf("vvedite poryadok matrici:\n");
    scanf_s("%d", &order); // ввод порядка матрицы
    printf("vvedite elementi matrici:\n");

    for (c = 0; c < 9; c++) // обнуление матрицы
        for (d = 0; d < 9; d++) {
            matrix[c][d] = 0;
            newmatrix[c][d] = 0;
        }

    for (c = 0; c < order; c++) // генерация матрицы и ввод элементов
        for (d = 0; d < order; d++)
            scanf_s("%d", &matrix[c][d]);

    printf("ishodnaya matrica:\n");

    for (c = 0; c < order; c++) { // вывод исходной матрицы
        for (d = 0; d < order; d++)
            printf("%d\t", matrix[c][d]);
        printf("\n");
    }

    for (c = 0; c < order; c++) // проверка и запись наибольшего по модулю элемента а также его расположение во временные элементы
        for (d = 0; d < order; d++)
            if (abs(matrix[c][d]) >= abs(temp))
            {
                temp = matrix[c][d];
                tempC = c;
                tempD = d;
            }

    for (c = 0; c < order; c++) // создание новой матрицы без строки и столбца с наибольшим по модулю элемента
        for (d = 0; d < order; d++) {
            if (c != tempC && d != tempD)
            {
                newmatrix[x][y] = matrix[c][d];
                if (y == order - 2) {
                    x++;
                    y = 0;
                }
                else
                    y++;
            }
        }

    printf("novaya matrica:\n");

    for (c = 0; c < order - 1; c++) { // вывод новой матрицы
        for (d = 0; d < order - 1; d++)
            printf("%d\t", newmatrix[c][d]);
        printf("\n");
    }
    return 0;
}