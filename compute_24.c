#include <stdio.h>
#include <stdlib.h>
#define N 3

int** permute(int* nums, int numsSize, int* returnSize);
int factorial(int);
void zeros(int, int*);

int main()
{
    int numbers[N];
    /*int* numbers;*/
    int n, fn;
    n = N;
    int i, j;
    for (i = 0; i < n; i++)
    {
        numbers[i] = i + 1;
        /*printf("%d ", numbers[i]);*/
    }
    printf("\n");

    int** array_2d;
    array_2d = permute(numbers, n, &fn);
    /*printf("%d %d\n%d %d\n", array_2d[0][0], array_2d[0][1], array_2d[1][0], array_2d[1][1]);*/
    for (i = 0; i < fn; i++)
    {
        for (j = 0; j < n; j++)
            printf("%-5d", array_2d[i][j]);
            /*printf("array_2d[%d][%d] = %d\n", i, j, array_2d[i][j]);*/
        printf("\n");
    }

    return 0;
}

int** permute(int* nums, int numsSize, int* returnSize)
{
    int **pnums;
    *returnSize = factorial(numsSize);
    pnums = malloc(*returnSize * sizeof(int*));
    if (numsSize == 0 || numsSize == 1)
    {
        pnums[0] = malloc(numsSize * sizeof(int));
        if (numsSize == 1)
            pnums[0][0] = nums[0];
        return pnums;
    }
    for (int i = 0; i < numsSize; i++)
    {
        int **snums, subSize, *tnums = malloc((numsSize - 1) * sizeof(int));
        for (int j = 0, m = 0; j < numsSize; j++)
            if (j != i)
                tnums[m++] = nums[j];
        snums = permute(tnums, numsSize - 1, &subSize);
        free(tnums);
        for (int j = 0; j < subSize; j++)
        {
            pnums[i * subSize + j] = malloc(numsSize * sizeof(int));
            pnums[i * subSize + j][0] = nums[i];
            for (int k = 0; k < numsSize - 1; k++)
                pnums[i * subSize + j][k + 1] = snums[j][k];
            free(snums[j]);
        }
        free(snums);
    }
    return pnums;
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    return factorial(n - 1) * n;
}

void zeros(int n, int* array)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = 0;
    }
}
