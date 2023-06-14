#include "ProcessManager.h"

void ProcessManager::Open(std::string applicationName, std::string args)
{
	std::stringstream ss;
	ss << applicationName << " " << args;
	system(ss.str().c_str());
}