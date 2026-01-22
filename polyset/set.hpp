#pragma once

#include "subject/subject/searchable_bag.hpp"

class set
{
	private:
		searchable_bag &bag;
	public:
		set() = delete;
		set(const set &source) = delete;
		set &operator=(const set &source) = delete;
		set(searchable_bag &source);
		~set();

		bool has(int item) const;
		void insert(int item);
		void insert(int *data, int size);
		void print() const;
		void clear();

		const searchable_bag &getBag();
};