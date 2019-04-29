#include "LinkedList.h"



template <class T> 
LinkedList<T>::LinkedList()
{
	size = 0;
	head = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(const T & nodeData)
{
	size = 0;
	addNode(nodeData);
}

template<class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* currentNode = head;
	while (currentNode != nullptr)
	{
		Node<T>* tempNode = currentNode->next;
		delete currentNode;
		currentNode = tempNode;
	}
}

template<class T>
void LinkedList<T>::addNode(const T & nodeData)
{
	Node<T>* tempNode = new Node<T>;
	tempNode->data = nodeData;
	tempNode->next = nullptr;
	
	if (head == nullptr)
	{
		head = tempNode;
	}
	else
	{
		Node<T>* currentNode = head;
		while (currentNode->next != nullptr)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = tempNode;
	}
	size++;
}
