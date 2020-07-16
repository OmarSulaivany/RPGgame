#ifndef SOLDIER_H
#define SOLDIER_H
#include "characters.h"

class soldier :public characters
{
public:
	soldier();
	bool isdead();
	

	string sName;
	 int sdamage;
     int sheart;
	string ssword;
};

#endif // !SOLDIER_H
#pragma once
