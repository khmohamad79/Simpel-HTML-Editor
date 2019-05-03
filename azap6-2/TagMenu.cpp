#include "TagMenu.h"


void showMenu(Tag * tag)
{
	int type;
	if (typeid(*tag) == typeid(SingleTag)) type = 1;
	else if (typeid(*tag) == typeid(PairedTag)) type = 2;
	else type = 0;

	system("cls");
	cout << "<" << tag->getName();
	auto attrs = tag->getAttributes();

	int c_attr = 0;
	for (auto it = attrs.cbegin(); it != attrs.cend(); ++it, c_attr++)
	{
		if (c_attr % 3 == 0) cout << endl;
		cout << "\t" << (c_attr + 1) << "." << it->first << "=" << it->second << "\t";
	}

	int c_tag = 0;
	if (type == 2) c_tag = ((PairedTag*)tag)->getSize();

	if (type == 1) cout << "/>" << endl;
	else if (type == 2)
	{
		cout << ">" << endl;
		PairedTag* ptag = (PairedTag*)tag;
		for (int j = 0; j < c_tag; j++)
		{
			Tag* tempTag = ptag->getTag(j);
			cout << "   " << (j + 1) << ".<" << ptag->getTag(j)->getName() << "/>\n";
		}
		cout << "</" << tag->getName() << ">\n";
	}
	else cout << ">" << endl;

	cout << endl;

	if (type == 1 || type == 2)
	{
		cout << "0.Back\n";
		cout << "1.AddAttribute\n";
		cout << "2.EditAttribute\n";
		cout << "3.DeleteAttrribute\n";
	}
	if (type == 2)
	{
		cout << "4.AddText\n";
		cout << "5.EditText\n";
		cout << "6.DeleteText\n";
		cout << "7.AddTag\n";
		cout << "8.OpenTag\n";
		cout << "9.DeleteTag\n";
	}

	int ch_command = 0;
	if (type == 1) {
		do
		{
			cout << "Enter command number:";
			cin >> ch_command;
		} while (ch_command < 0 || ch_command>3);
	}
	else if (type == 2) {
		do
		{
			cout << "Enter command number:";
			cin >> ch_command;
		} while (ch_command < 0 || ch_command>9);
	}

	if (ch_command == 0) return;
	else if (ch_command == 1)
	{
		string ch_name;
		cout << "Enter attribute name to add(0:Cancel):";
		cin >> ch_name;
		if (ch_name != "0")
		{
			cout << "Enter attribute value to add(00:Cancel):";
			string ch_val;
			cin >> ch_val;
			if (ch_val != "00")
			{
				tag->addAttr(ch_name.c_str(), ch_val.c_str());
			}
		}
	}
	else if (ch_command == 2)
	{
		int ch_num;
		do
		{
			cout << "Enter attribute number to edit(0:Cancel):";
			cin >> ch_num;
		} while (ch_num < 0 || ch_num > c_attr);
		if (ch_num > 0)
		{
			int j = 1;
			for (auto it = attrs.cbegin(); it != attrs.cend(); ++it, j++)
			{
				if (j == ch_num)
				{
					cout << it->first << "=";
					string ch_val;
					cin >> ch_val;
					tag->updateAttr(it->first.c_str(), ch_val.c_str());
					break;
				}
			}
		}
	}
	else if (ch_command == 3)
	{
		int ch_num;
		do
		{
			cout << "Enter attribute number to delete(0:Cancel):";
			cin >> ch_num;
		} while (ch_num < 0 || ch_num > c_attr);
		if (ch_num > 0)
		{
			int j = 1;
			for (auto it = attrs.cbegin(); it != attrs.cend(); ++it, j++)
			{
				if (j == ch_num)
				{
					tag->removeAttr(it->first.c_str());
					break;
				}
			}
		}
	}
	
	
	
	showMenu(tag);

}
