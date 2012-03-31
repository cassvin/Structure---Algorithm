#include <stdio.h>

void quick_sort(int A[], int p, int r);
void swap(int A[], int i, int j);
int partition(int A[], int p, int r);

int main()
{
	int A[] = {4, 2, 5, 8, 3, 9, 10, 100, 29, 30, 77};
	quick_sort(A, 0, 10);
	int i = 0;
	for (; i <= 10; ++i) {
		printf("%d\n", A[i]);
	}
	return 0;
}

void quick_sort(int A[], int p, int r)
{
	if (p < r) {
		int kval = partition(A, p, r);
		quick_sort(A, p, kval - 1);
		quick_sort(A, kval + 1, r);
	}
}

void swap(int A[], int i, int j)
{
	int tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
}

int partition(int A[], int p, int r) 
{
	int x = A[r];
	int i = p - 1, j = p;
	
	for (; j < r; ++j) {
		if (A[j] < x) {
			++i;
			swap(A, i, j);
		}
	}
	swap(A, r, i + 1);

	return(i + 1);
}

