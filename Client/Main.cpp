// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Globals.h"
#include "Utility.h"
#include "Memory.h"
#include "Overlay.h"
#include <iostream>
#include <time.h>
#include <Psapi.h>


HWND gameWindow = FindWindow(NULL, L"Rainbow Six");

//Defining our globals
namespace Global {
	HANDLE GameHandle = 0x0;
	int ID;
	LPVOID BaseAddress = NULL;

	std::string LocalName = "";

	Memoryyy Memory = Memoryyy();

	Overlayyy Over = Overlayyy();

	BOOL Aimbot = FALSE;
	
	BOOL Spread = FALSE;

	BOOL Recoil = FALSE;
}

static const char consoleNameAlphanum[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int consoleNameLength = sizeof(consoleNameAlphanum) - 1;

char genRandomConsoleName()
{
	return consoleNameAlphanum[rand() % consoleNameLength];
}

int main()
{
	srand(time(0));
	std::wstring ConsoleNameStr;
	for (unsigned int i = 0; i < 20; ++i)
	{
		ConsoleNameStr += genRandomConsoleName();

	}
	SetConsoleTitle(ConsoleNameStr.c_str());
	std::cout << "Siege External" << std::endl;
	std::cout << "-----" << std::endl;
	if (gameWindow != 0) {
		std::cout << "Game window found" << std::endl;

		std::cout << "Eneter your ingame name: " << std::flush;
		std::cin >> Global::LocalName;
		//Global::LocalName = "TheWiseR6Man";
		Sleep(1000);

		 
		std::string confirmation;

		//std::cout << "Confirm [Y]/[N]: " << std::flush;
		//std::cin >> confirmation;
		confirmation = "Y";
		if (confirmation == "Y") {
			Global::Memory.SetBaseAddress();

			Global::Over.SetupWindow();
			std::cout << "Overlay window set" << std::endl;

			//Start the main loop
			Global::Over.Loop();

			system("pause");
			return EXIT_SUCCESS;

			return 0;
		}
		else {
			std::cout << "Closing..." << std::endl;
			Sleep(2000);
		}
		return 0;
	}
	else {
		std::cout << "Game must be running to continue." << std::endl;
		std::cout << "" << std::endl;
		system("pause");
		return 0;
	}
}
