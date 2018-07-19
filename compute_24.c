#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define N 4
#define true 1
#define false 0

typedef int bool;

int factorial(int n);
int** permute(int* nums, int numsSize, int* returnSize);
void printPnums(int** pnums, int rowSize, int colSize);
double binaryOperation(double num1, double num2, char operation);
char* brutalForceCompute(int *nums, int numsSize, char operations[], int operationsSize, int *returnSize);

int main(int argc, char* argv[])
{
    int nums[N] = {0, 0, 0, 1}, numsSize = N, **pnums, pnumsSize, operationsSize = 4, resSize;
    char operations[] = "+-*/", *resOperations;

    while (nums[0] + nums[1] + nums[2] + nums[3])
    {
        scanf("%d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3]);
        resOperations = brutalForceCompute(nums, numsSize, operations, operationsSize, &resSize);
        if (resSize == 3)
            printf("%2d %2d %2d %2d: ((%d %c %d) %c %d) %c %d\n", nums[0], nums[1], nums[2], nums[3], nums[0], resOperations[0], nums[1], resOperations[1], nums[2], resOperations[2], nums[3]);
    }

    // read from command line
    // for (int i = 1; i < argc; i++)
        // nums[i-1] = atoi(argv[i]);

    // pnums = permute(nums, numsSize, &pnumsSize);
    // printPnums(pnums, pnumsSize, numsSize);
    return 0;
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    return factorial(n - 1) * n;
}

// Permute using recursion
int** permute(int* nums, int numsSize, int* returnSize)
{
    int **pnums;
    *returnSize = factorial(numsSize);
    pnums = malloc(*returnSize * sizeof(int*));

    // Base case
    if (numsSize == 0 || numsSize == 1)
    {
        pnums[0] = malloc(numsSize * sizeof(int));
        if (numsSize == 1)
            pnums[0][0] = nums[0];
        return pnums;
    }

    // When numsSize >= 2
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

void printPnums(int **pnums, int rowSize, int colSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
            printf("%-5d", pnums[i][j]);
        printf("\n");
    }
}

char* brutalForceCompute(int *nums, int numsSize, char operations[], int operationsSize, int *returnSize)
{
    int res = nums[0];
    char *foundOperations;
    *returnSize = 0;
    foundOperations = malloc((*returnSize + 1)* sizeof(char));
    foundOperations[*returnSize] = '\0';
    if (numsSize != 4)
        return foundOperations;

    for (int i = 0; i < operationsSize; i++)
    {
        double tmp1 = binaryOperation(nums[0], nums[1], operations[i]);
        for (int j = 0; j < operationsSize; j++)
        {
            double tmp2 = binaryOperation(tmp1, nums[2], operations[j]);
            for (int k = 0; k < operationsSize; k++)
            {
                if (binaryOperation(tmp2, nums[3], operations[k]) - 24 == 0)
                {
                    *returnSize = 3;
                    foundOperations = realloc(foundOperations, (*returnSize + 1)* sizeof(char));
                    foundOperations[*returnSize] = '\0';
                    foundOperations[0] = operations[i];
                    foundOperations[1] = operations[j];
                    foundOperations[2] = operations[k];
                }
            }
        }
    }

    return foundOperations;
}

double binaryOperation(double num1, double num2, char operation)
{
    switch (operation)
    {
        case '+':
            return num1 + num2; break;
        case '-':
            return num1 - num2; break;
        case '*':
            return num1 * num2; break;
        case '/':
            if (num2 == 0)
                return INT_MIN;
            else
                return num1 / num2;
            break;
        default:
            return -1;
    }
}
