#pragma once
#include "BagInterface.h"
#include "Node.h"

template < class ItemType>
class LinkedListBag : public BagInterface<ItemType>
{
private:
	Node<ItemType>* headPtr;
	int itemCount;
	
	Node<ItemType>* getPointerTo(const ItemType& target) const	
	{
		bool found = false;
		Node<ItemType>* curPtr = headPtr;
		while (!found && (curPtr != nullptr))
		{
			if (target == curPtr->getItem())
				found = true;														//Could I return "curPtr" here instead of using "found"
			else
				curPtr = curPtr->getNext();
		}
		return curPtr;
		
	}

public:
	LinkedBag()
	{
		headPtr = nullptr;
		itemCount = 0;
	}

	LinkedBag(const LinkedBag<ItemType>& aBag)										// Copy constructor
	{
																					//How can this constructor access private data members
		itemCount = aBag->itemCount;
		Node<ItemType>* origChainPtr = aBag->headPtr
			if (origChainPtr == nullptr)
				headPtr = nullptr; 
			else
			{
				// Copy first node
				headPtr = new Node<ItemType>();
				headPtr->setItem(origChainPtr->getItem());
				// Copy remaining nodes
				Node<ItemType>* newChainPtr = headPtr; // Last-node pointer			//NewChainPtr
				while (origPtr != nullptr)
				{
					origChainPtr = origChainPtr->getNext(); // Advance pointer
					// Get next item from original chain
					ItemType nextItem = origChainPtr->getItem();
					// Create a new node containing the next item
					Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);		//newNodePtr
																					//Isn't this pointer re-defined with every iteration?
					// Link new node to end of new chain
					newChainPtr->setNext(newNodePtr);
					// Advance pointer to new last node
					newChainPtr = newChainPtr->getNext();
				} 
				newChainPtr->setNext(nullptr); // Flag end of new chain
			}
	}
	
	virtual ~LinkedBag() // Destructor should be virtual
	{
		clear();
	}

	int getCurrentSize() const
	{
		return itemCount;
	}

	bool isEmpty() const
	{
		return itemCount == 0;
	}

	bool add(const ItemType& newEntry)												//Why do I need a bool return type?
	{
		Node<ItemType>* newNodePtr = new Node<ItemType>();
		newNodePtr->setItem(newEntry);
		newNodePtr->setNext(headPtr);
		headPtr = newNodePtr;
		itemCount++;
		return true;
	}

	bool remove(const ItemType& anEntry)
	{
		Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
		bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);				//Why do I need to check isEmpty?
		if (canRemoveItem)
		{
			// Copy data from first node to located node
			entryNodePtr->setItem(headPtr->getItem());
			// Delete first node
			Node<ItemType>* nodeToDeletePtr = headPtr;
			headPtr = headPtr->getNext();
			// Return node to the system
			nodeToDeletePtr->setNext(nullptr);										//Why do I need this?
			delete nodeToDeletePtr;
			nodeToDeletePtr = nullptr;												//Can't we delete this pointer?
			itemCount--;
		}
		return canRemoveItem;
	}

	void clear()
	{
		while (headPtr != nullptr)
		{
			Node<ItemType>* nodeToDeletePtr = headPtr;								//Isn't this pointer re-defined with every iteration?
			headPtr = headPtr->getNext();
			// Return node to the system
			nodeToDeletePtr->setNext(nullptr);
			delete nodeToDeletePtr;
		} 
		nodeToDeletePtr = nullptr;
		itemCount = 0;
	}
	void clearRecursive();															//Definition in "LinkedListBagRecursiveFunctions"

	bool contains(const ItemType& anEntry) const
	{
		return (getPointerTo(anEntry) != nullptr);
	}

	int getFrequencyOf(const ItemType& anEntry) const
	{
		int frequency = 0;
		int counter = 0;															//Why do I need this counter?
		Node<ItemType>* curPtr = headPtr;
		while ((curPtr != nullptr) && (counter < itemCount))
		{
			if (anEntry == curPtr->getItem())
			{
				frequency++;
			}
			counter++;
			curPtr = curPtr->getNext();
		}
		return frequency;
	}

	vector<ItemType> toVector() const
	{
		vector<ItemType> bagContents;
		Node<ItemType>* curPtr = headPtr;
		int counter = 0;											//Why do I need this counter?
																	//Textbook: Note that the variable counter, while not necessary, provides a defense against going beyond the end of the chain.
		while ((curPtr != nullptr) && (counter < itemCount))
		{
			bagContents.push_back(curPtr->getItem());
			curPtr = curPtr->getNext();
			counter++;
		}
		return bagContents;
	}
	void fillVector(std::vector<ItemType>& bagContents, Node<ItemType>* curPtr) const;	//Definition in "LinkedListBagRecursiveFunctions"
	std::vector<ItemType> toVectorRecursive() const;									//Definition in "LinkedListBagRecursiveFunctions"
};