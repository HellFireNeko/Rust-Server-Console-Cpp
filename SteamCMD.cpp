#include "SteamCMD.h"

void SteamCMD::InstallOrUpdate(std::string steamCMDPath, unsigned int appid, bool validate)
{

	std::filesystem::path filePath = std::filesystem::path(steamCMDPath);
	if (filePath.is_absolute() == false)
	{
		filePath = std::filesystem::absolute(filePath);
	}
	std::stringstream ss;
	ss << "+login anonymous +app_update " << appid;
	if (validate)
	{
		ss << " validate";
	}
	ss << " +quit";
	ProcessManager::Open(filePath.string(), ss.str());
}