#pragma once
#include <string>
#include <fstream>
#include <filesystem>
#include <nlohmann/json.hpp>

class MainSettings
{
public:
	std::string RustDedicatedPath = "";
	std::string SteamCMDPath = "";
	bool AutoOxide = false;
	bool AutoRestart = false;
	bool ManuallyInstalled = false;

	MainSettings();
	void SaveSettings();

private:
	const std::string FilePath = "Settings.json";
};

