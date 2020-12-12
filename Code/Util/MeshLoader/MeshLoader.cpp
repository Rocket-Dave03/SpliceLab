#include "MeshLoader.h"


typedef char byte;
List<byte>* MeshLoader::loadFile(const char* filePath)
{
	// Open File
	std::ifstream file;
	file.open(filePath, std::ios::binary);

	

	if (file)
	{
		byte* buffer = nullptr;
		// get length of file:
		file.seekg(0, file.end);
		long long length = file.tellg();
		file.seekg(0, file.beg);

		// Allocate buffer
		buffer = new byte[length+1];

		printf("Reading %lld characters... \n", length);
		// read data to buffer:
		file.read(buffer, length);
		// add null terminator
		buffer[length - 1] = 0;

		printf("%s\n", buffer);
		printf("Read Done\n");

		List<byte>* list = new List<byte>(buffer, length);
		delete[] buffer;
		file.close();
		return list;

	}
	else
	{
		printf("Failed to load mesh file %s\n", filePath);
		file.close();
		return nullptr;
	}

}

ArrayList<List<byte>*>* MeshLoader::splitAtByte(List<byte>* buffer, byte val)
{
	ArrayList<List<byte>*>* out = new ArrayList<List<byte>*>();
	for (int i = 0; i < buffer->length;i++)
	{
		if ( (*buffer)[i] == val )
		{
			/* TODO: Make this actualy work/ Thias currently dose nothing */
			out->append(buffer->split(i));
		}
	}
	return out;
}







// Mesh Class
using namespace MeshLoader;

Mesh::Mesh(const char* filePath)
{
	// Load file
	rawFile = loadFile(filePath);

	if (rawFile != nullptr)
	{
		// Parse File
		ArrayList<List<byte>*>* lines = MeshLoader::splitAtByte(rawFile, 10);
		printf("%s\n", lines->get(0)->getRaw());

	}
}


Mesh::~Mesh()
{
	delete rawFile;
}