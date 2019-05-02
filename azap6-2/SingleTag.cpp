#include "SingleTag.h"



void SingleTag::generateHtml(std::ostream & output) const
{
	output << "<" << name;
	for (auto it = attributes.cbegin(); it != attributes.cend(); ++it)
	{
		output << " " << it->first << "=\"" << it->second << "\"";
	}
	output << "/>";
}

SingleTag::SingleTag(std::string tag_name) :
	Tag(tag_name)
{
	name = tag_name;
}


SingleTag::~SingleTag()
{
}

std::ostream & operator<<(std::ostream & output, const SingleTag & tag)
{
	//output << "*s*";
	tag.generateHtml(output);
	return output;
}
