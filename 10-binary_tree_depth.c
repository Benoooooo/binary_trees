#include <stdio.h>
#include "binary_trees.h"

/**
* binary_tree_depth - measures the depth of a node in a binary tree
* @tree: the node
* Return: The depth of the node
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int left_depth = 0, right_depth = 0;

	if (tree == NULL)
	return (0);

	if (tree->parent)
	{
		left_depth = binary_tree_depth(tree->parent) + 1;
		right_depth = binary_tree_depth(tree->parent) + 1;
	}

	if (left_depth > right_depth)
		return (left_depth);
	else
		return (right_depth);
}
