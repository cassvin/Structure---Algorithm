#ifndef _TREE
#define _TREE

typedef struct TreeNode *SearchTree;
typedef struct TreeNode *Position;
typedef int ElementType;

void make_empty(SearchTree tree);
SearchTree find(const ElementType x, const SearchTree tree);
SearchTree find_min(SearchTree tree);
SearchTree find_max(SearchTree tree);
SearchTree insert(const ElementType x, SearchTree tree);
SearchTree _delete(const ElementType x, SearchTree tree);

#endif

struct TreeNode
{
	ElementType x;
	SearchTree left;
	SearchTree right;
};

