#include "LinkedList.h"



template <class N> 
LinkedList<N>::LinkedList()
{
	head = nullptr;
	size = 0;
}

template<class T>
LinkedList<T>::LinkedList(const T & nodeData)
{
	Node<T>* tempNode = new Node<T>;
	tempNode->data = nodeData;
	tempNode->next = nullptr;
	head = tempNode;
	size = 1;
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
