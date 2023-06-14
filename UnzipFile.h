#pragma once
#include <string>
#include <sstream>
#include <filesystem>

class UnzipFile
{
public:
	static void Unzip(std::string file, std::string targetDir);
};

