#pragma once
#include <vector>
#include <iterator>
#include <map>
#include <string.h>
class Tag
{
	std::map<std::string, std::string> attributes;
	std::string text;
	std::vector<Tag> tags;
	std::vector<std::string> texts;
public:
	Tag();
	~Tag();

	void addTag(const Tag & tag);
	void addText(const char* str);
	void insertTag(const Tag & tag, const unsigned int & index);
	void insertText(const char* str, const unsigned int & index);
	void removeTag();
	void removeText();
	void removeTag(const unsigned int & index);
	void removeText(const unsigned int & index);
	Tag & getTag(const unsigned int & index);
	std::string getText(const unsigned int & index);

	friend std::ostream & operator<<(std::ostream & output, const Tag & tag);
};

