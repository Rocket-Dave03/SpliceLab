#pragma once

#include <map>
#pragma once
#include <iterator> 

#include "../../../All.h"

namespace MeshParser
{
	enum class objElem
	{
		none,
		vertex,
		line,
		face,
	};


	objElem ste(std::string);
	void getArgs(std::string);
	objElem parseLine(std::string);
	
};
