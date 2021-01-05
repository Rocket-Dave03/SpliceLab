#include "MeshLoader.h"


typedef char byte;
ArrayList<std::string*>* MeshLoader::loadFile(std::filesystem::path filePath)
{
	// Open File
	std::ifstream file;
	file.open(std::filesystem::absolute(filePath), std::ios::binary);

	

	if (file)
	{
		ArrayList<std::string*>* list = new ArrayList<std::string*>();
		std::string str;
		while (std::getline(file, str))
		{
			list->append(new std::string(str.c_str()));
		}
		return list;

	}
	else
	{
		printf("Failed to load mesh file %ws\n", filePath.c_str());
		file.close();
		return nullptr;
	}

}



