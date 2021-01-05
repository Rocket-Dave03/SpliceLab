#include "MeshParser.h"




enum MeshParser::objElem MeshParser::ste(std::string s)
{
	if (s.size() < 1)
	{
		printf("String Length was less than 1");
		assert(s.size() < 1);
	}
	switch (s.c_str()[0])
	{
	case 'v':
		return MeshParser::objElem::vertex;
	case 'f':
		return MeshParser::objElem::face;
	default:
		return MeshParser::objElem::none;
	}
}
enum MeshParser::objElem MeshParser::parseLine(std::string line)
{
	MeshParser::getArgs(line);
	return MeshParser::ste(line);
}
void MeshParser::getArgs(std::string str)
{
	size_t sLen = str.find_first_of(' ', 0);
	str.erase(0, sLen);
	printf("%s\n", str.c_str());

}