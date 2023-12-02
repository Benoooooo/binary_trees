#include "binary_trees.h"

/**
* binary_tree_rotate_left - rotates a tree leftward
* @tree: The root node
* Return: The new root
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp, *parent;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	tmp = tree;
	parent = tree->parent;
	tree = tree->right;

	if (tree->left)
	{
		tmp->right = tree->left;
		tree->left->parent = tmp;
	}
	else
	{
		tmp->right = NULL;
	}
	tmp->parent = tree;
	tree->left = tmp;

	if (parent != NULL)
	{
		parent->right = tree;
		tree->parent = parent;
	}

	return (tree);
}
