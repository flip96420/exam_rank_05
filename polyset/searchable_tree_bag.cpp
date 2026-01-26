#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &source) : tree_bag(source) {}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &source)
{
	if (this != &source)
		tree_bag::operator=(source);
	return (*this);
}

searchable_tree_bag::~searchable_tree_bag() {}

bool searchable_tree_bag::search(node *node, const int item) const
{
	if (node == nullptr)
		return (false);
	if (item == node->value)
		return (true);
	else if (item < node->value)
		return (search(node->l, item));
	else
		return (search(node->r, item));
}

bool searchable_tree_bag::has(int item) const
{
	return (search(this->tree, item));
}