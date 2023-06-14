#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "ConsoleUtils.h"
#include "MainSettings.h"
#include "ServerObject.h"
#include "WebDownloader.h"
#include "UnzipFile.h"
#include "SteamCMD.h"

MainSettings settings;

const std::string SteamCmdDownloadLink = "https://steamcdn-a.akamaihd.net/client/installer/steamcmd.zip";
const unsigned int RustDedicatedID = 258550;

const std::string SteamCMDPath = "SteamCMD\\steamcmd.exe";
const std::string RustDedicatedPath = "SteamCMD\\steamapps\\common\\rust_dedicated\\RustDedicated.exe";

void ErrorCheck(bool value, std::string message, bool doNotThrow)
{
	if (value) return;
	std::cout << "An error has occured." << std::endl
		<< "Msg: " << message << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	if (doNotThrow == false)
	{
		throw EXCEPTION_NONCONTINUABLE;
	}
}

void AutomaticSetupSequence()
{
	bool mkDirCheck = std::filesystem::create_directory("SteamCMD");
	ErrorCheck(mkDirCheck, "Unable to create directory.", false);

	std::cout << "Downloading SteamCMD..." << std::endl;
	bool scdDownRes = WebDownloader::DownloadFile(SteamCmdDownloadLink, "SteamCMD\\SteamCMD.zip");
	ErrorCheck(scdDownRes, "Steam cmd failed to download propperly", false);

	std::cout << "Unzipping SteamCMD..." << std::endl;
	UnzipFile::Unzip("SteamCMD\\SteamCMD.zip", "SteamCMD");

	std::cout << "Validating SteamCmd install..." << std::endl;
	bool scdFSRes = std::filesystem::exists(SteamCMDPath);
	ErrorCheck(scdFSRes, "Extracted files are invalid", true);

	std::cout << "SteamCMD Successfully installed." << std::endl
		      << "Installing Rust Dedicated now." << std::endl;

	SteamCMD::InstallOrUpdate(SteamCMDPath, RustDedicatedID, true);

	std::cout << "Validating Rust Dedicated Install..." << std::endl;
	bool rsdFSRes = std::filesystem::exists(RustDedicatedPath);
	ErrorCheck(rsdFSRes, "Rust dedicated failed to install", false);

	std::cout << "Rust Dedicated Sucessfully installed." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "Cleaning up..." << std::endl;
	std::remove("SteamCMD\\SteamCMD.zip");
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void FirstTimeSetup()
{
	std::cout << "Starting setup sequence!" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));

	AutomaticSetupSequence();

	settings.Installed = true;
	settings.AutoRestart = false;
	settings.SaveSettings();
}

void StartServer(ServerObject server)
{
	std::cout << "Starting " << server.Server.Identity << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(300));
	ConsoleUtils::Clear();

	SetConsoleTitle(L"Rust Server Running");
	
	bool firstStart = true;

	if (settings.AutoRestart)
	{
		std::cout << "Warning, using autorestart can lead to the rust dedicated process to not exit if you close this app. When you close, make sure you check taskmanager." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		ConsoleUtils::Clear();
	}

	while (settings.AutoRestart || firstStart)
	{
		std::cout << "Running command: " << RustDedicatedPath << " " << server.CreateProcessArguments() << std::endl;
		ProcessManager::Open(RustDedicatedPath, server.CreateProcessArguments());

		firstStart = false;

		if (settings.AutoRestart)
		{
			std::cout << "Restarting the server in 10 seconds..." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(10));
		}
	}
}

int main()
{
	std::cout << "Welcome to the rust console" << std::endl;
	SetConsoleTitle(L"Rust Manager Console");

	if (settings.Installed == false)
	{
		// Start first time setup:
		FirstTimeSetup();
	}
	else
	{
		bool validate = ConsoleUtils::PromptYN("Do you want to validate the files? y/n", true);
		SteamCMD::InstallOrUpdate(SteamCMDPath, RustDedicatedID, validate);
	}

	ServerObject server;
	if (std::filesystem::exists("Server.json"))
	{
		std::ifstream file;
		file.open("Server.json");
		if (file.is_open())
		{
			nlohmann::json j = nlohmann::json::parse(file);
			server = ServerObject(j);
		}
	}
	else
	{
		server = ServerObject::CreateNewServer();
		nlohmann::json j;
		server.SaveSettings(j);

		std::ofstream file("Server.json");
		file << j.dump(4) << std::endl;
		file.close();
	}

	StartServer(server);
}
