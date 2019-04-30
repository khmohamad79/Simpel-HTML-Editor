#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main()
{
	LinkedList<string> mylist;
	mylist.addNode("1");
	mylist.addNode("2");
	for (int i = 0; i < mylist.getSize(); i++)
	{
		cout << mylist.getNodeData(i).c_str();
	}
	mylist.addNode("0", 2);
	cout << endl;
	for (int i = 0; i < mylist.getSize(); i++) cout << mylist.getNodeData(i).c_str();
	cout << endl;
	mylist.addNode("0", 1);
	while (mylist.getSize()>0)
	{
		cout << mylist.getNodeData(mylist.getSize() - 1).c_str();
		mylist.removeNode(mylist.getSize() - 1);
	}
	cout << mylist.getSize();
	return 0;
}