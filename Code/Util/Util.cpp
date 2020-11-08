#include "Util.h"

std::string strCat(const char* a, const char* b)
{
	return ((std::string)a).append((std::string)b);
}

void checkError(int line)
{
	printf( strCat( "[%i] Error:\n", SDL_GetError() ).c_str(), line );

	SDL_ClearError();
}

