/**
 * compute_24.c
 * Using brutal force to make up 24 given four numbers.
 *
 * Author: Libao Jin
 * Email: jinlibao@outlook.com
 * Date: 07/19/2018
 * Copyright (c) 2018 Libao Jin
 * All rights reserved
 * License: MIT License
 * Version: v2.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

double binaryOperation(double num1, double num2, char operation);
char* brutalForceCompute(int *nums, int numsSize, char operations[], int operationsSize, int *returnSize);
int** permute(int* nums, int numsSize, int* returnSize);
int factorial(int n);

int main(int argc, char* argv[])
{
    int nums[4] = {0, 0, 0, 1}, numsSize = 4, interface = 2;

    if (argc > 1)
        interface = atoi(argv[1]);
    if (interface == 2)
        printf("Welcome to Compute 24! Please enter four numbers such as 1 2 3 4.\nExit: 0 0 0 0.\n");

    while (interface > 0 && nums[0] + nums[1] + nums[2] + nums[3])
    {
        // Interface 1: read from command line
        if (1 == interface)
            for (int i = 2; i < argc; i++)
                nums[i-2] = atoi(argv[i]);
        // Interface 2: read from the buffer provided by keyboard
        // Interface 3: read from the buffer provided by files
        else
            scanf("%d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3]);

        char operations[] = "+-*/", *resOperations;
        int i, resSize, pnumsSize, operationsSize = 4, **pnums = permute(nums, numsSize, &pnumsSize);
        for (i = 0, resSize = 0; resSize == 0 && i < pnumsSize; i++)
            resOperations = brutalForceCompute(pnums[i], numsSize, operations, operationsSize, &resSize);

        // Print out the result
        if (interface == 3)
            printf("%2d %2d %2d %2d: ", nums[0], nums[1], nums[2], nums[3]);
        else
            printf("%d %d %d %d: ", nums[0], nums[1], nums[2], nums[3]);
        if (i-- < pnumsSize && resSize == 3)
            printf("((%d %c %d) %c %d) %c %d\n", pnums[i][0], resOperations[0], pnums[i][1], resOperations[1], pnums[i][2], resOperations[2], pnums[i][3]);
        else
            printf("Impossible to make up 24.\n");

        free(pnums);
        free(resOperations);
        if (interface == 1)
            interface--;
    }

    if (interface > 0 && interface < 3)
        printf("Program exited.\n");
    return 0;
}

char* brutalForceCompute(int *nums, int numsSize, char operations[], int operationsSize, int *returnSize)
{
    *returnSize = 0;
    char *foundOperations = malloc((*returnSize + 1)* sizeof(char));
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
                if (fabs(binaryOperation(tmp2, nums[3], operations[k]) - 24.0) < 1e-10)
                {
                    *returnSize = 3;
                    foundOperations = realloc(foundOperations, (*returnSize + 1)* sizeof(char));
                    foundOperations[*returnSize] = '\0';
                    foundOperations[0] = operations[i];
                    foundOperations[1] = operations[j];
                    foundOperations[2] = operations[k];
                    return foundOperations;
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
