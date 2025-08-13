#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>
#include "twj.h"
int main() {
	try {
		userinput();
	}
	catch (...) {
		return -1;
	}
	/*
	std::string line;
	std::vector<std::string> loadfile;
	if (userInput == 'B' || userInput == 'b') {
		std::ifstream load("gamesave.sl", std::fstream::in);
		if (!load) {
			std::cerr << "存档读取错误 可能是因为权限不足/没有建立任何存档/存档被损坏";
			errorlog << "\nerror: Archive read errors It may be because of insufficient permissions/no archives were created/archives were corrupted（-2）";
			errorlog.close();
			Sleep(2000);
			return -2;
		}
		while (std::getline(load, line)) {
			loadfile.emplace_back(line);

		}
		load.close();
		int World;
		int Level;
		int Life;
		int Gold_Coins;
		int Star;
		try {

			char aWorld = loadfile.at(0)[6];
			char aLevel = loadfile.at(0)[15];
			char aLife = loadfile.at(0)[23];
			char aGold_Coins = loadfile.at(0)[37];
			char aStar = loadfile.at(0)[45];
			std::string bWorld = std::string(1, aWorld);
			std::string bLevel = std::string(1, aLevel);
			std::string bLife = std::string(1, aLife);
			std::string bGold_Coins = std::string(1, aGold_Coins);
			std::string bStar = std::string(1, aGold_Coins);
			World = std::stoi(bWorld);
			Level = std::stoi(bLevel);
			Life = std::stoi(bLife);
			Gold_Coins = std::stoi(bGold_Coins);
			Star = std::stoi(bStar);
		}
		catch(const std::out_of_range& error) {
			std::cerr << "存档数据有误";
			errorlog << "\nArchive information is incorrect: Non-digital use(-3)";
			errorlog.close();
			Sleep(2000);
			return -3;

		}
		catch (...) {
			std::cerr << "未知错误（-4）";
			errorlog << "\nUnknow error(-4)";
			Sleep(2000);
			return -4;
		}
	}
	*/
	return 0;
}