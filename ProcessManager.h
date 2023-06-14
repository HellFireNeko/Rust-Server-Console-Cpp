#pragma once
#include <string>
#include <Windows.h>
#include <sstream>

class ProcessManager
{
public:
	static void Open(std::string applicationName, std::string args);
};

