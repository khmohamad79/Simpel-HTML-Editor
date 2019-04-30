#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main()
{
	LinkedList<int> mylist;
	mylist.addNode(1);
	mylist.addNode(2);
	for (int i = 0; i < mylist.getSize(); i++)
	{
		cout << mylist.getNodeData(i);
	}
	cout << endl;
	mylist.addNode(0, 2);
	while (mylist.getSize()>0)
	{
		cout << mylist.getNodeData(mylist.getSize() - 1);
		mylist.removeNode(mylist.getSize() - 1);
	}
	return 0;
}