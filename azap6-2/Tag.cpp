#include "Tag.h"



Tag::Tag()
{
	text = "";
}


Tag::~Tag()
{
}

void Tag::addTag(const Tag & tag)
{
	tags.push_back(tag);
	texts.push_back("");
}

void Tag::addText(const char * str)
{
	if (texts.size() > 0) *(texts.end()) = str;
	else text = str;
}

