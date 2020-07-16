#ifndef KING_H
#define KING_H
#include "characters.h"

class king :public characters
{
public:
	king();
	bool isdead();


	string kName;
	int kdamage;
	int kheart;
	string ksword;
};

#endif // !KING_H
#pragma once
