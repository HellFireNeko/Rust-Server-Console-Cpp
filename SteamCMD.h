#pragma once
#include <string>
#include <filesystem>
#include <Windows.h>
#include "ProcessManager.h"

class SteamCMD
{
public:
	static void InstallOrUpdate(std::string steamCMDPath, unsigned int appid, bool validate);
};

