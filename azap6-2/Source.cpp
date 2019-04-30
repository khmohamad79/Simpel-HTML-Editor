#include <iostream>
#include <fstream>
#include "string"
#include "Tag.h"

using namespace std;

int main()
{
	Tag* temp;
	Tag body("body");
	body.addText("before");
	body.addTag(Tag("h1"));
	body.addText("after");
	temp = &body.getTag(0);
	temp->addAttr("style", "color:red;");
	temp->addText("Header1");
	
	fstream fp("index.html", ios::out);
	fp << body;
	//fp.close();
	return 0;
}