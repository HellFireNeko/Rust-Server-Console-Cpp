#include "UnzipFile.h"

void UnzipFile::Unzip(std::string file)
{
	std::stringstream ss;
	ss << "tar -xf " << file;
	system(ss.str().c_str());
}