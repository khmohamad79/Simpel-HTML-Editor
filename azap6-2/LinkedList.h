#pragma once
template <class N> class LinkedList
{
	unsigned int size;
	N* head;
public:
	LinkedList();
	LinkedList(const N & node)
	~LinkedList();
	bool addNode(const N & node);
	bool addNode(const N & node, const unsigned int & index);
	bool addNode(const N & node, N* previousNodeptr);
	bool removeNode(const unsigned int & index);
	bool removeNode(N* nodeptr);
	N* getNode(const unsigned int & index) const;
	N* getNode(N* previous) const;
	unsigned int getSize() const;
};

