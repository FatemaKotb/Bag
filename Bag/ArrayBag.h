#pragma once
#include "BagInterface.h"

template <class ItemType>
class ArrayBag: public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 6;				//Why do I need this to be static?
	ItemType items[DEFAULT_CAPACITY];
	int itemCount;
	int maxItems;										//Why do we need this?

	int getIndexOf(const ItemType& target) const		// -1 indicates not found
	{
		for (int i = 0; i < itemCount; i++)
		{
			if (items[i] == target)
			{
				return i;
			}
		}
		return -1;
	}
	int getIndexOfRecursive(const ItemType& target, int searchIndex) const;			//Definition in "ArrayBagRecursiveFunctions"

public:
	ArrayBag()
	{
		itemCount = 0;
		maxItems = DEFAULT_CAPACITY;
	}

	int getCurrentSize() const
	{
		return itemCount;
	}

	bool isEmpty() const
	{
		return itemCount == 0;
	}

	bool add(const ItemType& newEntry)
	{
		bool hasRoomToAdd = (itemCount < maxItems);
		if (hasRoomToAdd)
		{
			items[itemCount] = newEntry;
			itemCount++;
		}
		return hasRoomToAdd;
	}

	bool remove(const ItemType& anEntry)
	{
		for (int i = 0; i < itemCount; i++)
		{
			if (items[i] == anEntry)
			{
				items[i] = items[itemCount];
				itemCount--;
				return true;
			}
		}
		return false;
	}

	void clear()
	{
		itemCount = 0;
	}

	int getFrequencyOf(const ItemType& anEntry) const
	{
		int frequency = 0;
		for (int i = 0; i < itemCount; i++)
		{
			if (items[i] == anEntry)
			{
				frequency++;
			}
		}
		return frequency;
	}
	int countFrequency(const ItemType& target, int searchIndex) const;				//Definition in "ArrayBagRecursiveFunctions"
	int getFrequencyOfRecursive(const ItemType& anEntry) const;						//Definition in "ArrayBagRecursiveFunctions"

	bool contains(const ItemType& anEntry) const
	{
		for (int i = 0; i < itemCount; i++)
		{
			if (items[i] == anEntry)
			{
				return true;
			}
		}
		return false;
	}

	virtual vector <ItemType> tovector() const
	{
		vector<ItemType> bagContents;
		for (int i = 0; i < itemCount; i++)
		{
			bagContents.push_back(items[i]);
		}
		return bagContents;
	}
};