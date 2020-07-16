#include "player.h"
#include "Random.h"
#include "soldier.h"
#include "king.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

player::player():pName("Player"), pdamage(mdamage), pheart(mheart), ppower(mpower), psword(msword)
{}

bool player::isdead()
{
	if (this->pheart <= 0)
		return true;
	else
		return false;
}
void player::enhance_power()
{
	if (this->ppower <= 83)
	{
	  this->ppower += 17;
	  cout << "Your power got enhanced by 17 \n";
	}
	else
	{
		this->ppower = 100;
		cout << "Your power got fully enhanced \n";
	}
}

void player::bomb()
{
	if (this->pheart-23 > 0)
	{
		this->pheart -= 23;
		cout << "You fall on a Bomb!!!! you have lost 23 of blood \n";
	}
	else
	{

		cout << "You fall on a Bomb!!!! lost all of blood and died \n  Game over! \n";
		cout << "Play again \n Yes:y NO:n :";
		char n;
		cin >> n;
		if (n == 'y')
		{
			system("CLS");
			WinExec("RPGgame", SW_SHOW);
			exit(1);
		}
		else
			exit(0);
		
	}
}

void player::enhance_health()
{
	if (this->pheart <= 89)
	{
		this->pheart += 11;
		cout << "Your Health got enhanced by 11 \n";
	}
	else
	{
		this->pheart = 100;
		cout << "Your Health got fully enhanced \n";
	}
}
void player::status()
{

	cout << right << setw(95) << this->pName << " Blood: " << this->pheart << " Power: " << this->ppower << '\n';
}
void player::fight(char x)
{
	if (x == 'S')
	{
		soldier s;

		while (s.sheart > 0 && this->pheart > 0)
		{
			cout << right << setw(95) << this->pName << " Blood: " << this->pheart << " Power: " << this->ppower << '\n';
			cout << right << setw(111) << "-----------------------" << '\n';
			cout << right << setw(95) << s.sName << " Blood: " << s.sheart << '\n';
			cout << "Attack:a Defend:d : ";
			cin >> x;
			switch (x)
			{
			case 'a':
			{

				if (this->ppower >= 5)
				{
					if (Random(1, 5) > 3)
					{
						cout << "you hit the Enemy soldier \n";
						if (s.sheart - 17 > 0)
						{
							s.sheart -= 17;
							this->ppower -= 5;
							break;
						}
						else
						{

							s.sheart = 0;
							break;
						}
					}

					else
					{
						cout << "you missed hitting the Enemy soldier  \n";
						this->ppower -= 5;

						if (Random(1, 10) > 7)
						{
							if (this->pheart - 5 > 0)
							{
								cout << "You were hit by the Enemy soldier BE CAREGULL!! \n";
								this->pheart -= 5;
								break;
							}
							else
							{
								this->pheart = 0;
								break;
							}
						}
					}

				}
				else
				{
					if (this->ppower < 5)
					{
						cout << "You can't attack you have less than 5 points of power left \n"; break;
					}

				}

			} break;
			case 'd': {this->ppower += 1; }

			default:
				break;
			}

		}
	}
	else if (x == 'K')
	{

		king k;

		while (k.kheart > 0 && this->pheart > 0)
		{
			cout << right << setw(95) << this->pName << " Blood: " << this->pheart << " Power: " << this->ppower << '\n';
			cout << right << setw(111) << "-----------------------" << '\n';
			cout << right << setw(95) << k.kName << " Blood: " << k.kheart << '\n';
			cout << "Attack:a Defend:d : ";
			cin >> x;
			switch (x)
			{
			case 'a':
			{

				if (this->ppower >= 5)
				{
					if (Random(1, 10) > 6)
					{
						cout << "you hit the King \n";
						if (k.kheart - 13 > 0)
						{
							k.kheart -= 13;
							this->ppower -= 5;
							break;
						}
						else
						{

							k.kheart = 0;
							break;
						}
					}

					else
					{
						cout << "you missed hitting the King!!!  \n";
						this->ppower -= 5;

						if (Random(1, 10) > 7)
						{
							if (this->pheart - 5 > 0)
							{
								cout << "You were hit by the King BE CAREGULL!! \n";
								this->pheart -= 5;
								break;
							}
							else
							{
								this->pheart = 0;
								break;
							}
						}
					}

				}
				else
				{
					if (this->ppower < 5)
					{
						cout << "You can't attack you have less than 5 points of power left \n"; break;
					}

				}

			} break;
			case 'd': {this->ppower += 1; }

			default:
				break;
			}


		}
	}
}