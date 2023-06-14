#pragma once
#include <string>
#include <fstream>
#include <filesystem>
#include <nlohmann/json.hpp>

class MainSettings
{
public:
	bool Installed = false;
	bool AutoRestart = false;

	MainSettings();
	void SaveSettings();

private:
	const std::string FilePath = "Settings.json";
};

