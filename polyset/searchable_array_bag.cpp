#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() {}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &source) : array_bag(source) {}

searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag &source)
{
	if (this != &source)
		array_bag::operator=(source);
	return (*this);
}

searchable_array_bag::~searchable_array_bag() {}

bool searchable_array_bag::has(int item) const
{
	if (!data)
		return (false);
	for (int i = 0; i < size; i++)
	{
		if (item == data[i])
			return (true);
	}
	return (false);
}