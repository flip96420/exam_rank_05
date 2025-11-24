#include "searchable_tree_bag.hpp"
#include <iostream>

searchable_tree_bag::searchable_tree_bag() {
	tree = nullptr;
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &src) {
	tree = copy_node(src.tree);
}

searchable_tree_bag::~searchable_tree_bag() {
	destroy_tree(tree);
}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &src) {
	if (this != &src) {
		destroy_tree(tree);
		tree = copy_node(src.tree);
	}
	return *this;
}

bool searchable_tree_bag::has(int item) const
{
	if (!tree)
		return (false);
	node *current = tree;
	while (true) 
	{
		if (item == current->value)
			return (true);
		else if (current->l != nullptr)
			current = current->l;
		else if (current->r != nullptr)
			current = current->r;
		else
			break;
	}
	return (false);
}

void searchable_tree_bag::destroy_tree(node *current) {
	if (current != nullptr) {
		std::cout << "destroying value: " << current->value << std::endl;
		destroy_tree(current->l);
		destroy_tree(current->r);
		delete current;
	}
}

void searchable_tree_bag::print_node(node *current) {
	if (current != nullptr) {
		print_node(current->l);
		if (current->value != 0)
			std::cout << current->value << " ";
		print_node(current->r);
	}
}

tree_bag::node *searchable_tree_bag::copy_node(node *current) {
	if (current == nullptr) {
		return nullptr;
	} else {
		node *new_node = new node;
		new_node->value = current->value;
		new_node->l = copy_node(current->l);
		new_node->r = copy_node(current->r);
		return new_node;
	}
}