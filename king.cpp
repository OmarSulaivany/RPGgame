#include "king.h"
#include <iostream>
#include <string>
using namespace std;

king::king() :kName("King"), kdamage(mdamage), kheart(mheart), ksword(msword)
{}

bool king::isdead()
{
	if (this->kheart <= 0)
		return true;
	else
		return false;
}