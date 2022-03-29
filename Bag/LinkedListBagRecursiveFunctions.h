#pragma once
#include "LinkedListBag.h"

/*"vector is from the std namespace, so you must use std::to specify"
 I found this on stackOverflow but I don't really understand the reason why I had to use it
 #include <vector> was enough before
*/
template <class ItemType>
void LinkedListBag<ItemType>::fillVector(std::vector<ItemType>& bagContents, Node<ItemType>* curPtr) const
	{
		if (curPtr != nullptr)
		{
			bagContents.push_back(curPtr->getItem());
			fillVector(bagContents, curPtr->getNext());
		}
	}

template < class ItemType>
std::vector<ItemType> LinkedListBag<ItemType>::toVectorRecursive() const										
	{
		vector<ItemType> bagContents;
		fillVector(bagContents, headPtr);
		return bagContents;
	}

template < class ItemType>
void LinkedListBag<ItemType>::clearRecursive()										//Unable to implement with an empty parameterlist
{
}