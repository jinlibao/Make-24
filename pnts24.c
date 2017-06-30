/****************************************************************************** 	
	This file is a sample of parallelized C code by Lingxiao
	Ready for any benchmark test.
	(should be always kept in desktop)

	How to run:
	compile ------>  mpicc sample_MPI.c
	run     ------> ./a.out on unix (or sbatch on Mtmoran, or bsub on YS)
******************************************************************************/

// # include <mpi.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <string.h>
# include <sys/time.h>
# define  N 10	// operators
# define  M 3 	// locs

int** permutation(int*, int);
int factorial(int);
void zeros(int*, int);

int main(int argc, char *argv[])
{
	int array[N], comp[N], ind[N] = {0, 0, 0, 0};
// 	int array2D[24][N], comp2D[4*4*4][M];
// 	int final;
//
// 	int i, j, k;
//
// 	/* initialize operations */
// 	for (i = 0; i < N-1; i++)
// 	{
// 		comp[i] = i + 1;
// 	}
	
	for (int i = 0; i < N; i++)
		array[i] = i + 1;
	
	// /* generate tables */
	// for (i = 0; i < ; i++)
	//
	//
	// for (i = 0; i < N-1; i++)
	// {
	// 	final = 1;
	// 	for (j = 0; j < N-1; j++)
	// 	{
	// 		for (k = 0; k < N-1; k++)
	// 		{
	// 			if (i == 0 || j == 0 || k == 0)
	// 			{
	// 				final = final + ;
	// 			}
	//
	// 		}
	// 	}
	// }
	
	int n = N;
	int** permuted_arrays = permutation(array, n);
	int fn = factorial(n);
	for (int i = 0; i < fn; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%-5d", permuted_arrays[i][j]);
		}
		printf("\n");
	}
		
	return 0;	
}
	
	
int oper(int *final, int oper, int next, int ith)
{
	if (oper == 0)
	{
		if (ith == 0)
		{
			*final = 0;
		}
		*final = *final + next;
	}
	if (oper == 1)
	{
		if (ith == 0)
		{
			*final = 0;
		}
		*final = *final - next;
	}
	if (oper == 2)
		*final = *final * next;
	if (oper == 3)
	{
		if (*final%next != 0)
		{
			return 0;
		}
		else
		{
			*final = *final / next;
		}
	}		
	return 1;
}
	
int** permutation(int* a, int n)
{
	if (n == 1)
	{
		
		int** b = (int **)malloc(n * sizeof(int *));
		*b = (int *)malloc(1 * sizeof(int));
		b[0][0] = a[0];
		return b;
	}
	else
	{
		int fn = factorial(n);
		int fm = factorial(n-1);

		// int b[fn][n];
		int **b = (int **)malloc(fn * sizeof(int *));
		    for (int i=0; i < fn; i++)
		         b[i] = (int *)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++)
		{
			int indicator[n];
			zeros(indicator, n);
			for (int j = 0; j < fm; j++)
			{
				b[i * fm + j][0] = a[i];
			}
			
			indicator[i] = 1;
			int c[n-1];
			int k = 0;
			
			for (int j = 0; j < n; j++)
			{
				if (indicator[j] == 1)
				{
					continue;
				}
				else
				{
					c[k] = a[j];
					k++;
				}
			}
			int** d = permutation(c, n-1);
			for (int j = 0; j < fm; j++)
			{
				for (int k = 1; k < n; k++)
				{
					b[i * fm + j][k] = d[j][k-1];
				}
			}
		}
		return b;
	}
}
	
int factorial(int n)
{
	if (n == 1)
		return n;
	else
	{
		return n * factorial(n-1);
	}
}

void zeros(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
	}
}