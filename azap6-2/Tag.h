#pragma once
#include <vector>
#include <iterator>
#include <map>
#include <string.h>
class Tag
{
	std::string name;
	std::map<std::string, std::string> attributes;
	std::string text;
	std::vector<Tag> tags;
	std::vector<std::string> texts;
public:
	Tag(std::string tag_name);
	~Tag();

	void addTag(const Tag & tag);
	void addText(const char* str);
	void addAttr(const char* str_name, const char* str_value);
	void insertTag(const Tag & tag, const unsigned int & index);
	void insertText(const char* str, const unsigned int & index);
	void removeTag();
	void removeText();
	void removeTag(const unsigned int & index);
	void removeText(const unsigned int & index);
	void removeAttr(const char* str_name);
	void clearTags();
	void clearAttrs();
	void clear();
	void updateTag(const Tag & tag, const unsigned int & index);
	void updateText(const char* str, const unsigned int & index);
	void updateAttr(const char* str_name, const char* str_value);
	
	unsigned int getSize() const;
	Tag & getTag(const unsigned int & index);
	std::string getName() const;
	std::string getText() const;
	std::string getText(const unsigned int & index) const;
	std::string getAttrVal(const char* str_name) const;

	friend std::ostream & operator<<(std::ostream & output, const Tag & tag_);
};

