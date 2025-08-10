#include <iostream>
struct story {

};
struct monkeyWando {
	double fire = 1.250;
	double hard = 0.785;
	double head = 0.886;
};
monkeyWando wando;
double mwando(int wdoit) { 
	if (wdoit == 1) {
		return wando.fire;
	}
	if (wdoit == 2) {
		return wando.hard;
	}
	if (wdoit == 3) {
		return wando.head;
	}
};