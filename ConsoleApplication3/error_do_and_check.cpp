#include <iostream>
#include <fstream>
#include <Windows.h>
#include "twj.h"
bool check() {
	if (mwando(1) == 1.250) {
		return true;
	}
	else{
		return false;
	}
};
void errorlog(int canshu) {
	std::ofstream errorlog("error.log", std::ofstream::out | std::ofstream::app); //���ش�����־
	if (!errorlog) {
		throw std::runtime_error("errorlog can not read or founnd new errorlog");
		std::cerr << "Tip:errorlog can not read or founnd new errorlog";
		
	}
	if (canshu == 2) {
		std::cerr << "�浵��ȡ���� ��������ΪȨ�޲���/û�н����κδ浵/�浵����";
		errorlog << "\nerror: Archive read errors It may be because of insufficient permissions/no archives were created/archives were corrupted��-2��";
		errorlog.close();
		Sleep(2000);
	}
	if (canshu == 3) {
		std::cerr << "�浵��������";
		errorlog << "\nArchive information is incorrect: Non-digital use(-3)";
		errorlog.close();
		Sleep(2000);
	}
	if (canshu == 4) {
		std::cerr << "δ֪����-4��";
		errorlog << "\nUnknow error(-4)";
		Sleep(2000);
	}
	errorlog.close();
};