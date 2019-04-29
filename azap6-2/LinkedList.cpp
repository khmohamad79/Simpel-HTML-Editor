#include "LinkedList.h"



template<class T> 
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

template<class T>
void LinkedList<T>::addNode(const T & nodeData, const unsigned int & index)
{
	if (index<0 || index>size) return;
	else if (index == size) addNode(nodeData);
	else if (index == 0)
	{
		Node<T>* tempNode = new Node<T>;
		tempNode->data = nodeData;
		tempNode->next = head;
		head = tempNode;
	}
	else
	{
		Node<T>* previousNode = head;
		for (int i = 0; i < (index - 1); i++) previousNode = previousNode->next;
		Node<T>* tempNode = new Node<T>;
		tempNode->data = nodeData;
		tempNode->next = previousNode->next;
		previousNode->next = tempNode;
	}
	size++;
}

template<class T>
void LinkedList<T>::removeNode(const unsigned int & index)
{
	if (index<0 || index>=size) return;
	else if (index == 0)
	{
		Node<T>* tempNode = head->next;
		delete head;
		head = tempNode;
	}
	else
	{
		Node<T>* previousNode = head;
		for (int i = 0; i < (index - 1); i++) previousNode = previousNode->next;
		Node<T>* tempNode = previousNode->next->next;
		delete previousNode->next;
		previousNode->next = tempNode;
	}
	size--;
}

template<class T>
T LinkedList<T>::getNodeData(const unsigned int & index) const
{
	if (index<0 || index>=size) return NULL;
	else
	{
		Node<T>* currentNode = head;
		for (int i = 0; i < index; i++) currentNode = currentNode->next;
		return currentNode->data;
	}
	return T();
}

template<class T>
unsigned int LinkedList<T>::getSize() const
{
	return size;
}


