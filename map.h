#ifndef MAP_H
#define MAP_N
#include "player.h"
#include "soldier.h"
class map
{
public:

	map(int x,int y, char di,unsigned int hlen, unsigned int wlen);
	~map();
	char** level_map();
	char action(map m, player p, characters* p1, unsigned int movement,char x);
	void print(player p);
	
private:
	int mx, my;
	char mp;
	char** m_e_map;
	char diff;
	unsigned int mhlen, mwlen;

};
#endif // !MAP_H
#pragma once
