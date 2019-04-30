#pragma once
#include <list>
#include <iterator>
#include <map>
#include <string.h>
class Tag
{
	std::map<std::string, std::string> attributes;
	std::string text;
	std::list<Tag> tags;
	std::list<std::string> texts;
public:
	Tag();
	~Tag();

	void addTag(const Tag & tag);
	void addText(const char* str);
	void addTag(const Tag & tag, const unsigned int & index);
	void addText(const char* str, const unsigned int & index);
	void removeTag();
	void removeText();
	void removeTag(const unsigned int & index);
	void removeText(const unsigned int & index);
	Tag & getTag(const unsigned int & index);
	std::string getText(const unsigned int & index);

	friend std::ostream & operator<<(std::ostream & output, const Tag & tag);
};

