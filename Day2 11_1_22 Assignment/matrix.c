#include <stdio.h>
#include <stdlib.h>
int main()
{
    int r1, c1, r2, c2, i, j, k;
    int **arr1, **arr2, **arr3;
    printf("\nEnter the size of first matrix(Row and column) and second matrix : ");
    scanf("%d %d %d %d", &r1, &c1,&r2, &c2);
    if (c1 != r2)
    {
        printf("column size of first matrix must match with the row size of second matrix");
        exit(1);
    }

    arr1 = (int **)malloc(r1 * sizeof(int *));
    printf("\nEnter First array element\n");
    for (i = 0; i < r1; i++)
    {
        arr1[i] = (int *)malloc(c1 * sizeof(int));
        for (j = 0; j < c1; j++)
            scanf("%d", &arr1[i][j]);
    }
    arr2 = (int **)malloc(r2 * sizeof(int *));
    printf("\nEnter Second array element\n");
    for (i = 0; i < r2; i++)
    {
        arr2[i] = (int *)malloc(c1 * sizeof(int));
        for (j = 0; j < c2; j++)
            scanf("%d", &arr2[i][j]);
    }

    arr3 = (int **)malloc(r1 * sizeof(int *));
    for (i = 0; i < r1; i++)
    {
        arr3[i] = (int *)malloc(c2 * sizeof(int));
        for (j = 0; j < c1; j++)
        {
            for (k = 0; k < c2; k++)
            {
                arr3[i][k] += (arr1[i][j]) * (arr2[j][k]);
            }
        }
    }
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf(" %d ", arr3[i][j]);
        }
    }
    return 0;
}