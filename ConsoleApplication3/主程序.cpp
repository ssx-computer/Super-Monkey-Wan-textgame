#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>
#include "twj.h"
int main() {
	std::ofstream errorlog("error.log", std::ofstream::out | std::ofstream::app); //挂载错误日志
	std::cout << "Super Monkey Wan！Game\n";
	std::cout << "输入L开始游戏\n";
	char userInput;   //userInput接受一切的用户输入内容
	std::cin >> userInput;
	//效验数据 用数据库抽取法检查
	if (userInput == 'L' || userInput == 'l') {
		std::cout << "数据效验中...Loading";
		if (!XY()) {
			std::cerr << "数据疑似被篡改，请重新安装";
			Sleep(2000);
			return -1;
		}
		userInput = ' ';
	}
	else {
		return -1;
	}
	std::cout << "数据效验完成\n";
	std::cout << "开始新游戏(A)还是继续游戏(B)？\n";
	std::cin >> userInput;
	if (userInput == 'A' || userInput == 'a') {
		std::ofstream gameload("gamesave.sl");
		gameload << "World 1; Level 0; Life 5; Gold Coins 0; Star 0;";
		gameload.close();
		userInput = 'B';
	}
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

	std::cout << "欢迎进入SuperMonkeyWAN的世界！";

	errorlog.close();//关闭挂载错误日志
}