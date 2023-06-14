#include "ServerObject.h"

ServerObject::ServerObject(nlohmann::json& j)
{
	Server = ServerSettings(j["server"]);
	Rcon = RconSettings(j["rcon"]);
	LogFile = j["log file"];
	SilentCrashes = j["silent crashes"];
}

ServerObject::ServerObject(ServerSettings server, RconSettings rcon)
{
	Server = server;
	Rcon = rcon;
}

void ServerObject::SaveSettings(nlohmann::json& j)
{
	nlohmann::json s;
	Server.SaveSettings(s);
	j["server"] = s;
	nlohmann::json r;
	Rcon.SaveSettings(r);
	j["rcon"] = r;
	j["log file"] = LogFile;
	j["silent crashes"] = SilentCrashes;
}

std::string ServerObject::CreateProcessArguments()
{
	std::stringstream ss;
	ss << "-batchmode " << Server.CreateServerArguments() << " " << Rcon.CreateRconArguments() << " -logfile \"" << LogFile << "\"";
	if (SilentCrashes)
	{
		ss << " -silent-crashes";
	}
	return ss.str();
}

ServerObject ServerObject::CreateNewServer()
{
	ConsoleUtils::Clear();
	std::cout << "Server Side Settings:" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));

	ServerSettings server;
	RconSettings rcon;
	
	server.Identity = ConsoleUtils::PromptString("Server Identity", 1);
	server.Port = ConsoleUtils::PromptInt("Server Port", true);
	server.HostName = ConsoleUtils::PromptString("Server Hostname", 3);
	server.Description = ConsoleUtils::PromptString("Server Description", 0);
	server.MaxPlayers = ConsoleUtils::PromptInt("Server Max Players", true);
	server.WorldSize = ConsoleUtils::PromptIntRange("Server World Size (3000 - 6000)", 3000, 6000);
	if (ConsoleUtils::PromptYN("Generate random seed? y/n"))
	{
		server.Seed = rand() % 1000000 + 1;
	}
	else
	{
		server.Seed = ConsoleUtils::PromptInt("Server Seed", true);
	}

	ConsoleUtils::Clear();
	std::cout << "Server Side Settings Complete" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(300));

	ConsoleUtils::Clear();
	std::cout << "Rcon Settings:" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));

	rcon.Port = ConsoleUtils::PromptInt("Rcon Port", true);
	rcon.Web1 = ConsoleUtils::PromptYN("Rcon Web1? y/n");
	rcon.Password = ConsoleUtils::PromptString("Rcon Password", 0);

	ConsoleUtils::Clear();
	std::cout << "Rcon Settings Complete" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(300));

	return ServerObject(server, rcon);
}