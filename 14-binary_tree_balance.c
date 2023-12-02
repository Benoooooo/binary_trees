#include "binary_trees.h"

/**
 * height_of_tree - Function to calculate the height of a tree
 * @tree: binary tree to measure
 * @n: accumulated height of current tree
 * @height: pointer to maximum height value
 * Return: void
 */

void height_of_tree(const binary_tree_t *tree, int n, int *height)
{
	if (tree != NULL)
	{
		if ((tree->left == NULL) && (tree->right == NULL))
		{
			if (n > *height)
			{
				*height = n;
			}
		}
		else
		{
			height_of_tree(tree->left, n + 1, height);
			height_of_tree(tree->right, n + 1, height);
		}
	}
}

/**
 * binary_tree_balance - measure the balance factor of a binary tree
 * @tree: pointer to the root of the binary tree
 * Return: balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor = 0;
	int left_height = 0;
	int right_height = 0;

	if (tree != NULL)
	{
		height_of_tree(tree->left, 1, &left_height);
		height_of_tree(tree->right, 1, &right_height);
	}
	balance_factor = left_height - right_height;
	return (balance_factor);
}
