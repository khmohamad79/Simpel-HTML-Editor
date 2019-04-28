#pragma once
template <class T> class Node
{
	T data;
	Node* next;
};
template <class T> class LinkedList
{
	unsigned int size;
	Node<T>* head;
public:
	LinkedList();
	LinkedList(const T & nodeData);
	~LinkedList();
	void addNode(const T & nodeData);
	void addNode(const T & nodeData, const unsigned int & index);
	// void addNode(const T & nodeData, Node<T>* previousNode);
	void removeNode(const unsigned int & index);
	void removeNode(Node<T>* nodePtr);
	T* getNodeData(const unsigned int & index) const;
	Node<T>* getNode(const unsigned int & index) const;
	// Node<T>* getNode(Node<T>* previousNode) const;
	unsigned int getSize() const;
};

