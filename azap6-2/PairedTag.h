#pragma once
#include "Tag.h"
class PairedTag :
	public Tag
{
	std::string text;
	std::vector<Tag> tags;
	std::vector<std::string> texts;
public:
	PairedTag(std::string tag_name);
	~PairedTag();

	void addTag(const Tag & tag);
	void addText(const char* str);
	void insertTag(const Tag & tag, const unsigned int & index);
	void insertText(const char* str, const unsigned int & index);
	void removeTag();
	void removeText();
	void removeTag(const unsigned int & index);
	void removeText(const unsigned int & index);
	void clearTags();
	void clear();
	void updateTag(const Tag & tag, const unsigned int & index);
	void updateText(const char* str, const unsigned int & index);

	unsigned int getSize() const;
	Tag & getTag(const unsigned int & index);
	std::string getText() const;
	std::string getText(const unsigned int & index) const;
};
