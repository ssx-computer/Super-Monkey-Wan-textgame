#include <iostream>
#include "twj.h"
//提取monkey 万的火焰技能是否被篡改
bool XY() {
	if (mwando(1) == 1.250)
		return 1;
	else
		return 0;
};	