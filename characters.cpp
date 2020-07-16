#include "characters.h"
#include<iostream>
#include <string>
using namespace std;



characters::characters()
{
	this->mName = "Default name";
	this->mpower = 50;
	this->mheart = 50;
	this->mdamage = 0;
	this->msword = "Level1";
}

bool characters::isdead()
{
	return false;
}
