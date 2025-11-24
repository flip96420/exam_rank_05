#pragma once 

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
	public:
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag &);
		searchable_tree_bag  &operator=(const searchable_tree_bag &);
		~searchable_tree_bag();

		bool has(int) const;

	private:
		static void destroy_tree(node *);
		static void print_node(node *);
		static tree_bag::node *copy_node(node *);
};