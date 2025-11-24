#pragma once
#include "subject/searchable_bag.hpp"

class set 
{
	private:
		searchable_bag *bag;

	public:
		set();
		set(const searchable_bag &src);
		set(const set &src);
		set  &operator=(const set &src);
		~set();

		void insert(int);
		void insert(int *, int);
		void print()const;
		void clear();
		bool has(int) const;
		searchable_bag &get_bag();
};