#include "binary_trees.h"

/**
 * binary_tree_is_bst - check if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return:  return 1 if tree is a valid BST, and 0 otherwise
 * If tree is NULL, return 0
 *
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btib_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btib_helper - check if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * @min: lower bounds
 * @max: upper bounds
 * Return:  return 1 if tree is a valid BST, and 0 otherwise
 *
 */
int btib_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (btib_helper(tree->left, min, tree->n - 1) &&
		btib_helper(tree->right, tree->n + 1, max));
}
