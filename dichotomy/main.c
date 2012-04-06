#include <stdio.h>

int dichotomy_search(int *A, int key, int top, int tail);

int main(void)
{
	int A[] = {1, 3, 4, 7, 9, 11, 12, 13, 20, 21};
	int key = 21;
	int pos = dichotomy_search(A, key, 0, 9);
	if (pos == -1) 
	{
		printf("Cann't find the keyword %d\n.", key);
		return -1;
	}
	printf("The position of %d is %d.\n", key, pos + 1);
	return 0;
}

int dichotomy_search(int *A, int key, int top, int tail)
{
	if (top > tail)
	{
		perror("Sorry couldn't find the element you want.");
		return -1;
	}
	int mid = (top + tail) / 2;
	if (A[mid] == key)
		return mid;
	if (A[mid] > key)
		return dichotomy_search(A, key, top, mid - 1);
	else 
		return dichotomy_search(A, key, mid + 1, tail);

}

