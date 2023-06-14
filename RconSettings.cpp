#include "RconSettings.h"

RconSettings::RconSettings() { }

RconSettings::RconSettings(nlohmann::json& j)
{
	Password = j["password"];
	Web1 = j["web1"];
	IP = j["ip"];
	Port = j["port"];
}

void RconSettings::SaveSettings(nlohmann::json& j)
{
	j["password"] = Password;
	j["web1"] = Web1;
	j["ip"] = IP;
	j["port"] = Port;
}

std::string RconSettings::CreateRconArguments()
{
	std::stringstream ss;
	ss << "+rcon.ip " << IP << " +rcon.port " << Port << " +rcon.password \"" << Password << "\"";
	if (Web1) {
		ss << " +rcon.web1";
	}
	return ss.str();
}