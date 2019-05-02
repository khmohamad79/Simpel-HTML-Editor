#include "Tag.h"



void Tag::generateHtml(std::ostream & output) const
{
	output << "<<" << name;
	output << ">>";
	output << "<</" << name << ">>";
}

Tag::Tag(std::string tag_name)
{
	name = tag_name;
}

Tag::~Tag()
{
}

void Tag::addAttr(const char * str_name, const char * str_value)
{
	attributes.insert({ str_name, str_value });
}

void Tag::removeAttr(const char * str_name)
{
	attributes.erase(str_name);
}

void Tag::clearAttrs()
{
	attributes.clear();
}

void Tag::updateAttr(const char * str_name, const char * str_value)
{
	attributes.at(str_name) = str_value;
}

std::string Tag::getName() const
{
	return name;
}

std::string Tag::getAttrVal(const char * str_name) const
{
	return attributes.at(str_name);
}

std::ostream & operator<<(std::ostream & output, const Tag & tag)
{
	tag.generateHtml(output);
	return output;
}
