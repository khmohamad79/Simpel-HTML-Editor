#pragma once
#include "Tag.h"
class SingleTag :
	public Tag
{
protected:
	virtual void generateHtml(std::ostream & output) const;
public:
	SingleTag(std::string tag_name);
	~SingleTag();

	friend std::ostream & operator<<(std::ostream & output, const SingleTag & tag);
};

