#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "twj.h"
void load(char c) {
	if (c == 'o') {
		std::ofstream gameload("gamesave.sl", std::fstream::out);
		gameload << "World 1; Level 0; Life 5; Gold Coins 0; Star 0;";
		gameload.close();
		c = 'B';
	}
	if (c == 'b') {
		std::ifstream load("gamesave.sl", std::fstream::in);
		if (!load) {
			errorlog(2);
			throw std::runtime_error("");
		}
		std::string line;
		std::vector<std::string> loadfile;
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
		catch (const std::out_of_range) {
			errorlog(3);
			throw std::runtime_error("Non-digital use");

		}
		catch (...) {
			throw std::runtime_error("Unknow error(-4)");
		}
	}
}