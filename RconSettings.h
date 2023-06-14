#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <nlohmann/json.hpp>

class RconSettings
{
public:
	std::string Password = "letmein";
	bool Web1 = true;
	std::string IP = "0.0.0.0";
	int Port = 28016;

	RconSettings();
	RconSettings(nlohmann::json& j);
	void SaveSettings(nlohmann::json& j);
	std::string CreateRconArguments();
};

