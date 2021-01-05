#pragma once

#include "MeshLoader/MeshLoader.h"
#include "MeshParser/MeshParser.h"

#include "../../IO.h"
#include "../../All.h"


class Mesh
{
private:

public:
	ArrayList<std::string*>* rawFile;

	Mesh(std::filesystem::path);
	~Mesh();
};