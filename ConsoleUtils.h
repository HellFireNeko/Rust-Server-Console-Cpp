#pragma once
#include <string>
#include <vector>
#include <iostream>

class ConsoleUtils
{
public:
	static std::string PromptString(std::string prompt, int minLen, bool clearConsole);
	static int PromptInt(std::string prompt, bool notNegative, bool clearConsole);
	static int PromptIntRange(std::string prompt, int min, int max, bool clearConsole);
	static bool PromptYN(std::string prompt, bool clearConsole);
	static int CreateMenu(std::string title, std::vector<std::string> options, bool clearConsole);
	static void Clear();
};

