#include "binary_tree.h"
#include <stdio.h>

int main(void) 
{
	SearchTree tree = NULL;
	ElementType A[] = {3, 2, 1, 4, 9, 5, 10, 48, 22, 13, 11, 88};
	int i = 0;
	for (; i < 12; ++i) {
		tree = insert(A[i], tree);
	}
	SearchTree min_ele = find_min(tree);
	SearchTree max_ele = find_max(tree);
	printf("The min element in tree is %d.\n", min_ele->x);
	printf("The max element in tree is %d.\n", max_ele->x);
	
	printf("Now we insert the element 99.\n");
	tree = insert(99, tree);
	max_ele = find_max(tree);
	printf("The max element now in the tree is %d.\n", max_ele->x);

	printf("Now we delete the element 99.\n");
	tree = _delete(99, tree);
	max_ele = find_max(tree);
	printf("The max element now in the tree is %d.\n", max_ele->x);

	make_empty(tree);

	return 0;
}
