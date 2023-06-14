#pragma once
#include <string>
#include <vector>
#include <iostream>

class ConsoleUtils
{
public:
	static std::string PromptString(std::string prompt, int minLen = 1, bool clearConsole = true);
	static int PromptInt(std::string prompt, bool notNegative = false, bool clearConsole = true);
	static int PromptIntRange(std::string prompt, int min, int max, bool clearConsole = true);
	static bool PromptYN(std::string prompt, bool clearConsole = true);
	static int CreateMenu(std::string title, std::vector<std::string> options, bool clearConsole = true);
	static void Clear();
};

