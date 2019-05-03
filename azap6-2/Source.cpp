#include <iostream>
#include <fstream>
#include <string>
#include "PairedTag.h"
#include "SingleTag.h"
#include "TagMenu.h"

using namespace std;

int main()
{
	
	PairedTag body("body");
	body.addText("start");
	body.addTag(new PairedTag("h1"));
	body.addTag(new SingleTag("a"));
	body.addText("middle",0);

	PairedTag* pt = (PairedTag*)body.getTag(1);
	showMenu(&body);
	//pt->addTag(new SingleTag("hr"));
	//body.addTag(new PairedTag("p"));
	//body.addTag(new SingleTag("a"));
	//body.addText("end");

	
	//temp1->addAttr("style", "color:red;");
	//temp1->addText("Header1");
	
	/*Tag* temp2 = &body.getTag(1);
	temp2->addAttr("style", "color:blue;");
	temp2->addText("parag");
	*/
	fstream fp("index.html", ios::out);
	fp << body;
	fp.close();

	cout << body <<endl;

	return 0;
}