#include "set.hpp"
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

set::set(searchable_bag &source) : bag(source) {}

set::~set() {}

bool set::has(int item) const
{
	return (bag.has(item));
}

void set::insert(int item)
{
	if (!(this->has(item)))
		bag.insert(item);
}

void set::insert(int *data, int size)
{
	for (int i = 0; i < size; i++)
		this->insert(data[i]);
}

void set::print() const
{
	bag.print();
}

void set::clear()
{
	bag.clear();
}

const searchable_bag &set::getBag()
{
	return (this->bag);
}