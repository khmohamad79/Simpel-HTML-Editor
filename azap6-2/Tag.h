#pragma once
#include <vector>
#include <iterator>
#include <map>
#include <string>
class Tag
{
protected:
	std::string name;
	std::map<std::string, std::string> attributes;
	virtual void generateHtml(std::ostream & output) const = 0;
public:
	Tag(std::string tag_name);
	~Tag();

	void addAttr(const char* str_name, const char* str_value);
	void removeAttr(const char* str_name);
	void clearAttrs();
	void updateAttr(const char* str_name, const char* str_value);
	
	std::string getName() const;
	std::string getAttrVal(const char* str_name) const;

	friend std::ostream & operator<<(std::ostream & output, const Tag & tag);
};

