#include <stdio.h>
#define K 9
#define N 10

void counting_sort(int A[], int B[]);

int main()
{
	int A[N] = {0, 5, 3, 7, 2, 4, 6, 3, 8, 5};
	int B[N] = {0};
	counting_sort(A, B);
	
	int i = 0;
	for (; i < N; ++i) {
		printf("%d\n", B[i]);
	}

	return 0;
}

void counting_sort(int A[], int B[])
{
	int C[K] = {0};

	int i = 0, len = N;
	for (; i < len; ++i) {
		++C[A[i]];
	}

	for (i = 1; i < K; ++i) {
		C[i] += C[i - 1]; 
	}

	for (i = 0; i < N; ++i) {
		B[C[A[i]] - 1] = A[i];
		--C[A[i]];
	}

}
