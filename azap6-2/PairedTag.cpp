#include "PairedTag.h"



void PairedTag::generateHtml(std::ostream & output) const
{
	output << "<" << name;
	for (auto it = attributes.cbegin(); it != attributes.cend(); ++it)
	{
		output << " " << it->first << "=\"" << it->second << "\"";
	}
	output << ">";
	output << text;
	for (int i = 0; i < getSize(); i++)
	{
		output << tags[i] << texts[i];
	}
	output << "</" << name << ">";
}

PairedTag::PairedTag(std::string tag_name) :
	Tag(tag_name)
{
	name = tag_name;
	text = "";
}


PairedTag::~PairedTag()
{
}

void PairedTag::addTag(const Tag & tag)
{
	tags.push_back(tag);
	texts.push_back("");
}

void PairedTag::addText(const char * str)
{
	if (texts.size() > 0) texts[texts.size() - 1] = str;
	else text = str;
}

void PairedTag::insertTag(const Tag & tag, const unsigned int & index)
{
	tags.insert(tags.begin() + index, tag);
	texts.insert(texts.begin() + index, "");
}

void PairedTag::insertText(const char * str, const unsigned int & index)
{
	if (index >= 0 && index < texts.size()) texts.at(index) = str;
	else text = str;
}

void PairedTag::removeTag()
{
	removeTag(tags.size() - 1);
}

void PairedTag::removeText()
{
	if (texts.size() > 0) texts.at(texts.size() - 1) = "";
	else text = "";
}

void PairedTag::removeTag(const unsigned int & index)
{
	if (index == 0) text += texts.at(0);
	else texts.at(index - 1) += texts.at(index);
	tags.erase(tags.begin() + index);
	texts.erase(texts.begin() + index);
}

void PairedTag::removeText(const unsigned int & index)
{
	if (index >= 0 && index < texts.size()) texts.at(index) = "";
	else text = "";
}

void PairedTag::clearTags()
{
	while (tags.size() > 0)
	{
		removeTag();
	}
}

void PairedTag::clear()
{
	clearTags();
	clearAttrs();
	removeText();
}

void PairedTag::updateTag(const Tag & tag, const unsigned int & index)
{
	tags.at(index) = tag;
}

void PairedTag::updateText(const char * str, const unsigned int & index)
{
	if (index >= 0 && index < texts.size()) texts.at(index) = str;
	else text = str;
}

unsigned int PairedTag::getSize() const
{
	return tags.size(); // or texts.size()
}

Tag & PairedTag::getTag(const unsigned int & index)
{
	return tags.at(index);
}

std::string PairedTag::getText() const
{
	return text;
}

std::string PairedTag::getText(const unsigned int & index) const
{
	return texts.at(index);
}

std::ostream & operator<<(std::ostream & output, const PairedTag & tag)
{
	//output << "*p*";
	tag.generateHtml(output);
	return output;
}
