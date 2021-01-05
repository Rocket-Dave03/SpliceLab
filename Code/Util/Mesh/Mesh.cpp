#include "Mesh.h"

Mesh::Mesh(std::filesystem::path filePath)
{
	printf("\nAtempting to Load MeshFile: %ws\n", filePath.filename().c_str());
	// Load file
	rawFile = MeshLoader::loadFile(filePath);

	if (rawFile != nullptr)
	{
		for (int i = 0; i < rawFile->size(); i++)
		{
			std::string line = *(*rawFile)[i];
			printf("[%d]	[%lld]	|%s\n", i, (long long)MeshParser::parseLine(line), line.c_str());
		}
		printf("File loaded successfully\n\n");
	}
	else
	{
		printf("\n======\nFailed to load file %ws\n======\n", filePath.filename().c_str());
	}
}
Mesh::~Mesh()
{
	delete rawFile;
}