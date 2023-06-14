#include <iostream>
#include <Windows.h>
#include "ConsoleUtils.h"
#include "MainSettings.h"
#include "ServerObject.h"

MainSettings settings;
std::string AppDir = "";

const std::string SteamCmdDownloadLink = "https://steamcdn-a.akamaihd.net/client/installer/steamcmd.zip";
const std::string OxideDownloadLink = "https://umod.org/games/rust/download?tag=public";
const unsigned int RustDedicatedID = 258550;

int main()
{
	AppDir = _pgmptr;

	std::cout << "Welcome to the rust console" << std::endl;
	system("title Rust Manager Console");
}