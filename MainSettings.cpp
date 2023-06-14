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
			AutoRestart = j["auto restart"];
			Installed = j["installed"];
		}
		file.close();
	}
}

void MainSettings::SaveSettings()
{
	nlohmann::json j;
	j["auto restart"] = AutoRestart;
	j["installed"] = Installed;

	std::ofstream file(FilePath);
	file << j.dump(4) << std::endl;
	file.close();
}
