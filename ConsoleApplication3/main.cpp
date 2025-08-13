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
	return 0;
}
