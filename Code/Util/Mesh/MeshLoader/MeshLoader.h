#pragma once
#include "../../../IO.h"
#include "../../../All.h"



typedef char byte;
namespace MeshLoader
{
	ArrayList<std::string*>* loadFile(std::filesystem::path);
	ArrayList<List<byte>*>* splitAtByte(List<byte>*, byte);

};
