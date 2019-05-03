#pragma once
#include "Tag.h"
class PairedTag :
	public Tag
{
	std::string text;
	std::vector<Tag*> tags;
	std::vector<std::string> texts;
protected:
	virtual void generateHtml(std::ostream & output) const;
public:
	PairedTag(std::string tag_name);
	~PairedTag();

	void addTag(Tag * tag);
	void addText(const char* str);
	void insertTag(Tag * tag, const unsigned int & index);
	void addText(const char* str, const unsigned int & index);
	void removeTag();
	void removeText();
	void removeTag(const unsigned int & index);
	void removeText(const unsigned int & index);
	void clearTags();
	void clear();
	void updateTag(Tag * tag, const unsigned int & index);
	void updateText(const char* str);
	void updateText(const char* str, const unsigned int & index);

	unsigned int getSize() const;
	Tag * getTag(const unsigned int & index);
	std::string getText() const;
	std::string getText(const unsigned int & index) const;

	friend std::ostream & operator<<(std::ostream & output, const PairedTag & tag);
};

