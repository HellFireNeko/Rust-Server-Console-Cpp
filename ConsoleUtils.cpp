#include "ConsoleUtils.h"

std::string ConsoleUtils::PromptString(std::string prompt, int minLen, bool clearConsole)
{
	std::string val;
	if (clearConsole)
	{
		Clear();
	}
	std::cout << prompt << std::endl;
	std::cin >> val;
	return val;
}

int ConsoleUtils::PromptInt(std::string prompt, bool notNegative, bool clearConsole)
{
	int val;
	while (true)
	{
		if (clearConsole)
		{
			Clear();
		}
		std::cout << prompt << std::endl;
		std::cin >> val;
		if (notNegative)
		{
			if (val >= 0)
			{
				return val;
			}
		}
		else
		{
			return val;
		}
	}
}

int ConsoleUtils::PromptIntRange(std::string prompt, int min, int max, bool clearConsole)
{
	int val;
	while (true)
	{
		if (clearConsole)
		{
			Clear();
		}
		std::cout << prompt << std::endl;
		std::cin >> val;
		if (val >= min && val <= max)
		{
			return val;
		}
	}
}

bool ConsoleUtils::PromptYN(std::string prompt, bool clearConsole)
{
	std::string val;
	while (true)
	{
		if (clearConsole)
		{
			Clear();
		}
		std::cout << prompt << std::endl;
		std::cin >> val;
		if (val == "y" || val == "Y" || val == "Yes" || val == "yes")
		{
			return true;
		}
		else if (val == "n" || val == "N" || val == "No" || val == "no")
		{
			return false;
		}
	}
}

int ConsoleUtils::CreateMenu(std::string title, std::vector<std::string> options, bool clearConsole)
{
	int maxInt = options.size();
	int selectedInt;
	while (true)
	{
		if (clearConsole)
		{
			Clear();
		}
		std::cout << title << std::endl;
		for (int i = 0; i < maxInt; i++)
		{
			std::cout << i + 1 << ". " << options[i] << std::endl;
		}
		std::cin >> selectedInt;
		if (selectedInt - 1 < maxInt && selectedInt - 1 >= 0)
		{
			return selectedInt - 1;
		}
	}
}

void ConsoleUtils::Clear()
{
	system("cls");
}