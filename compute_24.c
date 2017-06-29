#include <stdio.h>
#include <stdlib.h>
#define N 4

int** permutation(int, int*);
int factorial(int);
void zeros(int, int*);

int main()
{
    int numbers[N];
    /*int* numbers;*/
    int n, fn;
    n = N;
    fn = factorial(N);
    for (int i = 0; i < n; i++)
    {
        numbers[i] = i + 1;
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int** array_2d;
    array_2d = permutation(n, numbers);
    /*printf("%d %d\n%d %d\n", array_2d[0][0], array_2d[0][1], array_2d[1][0], array_2d[1][1]);*/
    for (int i = 0; i < fn; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%-5d", array_2d[i][j]);
            /*printf("array_2d[%d][%d] = %d\n", i, j, array_2d[i][j]);*/
        printf("\n");
    }

    return 0;
}

int** permutation(int n, int* array)
{
    if (n == 1)
    {
        int array_2d[n][n];
        int** ptr_array_2d;
        int* ptr_array[n];
        for (int i = 0; i < n; i++)
        {
            ptr_array[i] = array_2d[i];
        }
        array_2d[0][0] = array[0];
        ptr_array_2d = ptr_array;
        return ptr_array_2d;
    }
    else
    {
        int fn = factorial(n), fm = factorial(n-1);
        int** ptr_array_2d;
        int* ptr_array[fn];
        int array_2d[fn][n];

        for (int i = 0; i < fn; i++)
        {
            ptr_array[i] = array_2d[i];
        }
        ptr_array_2d = ptr_array;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < fm; j++)
                array_2d[i * fm + j][0] = array[i];

            int indicator[n];
            zeros(n, indicator);
            indicator[i] = 1;
            int new_array[n-1], k = 0;
            for (int j = 0; j < n; j++)
            {
                if (indicator[j] == 0)
                {
                    new_array[k] = array[j];
                    k++;
                }
            }

            int** subarray_2d = permutation(n-1, new_array);
            for (int j = 0; j < fm; j++)
            {
                for (int k = 0; k < n-1; k++)
                    array_2d[i * fm + j][k+1] = subarray_2d[j][k];
            }
        }
        return ptr_array_2d;
    }
}

int factorial(int n)
{
    if (n == 1)
        return n;
    else
        return n * factorial(n-1);
}

void zeros(int n, int* array)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = 0;
    }
}
