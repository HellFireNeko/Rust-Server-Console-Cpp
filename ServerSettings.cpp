#include "ServerSettings.h"

ServerSettings::ServerSettings() { }

ServerSettings::ServerSettings(nlohmann::json& j)
{
	Identity = j["identity"];
	IP = j["ip"];
	Port = j["port"];
	TickRate = j["tick rate"];
	HostName = j["host name"];
	Description = j["description"];
	MaxPlayers = j["max players"];
	SaveInterval = j["save interval"];
	WorldSize = j["world size"];
	Seed = j["seed"];
}

void ServerSettings::SaveSettings(nlohmann::json& j)
{
	j["identity"] = Identity;
	j["ip"] = IP;
	j["port"] = Port;
	j["tick rate"] = TickRate;
	j["host name"] = HostName;
	j["description"] = Description;
	j["max players"] = MaxPlayers;
	j["save interval"] = SaveInterval;
	j["world size"] = WorldSize;
	j["seed"] = Seed;
}

std::string ServerSettings::CreateServerArguments()
{
	std::stringstream ss;
	ss << "+server.ip " << IP << " +server.port " << Port << " +server.hostname \"" << HostName << "\" +server.description \"" << Description << "\" +server.maxplayers " << MaxPlayers << " +server.worldsize " << WorldSize << " +server.seed " << Seed << " +server.identity \"" << Identity << "\" +server.tickrate " << TickRate << " +server.saveinterval " << SaveInterval;
	return ss.str();
}