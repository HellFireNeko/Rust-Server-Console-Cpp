#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <nlohmann/json.hpp>
#include <thread>
#include <chrono>
#include <ctime>
#include "ConsoleUtils.h"
#include "ServerSettings.h"
#include "RconSettings.h"

class ServerObject
{
public:
	ServerSettings Server;
	RconSettings Rcon;
	std::string LogFile = "gameLog.txt";
	bool SilentCrashes = false;

	ServerObject() { }
	ServerObject(nlohmann::json& j);
	ServerObject(ServerSettings server, RconSettings rcon);
	void SaveSettings(nlohmann::json& j);
	std::string CreateProcessArguments();
	static ServerObject CreateNewServer();
};

