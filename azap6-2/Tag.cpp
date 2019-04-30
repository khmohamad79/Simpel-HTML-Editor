#include "Tag.h"



Tag::Tag(std::string tag_name)
{
	name = tag_name;
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

void Tag::addAttr(const char * str_name, const char * str_value)
{
	attributes.insert({ str_name, str_value });
}

void Tag::insertTag(const Tag & tag, const unsigned int & index)
{
	tags.insert(tags.begin() + index, tag);
	texts.insert(texts.begin() + index, "");
}

void Tag::insertText(const char * str, const unsigned int & index)
{
	if (index >= 0 && index < texts.size()) texts.at(index) = str;
	else text = str;
}

void Tag::removeTag()
{
	removeTag(tags.size() - 1);
}

void Tag::removeText()
{
	if (texts.size() > 0) *(texts.end()) = "";
	else text = "";
}

void Tag::removeTag(const unsigned int & index)
{
	if (index == 0) text += *(texts.begin());
	else texts.at(index - 1) += texts.at(index);
	tags.erase(tags.begin() + index);
	texts.erase(texts.begin() + index);
}

void Tag::removeText(const unsigned int & index)
{
	if (index >= 0 && index < texts.size()) *(texts.begin() + index) = "";
	else text = "";
}

void Tag::removeAttr(const char * str_name)
{
	attributes.erase(str_name);
}

void Tag::clearTags()
{
	while (tags.size() > 0)
	{
		removeTag();
	}
}

void Tag::clearAttrs()
{
	attributes.clear();
}

void Tag::clear()
{
	clearTags();
	clearAttrs();
	removeText();
}

void Tag::updateTag(const Tag & tag, const unsigned int & index)
{
	tags.at(index) = tag;
}

void Tag::updateText(const char * str, const unsigned int & index)
{
	if (index >= 0 && index < texts.size()) texts.at(index) = str;
	else text = str;
}

void Tag::updateAttr(const char * str_name, const char * str_value)
{
	attributes.at(str_name) = str_value;
}

unsigned int Tag::getSize() const
{
	return tags.size(); // or texts.size()
}

Tag & Tag::getTag(const unsigned int & index)
{
	return tags.at(index);
}

std::string Tag::getName() const
{
	return name;
}

std::string Tag::getText() const
{
	return text;
}

std::string Tag::getText(const unsigned int & index) const
{
	return texts.at(index);
}

std::string Tag::getAttrVal(const char * str_name) const
{
	return attributes.at(str_name);
}

std::ostream & operator<<(std::ostream & output, const Tag & tag)
{
	output << "<" << tag.name;
	for (auto it = tag.attributes.cbegin(); it != tag.attributes.cend(); ++it)
	{
		output << " " << it->first << "=\"" << it->second << "\"";
	}
	output << ">";
	output << tag.text;
	for (int i = 0; i < tag.getSize(); i++)
	{
		output << tag.tags[i] << tag.texts[i];
	}
	output << "</" << tag.name << ">";
	return output;
}
