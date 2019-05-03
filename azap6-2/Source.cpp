#include <iostream>
#include <fstream>
#include <string>
#include "PairedTag.h"
#include "SingleTag.h"
#include "TagMenu.h"

using namespace std;

int main()
{
	char file_name[81];
	cout << "enter file name:";
	cin.getline(file_name, 80);

	cout << "*** back from body = save ***\n";
	cout << "press any key to create html tag!";
	cin.get();

	fstream fp(strcat(file_name, ".html"), ios::out);
	if (!fp) {
		cout << endl;
		cout << "problem opennig file!!\n";
	}
	else
	{
		PairedTag html("html");
		showMenu(&html);
		fp << html;
		fp.close();
		cout << endl;
		cout << "file created successfully\n";
	}
	return 0;
}