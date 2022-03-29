#pragma once
#include "ArrayBag.h"

template<class ItemType>
int ArrayBag<ItemType>::getIndexOfRecursive(const ItemType& target, int searchIndex) const
{
	int result = -1;
	if (searchIndex < itemCount)
	{
		if (items[searchIndex] == target)
		{
			result = searchIndex;
		}
		else
		{
			result = getIndexOf(target, searchIndex + 1);
		}
	}
	return result;
}

/*The recursive method needs searchIndex as a parameter.
However, getFrequencyOf is a public method, so we cannot change its signature.
Instead, getFrequencyOf must call a private method that accomplishes the recursive search.*/
template<class ItemType>
int ArrayBag<ItemType>::countFrequency(const ItemType& target, int searchIndex) const
{
	int frequency = 0;
	if (searchIndex < itemCount)
	{
		if (items[searchIndex] == target)
		{
			frequency = 1 + countFrequency(target, searchIndex + 1);
		}
		else
		{
			frequency = countFrequency(target, searchIndex + 1);
		}
	}
	return frequency;
}

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOfRecursive(const ItemType& anEntry) const
{
	return countFrequency(anEntry, 0);
}
