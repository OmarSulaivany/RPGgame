#ifndef CHAEACTERS_H
#define CHARACTERS_H
#include <string>
using namespace std;
class characters
{
public:
	characters();
	 virtual bool isdead();

protected:

	string mName;
	 int mdamage;
	 int mheart;
	 int mpower;
	string msword;
};

#endif // !CHAEACTERS_H
#pragma once
