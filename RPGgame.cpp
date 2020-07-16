// RPGgame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "map.h"
#include <iomanip>
#include <windows.h>
using namespace std;



int main()
{
	SetConsoleOutputCP(1252);
	string line(34, '-');
	player p;
	characters* p1 = &p;
	unsigned int movement = 0,hlen,wlen;
	int x, y;
	char c = '/0', difficality;

		cout << line << "\n| Welcome to Khod-Mukhtari Game! | \n" << line << "\n1- New game\n2- Exit\n\n © 2020 Banta Inc.  All rights reserved.\n";
		int n;
		cin >> n;
		switch (n)
		{
		case 1: {
			system("CLS"); 
			cout << "Select difficality\n1-Easy\n2-Medium\n3-Hard\n\n"; 
			int s;
			cin >> s;
			switch (s)
			{
			case 1: {
				system("CLS");
				difficality = 'e';
				
				x = 3, y = 0, hlen = 4,wlen=3;
				map m(x, y,difficality,hlen,wlen);
				m.level_map();
				m.action(m, p, p1, movement, c);
				
			}

			case 2: {
				system("CLS"); 
				difficality = 'm';
				x = 4, y = 0, hlen=5,wlen=6;
				map m(x, y, difficality,hlen,wlen);
				m.level_map();
				m.action(m, p, p1, movement, c);
				break;
			}
			case 3: {
				system("CLS");
				difficality = 'h';
				x = 8, y = 0,hlen=9,wlen=9;
				map m(x, y, difficality,hlen,wlen);
				m.level_map();
				m.action(m, p, p1, movement, c);
				break;
			}
			default:
				break;

			}
			break;
		
		}
		case 2: {exit(0); break; }
		default: {system("CLS");int main(); }
		}
		
	
	
	

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
