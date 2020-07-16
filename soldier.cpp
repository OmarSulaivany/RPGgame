#include "soldier.h"
#include <iostream>
#include <string>
using namespace std;

soldier::soldier() :sName("Soldier"), sdamage(mdamage), sheart(mheart), ssword(msword)
{}

bool soldier::isdead()
{
	if (this->sheart <= 0)
		return true;
	else
		return false;
}