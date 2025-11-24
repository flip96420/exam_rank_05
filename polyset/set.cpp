#include "set.hpp"
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"
#include <stdexcept>

set::set()
{
	bag = new searchable_array_bag();
}

set::set(const searchable_bag &src)
{
	if (auto array = dynamic_cast<const searchable_array_bag *>(&src))
		bag = new searchable_array_bag(*array);
	else if (auto tree = dynamic_cast<const searchable_tree_bag *>(&src))
		bag = new searchable_tree_bag(*tree);
	else
		throw std::runtime_error("Searchable_bag type not found.");
}

set::set(const set &src)
{
	const searchable_bag &bg = *src.bag;

	if (auto array = dynamic_cast<const searchable_array_bag *>(&bg))
		bag = new searchable_array_bag(*array);
	else if (auto tree = dynamic_cast<const searchable_tree_bag *>(&bg))
		bag = new searchable_tree_bag(*tree);
	else
		throw std::runtime_error("Searchable_bag type not found.");
}

set &set::operator=(const set &src)
{
	if (this != &src)
	{
		delete bag;
		const searchable_bag &bg = *src.bag;

		if (auto array = dynamic_cast<const searchable_array_bag *>(&bg))
			bag = new searchable_array_bag(*array);
		else if (auto tree = dynamic_cast<const searchable_tree_bag *>(&bg))
			bag = new searchable_tree_bag(*tree);
		else
			throw std::runtime_error("Searchable_bag type not found.");
	}
	return (*this);
}

set::~set()
{
	delete bag;
}

void set::insert(int item)
{
	bag->insert(item);
}

void set::insert(int *array, int item)
{
	bag->insert(array, item);
}

void set::print() const
{
	bag->print();
}

void set::clear()
{
	bag->clear();
}

bool set::has(int item) const
{
	return (bag->has(item));
}

searchable_bag &set::get_bag()
{
	return (*bag);
}