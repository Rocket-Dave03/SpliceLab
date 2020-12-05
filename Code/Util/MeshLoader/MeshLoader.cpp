#include "MeshLoader.h"
#include "../../All.h"
#include "../../IO.h"


// Load Obj file as Mesh
MeshLoader::Mesh::Mesh(const char* filePath)
{
	std::ifstream file;
	file.open(filePath, std::ios::binary);

	if (file)
	{
		// get length of file:
		file.seekg(0, file.end);
		long long length = file.tellg() + (long long)1;
		file.seekg(0, file.beg);

		char* buffer = new char[length];

		printf("Reading %lld characters... \n",length);
		// read data as a block:
		file.read(buffer, length);
		// add null terminator
		buffer[length -1] = 0;

		printf("%s\n",buffer);
		printf("Read Done\n");
	}
	
	
	


	file.close();
}

MeshLoader::Mesh::~Mesh()
{
}
