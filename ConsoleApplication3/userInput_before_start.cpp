#include <iostream>
#include <Windows.h>
#include <string>
#include "twj.h"
void userinput() {
	errorlog(0); //挂载错误日志
	std::cout << "Super Monkey Wan！Game\n";
	std::cout << "输入L开始游戏\n";
	char userInput;   //userInput接受一切的用户输入内容
	std::cin >> userInput;
	if (userInput == 'L' || userInput == 'l') {
		std::cout << "数据效验中...Loading";
		if (!check()) {
			std::cerr << "数据疑似被篡改，请重新安装";
			Sleep(2000);
			throw std::runtime_error("database_is_not_true");
		}
		userInput = ' ';
	}
	else {
		throw std::runtime_error("User Exit");
	}
	std::cout << "数据效验完成\n";
	std::cout << "开始新游戏(A)还是继续游戏(B)？\n";
	std::cin >> userInput;
	try {
		if (userInput == 'a' || userInput== 'A') {
			load('o');
			userInput = 'B';
		}
		if (userInput == 'b' || userInput ==  'B') {
			load('b');
		}
	}
	catch (...) {
		throw std::runtime_error("");
	}
	std::cout << "欢迎进入SuperMonkeyWAN的世界！";
}