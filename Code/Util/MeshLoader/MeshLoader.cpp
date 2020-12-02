#include "MeshLoader.h"
#include <iostream>
#include <fstream>


// Load Obj file as Mesh
MeshLoader::Mesh::Mesh(const char* filePath)
{
	std::ifstream file;
	file.open(filePath, std::ios::binary);

	char* buff = new char[10];
	file.read(buff, sizeof(char)* 9);
	printf("%s\n", buff);



	file.close();
}

MeshLoader::Mesh::~Mesh()
{
}
