/* 	
 *  Big Heap 
 *  To be complished 	
*/
#include <stdio.h>

void heap_sort(int *A, const int array_size);
void build_heap(int *A, const int array_size);
void heapify(int *A, const int pos, const int heap_size);
void swap(int *A, const int a, const int b);

int main(void)
{
	int A[] = {4, 2, 5, 8, 3, 9, 6, 29, 21, 33};

	printf("The origin array is : ");
	int i = 0;
	for (; i < 10; ++i) {
		printf("%d  ", A[i]);
	}
	printf("\n");

	heap_sort(A, 10);

	printf("Now the array is : ");
	for (i = 0; i < 10; ++i) {
		printf("%d  ", A[i]);
	}
	printf("\n");
	return 0;
}

void heap_sort(int *A, const int array_size)
{
	build_heap(A, array_size);

	int heap_size = array_size;
	int i = heap_size - 1;
	for (; i > 0; --i)
	{
		swap(A, i, 0);
		--heap_size;
		heapify(A, 0, heap_size);
	}
}

void build_heap(int *A, const int array_size)
{
	int heap_size = array_size;
	int i =  heap_size / 2 - 1;
	for (; i >= 0; --i)
		heapify(A, i, heap_size);
}

void heapify(int *A, const int pos, const int heap_size)
{
	int left = pos * 2 + 1; 
	int right =  (pos + 1) * 2;
	
	int largest = pos;
	if (left < heap_size && A[largest] < A[left])
		largest = left;
	if (right < heap_size && A[largest] < A[right])
		largest = right;

	if (largest != pos)
	{
		swap(A, largest, pos);
		heapify(A, largest, heap_size);
	}
	
}

void swap(int *A, const int a, const int b)
{
	int tmp = A[a];
	A[a] =  A[b];
	A[b] = tmp;
}

