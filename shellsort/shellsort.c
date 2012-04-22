#include <stdio.h>

void shell_sort(int *A, const int n);
void swap(int *A, const int a, const int b);

int main(void)
{
	int A[] = {4, 2, 5, 8, 3, 9, 10, 100, 29, 30, 77};
	shell_sort(A, 10);

	int i = 0;
	for (; i < 10; ++i) {
		printf("%d\n", A[i]);
	}
	return 0;
}

void shell_sort(int *A, const int n)
{
	int i, j, increment;

	for (increment = n / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i < n; ++i)
		{
			for (j = i; j >= increment; j -= increment)
			{
				if (A[j] < A[j - increment])
					swap(A, j, j - increment);
				else
					break;
			}
		}
	}
}

void swap(int *A, const int a, const int b)
{
	int tmp = A[a];
	A[a] = A[b];
	A[b] = tmp;
}
