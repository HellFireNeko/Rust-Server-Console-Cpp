#include "MainSettings.h"

MainSettings::MainSettings()
{
	if (std::filesystem::exists(FilePath))
	{
		std::ifstream file;
		file.open(FilePath);
		if (file.is_open())
		{
			nlohmann::json j = nlohmann::json::parse(file);
			RustDedicatedPath = j["rust dedicated path"];
			SteamCMDPath = j["steam cmd path"];
			AutoOxide = j["auto oxide"];
			AutoRestart = j["auto restart"];
			ManuallyInstalled = j["manually installed"];
		}
		file.close();
	}
}

void MainSettings::SaveSettings()
{
	nlohmann::json j;
	j["rust dedicated path"] = RustDedicatedPath;
	j["steam cmd path"] = SteamCMDPath;
	j["auto oxide"] = AutoOxide;
	j["auto restart"] = AutoRestart;
	j["manually installed"] = ManuallyInstalled;

	std::ofstream file(FilePath);
	file << j.dump(4) << std::endl;
	file.close();
}
