#include <iostream>
#include <Windows.h>
#include <string>
#include "twj.h"
void userinput() {
	errorlog(0); //���ش�����־
	std::cout << "Super Monkey Wan��Game\n";
	std::cout << "����L��ʼ��Ϸ\n";
	char userInput;   //userInput����һ�е��û���������
	std::cin >> userInput;
	if (userInput == 'L' || userInput == 'l') {
		std::cout << "����Ч����...Loading";
		if (!check()) {
			std::cerr << "�������Ʊ��۸ģ������°�װ";
			Sleep(2000);
			throw std::runtime_error("database_is_not_true");
		}
		userInput = ' ';
	}
	else {
		throw std::runtime_error("User Exit");
	}
	std::cout << "����Ч�����\n";
	std::cout << "��ʼ����Ϸ(A)���Ǽ�����Ϸ(B)��\n";
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
	std::cout << "��ӭ����SuperMonkeyWAN�����磡";
}