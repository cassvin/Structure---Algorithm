#include <stdio.h>

void insert_sort(int A[], int len);
void swap(int A[], int i, int j);

int main()
{
	int A[] = {4, 2, 5, 8, 3, 9, 10, 100, 29, 30, 77};
	insert_sort(A, 10);

	int i = 0;
	for (; i < 10; ++i) {
		printf("%d\n", A[i]);
	}

	return 0;
}

void swap(int A[], int i, int j)
{
	int tmp;
	tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
}

void insert_sort(int A[], int len)
{
	int i = 1, j = 0;

	for (; i < len; ++i) {
		for (j = i; j != 0 && (A[j] < A[j - 1]); --j) {
			swap(A, j, j - 1);
		}
	}

}
