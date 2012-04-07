#include <stdio.h>

void selection_sort(int *A, const int len);
int find_min(const int *A, const int start, const int len);
void swap(int *A, const int a, const int b);

int main(void)
{
	int A[] = {4, 2, 5, 8, 3, 9, 10, 29, 30, 77};
	selection_sort(A, 10);
	
	int i = 0;
	for (; i < 10; ++i)
	{
		printf("%d\n", A[i]);
	}

	return 0;
}

void selection_sort(int *A, const int len)
{
	int pos = 0, pos_min = 0;
	for (; pos < len - 1; ++pos)
	{
		pos_min = find_min(A, pos, len);
		swap(A, pos, pos_min);
	}
	return;
}

void swap(int *A, const int a, const int b)
{
	int tmp = A[a];
	A[a] =  A[b];
	A[b] = tmp;
}

int find_min(const int *A, const int start, const int len)
{ 
	int i = start, pos_min = start, min = A[pos_min];
	for (; i < len; ++i)
	{
		if (min > A[i])
		{
			pos_min = i;
			min = A[i];
		}
	}
	return pos_min;
}

