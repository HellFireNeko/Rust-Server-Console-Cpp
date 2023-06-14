#include "UnzipFile.h"

void UnzipFile::Unzip(std::string file, std::string targetDir)
{
	std::filesystem::path filePath = std::filesystem::path(file);
	if (filePath.is_absolute() == false)
	{
		filePath = std::filesystem::absolute(filePath);
	}

	std::filesystem::path target = std::filesystem::path(targetDir);
	if (target.is_absolute() == false)
	{
		target = std::filesystem::absolute(target);
	}

	std::stringstream ss;
	ss << "tar -xf " << filePath.string() << " -C \"" << target.string() << "\"";
	system(ss.str().c_str());
}