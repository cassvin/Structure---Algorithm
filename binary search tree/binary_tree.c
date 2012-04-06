#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>

void make_empty(SearchTree tree)
{
	if (tree != NULL) 
	{
		make_empty(tree->left);
		make_empty(tree->right);
		free(tree);
	}
}

SearchTree find(const ElementType x, const SearchTree tree)
{
	if (tree == NULL) 
	{
		perror("The tree is empty.");
		return NULL;
	}
	else
	{
		if (tree->x > x) 
			find(x, tree->left);
		else if (tree->x < x)
			find(x, tree->right);
		else 
			return tree;
	}
}

SearchTree find_min(SearchTree tree)
{
	if (tree == NULL) 
	{
		perror("The tree is empty.");
		return NULL;
	}
	while (tree->left != NULL)
	{
		tree = tree->left;
	}

	return tree;
}

SearchTree find_max(SearchTree tree)
{
	if (tree == NULL) 
	{
		perror("The tree is empty.");	
		return NULL;
	}
	while (tree->right != NULL) 
	{
		tree = tree->right;
	}

	return tree;
}

SearchTree insert(const ElementType x, SearchTree tree)
{
	if (tree == NULL) 
	{
		tree = malloc(sizeof(struct TreeNode));
		if (tree == NULL) 
		{
			perror("Failed to alloc memory for the tree node.");
			return NULL;
		}

		tree->x =x;
		tree->left = tree->right = NULL;
	}
	else if (tree->x > x)
		tree->left = insert(x, tree->left);
	else if (tree->x < x)
		tree->right = insert(x, tree->right);

	return tree;
}

SearchTree _delete(const ElementType x, SearchTree tree)
{
	if (tree == NULL) 
	{
		perror("The tree is empty.");
		return NULL;
	}
	else
	{
		if (tree->x > x)
			tree->left = _delete(x, tree->left);
		else if (tree->x < x)
			tree->right = _delete(x, tree->right);
		else if (tree->left && tree->right)
		{
			Position tmp_pos = find_min(tree->right);
			tree->x = tmp_pos->x;
			tree->right = _delete(tmp_pos->x, tree->right);
		}
		else 
		{
			Position tmp_pos = tree;
			if (tree->left == NULL) 
				tree = tree->right;
			else if (tree->right == NULL)
				tree = tree->left;
			free(tree);
		}
	}

	return tree;
}

