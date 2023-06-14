#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <nlohmann/json.hpp>

class ServerSettings
{
public:
	std::string Identity = "Server 1";
	std::string IP = "0.0.0.0";
	int Port = 28015;
	int TickRate = 30;
	std::string HostName = "My Server";
	std::string Description = "My awesome server";
	int MaxPlayers = 10;
	int SaveInterval = 600;
	int WorldSize = 3000;
	int Seed = 0;

	ServerSettings();
	ServerSettings(nlohmann::json& j);
	void SaveSettings(nlohmann::json& j);
	std::string CreateServerArguments();
};

