#pragma once

#include "subject/subject/tree_bag.hpp"
#include "subject/subject/searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
	private:
		bool search(node *node, const int item) const;
	public:
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag &source);
		searchable_tree_bag &operator=(const searchable_tree_bag &source);
		~searchable_tree_bag();

		bool has(int item) const;
};