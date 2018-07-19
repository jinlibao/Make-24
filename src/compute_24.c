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
 * Version: v1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

double binaryOperation(double num1, double num2, char operation);
char* brutalForceCompute(int *nums, int numsSize, char operations[], int operationsSize, int *returnSize);

int main(int argc, char* argv[])
{
    int nums[4] = {0, 0, 0, 1}, numsSize = 4, operationsSize = 4, resSize, interface = 1;
    char operations[] = "+-*/", *resOperations;

    if (argc > 1)
        if (atoi(argv[1]) == 2)
            interface = 2;

    if (interface == 1)
    {
        if (argc <= 1)
            printf("Welcome to Compute 24! Please enter four numbers such as 1 2 3 4.\nExit: 0 0 0 0.\n");
        while (nums[0] + nums[1] + nums[2] + nums[3])
        {
            scanf("%d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3]);
            resOperations = brutalForceCompute(nums, numsSize, operations, operationsSize, &resSize);

            if (argc > 1)
                printf("%2d %2d %2d %2d: ", nums[0], nums[1], nums[2], nums[3]);
            else
                printf("%d %d %d %d: ", nums[0], nums[1], nums[2], nums[3]);

            if (resSize == 3)
                printf("((%d %c %d) %c %d) %c %d\n", nums[0], resOperations[0], nums[1], resOperations[1], nums[2], resOperations[2], nums[3]);
            else
                printf("Impossible to make up 24.\n");
            free(resOperations);
        }
    }
    else
    {
        // Interface 2: read from command line
        for (int i = 2; i < argc; i++)
            nums[i-2] = atoi(argv[i]);
            resOperations = brutalForceCompute(nums, numsSize, operations, operationsSize, &resSize);
            printf("%d %d %d %d: ", nums[0], nums[1], nums[2], nums[3]);
            if (resSize == 3)
                printf("((%d %c %d) %c %d) %c %d\n", nums[0], resOperations[0], nums[1], resOperations[1], nums[2], resOperations[2], nums[3]);
            else
                printf("Impossible to make up 24.\n");
    }

    printf("Program exited.\n");
    return 0;
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
