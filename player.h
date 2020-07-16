#ifndef PLAYER_H
#define PLAYER_H
#include "characters.h"


class player:public characters
{
public:
	player();
	 void fight(char x);
	 bool isdead();
	 void enhance_power();
	 void enhance_health();
	 void bomb();
	 void status();
protected:
	string pName;
	 int pdamage;
	 int pheart;
	 int ppower;
	string psword;

};
#endif // !PLAYER_H
#pragma once
