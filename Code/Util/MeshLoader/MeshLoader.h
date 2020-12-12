#pragma once
#include "../../IO.h"
#include "../../All.h"


typedef char byte;
namespace MeshLoader
{
	List<byte>* loadFile(const char*);
	ArrayList<List<byte>*>* splitAtByte(List<byte>*, byte);

	class Mesh
	{
	public:
		List<byte>* rawFile;

		Mesh(const char*);
		~Mesh();
	};
};