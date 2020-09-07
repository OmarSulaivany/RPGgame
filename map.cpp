#include "map.h"
#include <iostream>
#include <iomanip>
#include "player.h"
#include <vector>
#include <random>
#include <Windows.h>
using namespace std;

map::map(int x, int y, char di, unsigned int hlen, unsigned int wlen)
    :mx(x), my(y), mp('>'), m_e_map(nullptr), diff(di), mhlen(hlen), mwlen(wlen)
{}

char** map::level_map()
{

    if (this->diff == 'e')
    {
        char map[4][3];
        srand(time(NULL));
        int x = 4, y = 3;
        char letters[] = { '0','S','0','H','0','B','0','E','0','S' };
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                map[i][j] = letters[rand() % 10];
                //cout << easy_map[i][j] << " ";
            }


        }
        map[0][2] = 'K';
        map[1][1] = 'C';
        map[3][1] = 'C';
        map[3][0] = '0';



        char** e_map;
        e_map = new char* [x];

        for (int i = 0; i < x; i++)
        {
            e_map[i] = new char[y];

            for (int j = 0; j < y; j++)
            {
                // fill in some initial values
                // (filling in zeros would be more logic, but this is just for the example)
                e_map[i][j] = map[i][j];
            }
        }

        this->m_e_map = e_map;

        return m_e_map;
    }
    else if (this->diff == 'm')
    {

        char map[5][6];
        srand(time(NULL));
        int x = 5, y = 6;
        char letters[] = { '0','S','0','H','0','B','0','E','0','S' };
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                map[i][j] = letters[rand() % 10];
                //cout << easy_map[i][j] << " ";
            }


        }
        map[0][4] = 'K';
        map[1][3] = 'S';
        map[3][1] = 'C';
        map[3][0] = '0';

        char** e_map;
        e_map = new char* [x];

        for (int i = 0; i < x; i++)
        {
            e_map[i] = new char[y];

            for (int j = 0; j < y; j++)
            {
                // fill in some initial values
                // (filling in zeros would be more logic, but this is just for the example)
                e_map[i][j] = map[i][j];
            }
        }

        this->m_e_map = e_map;

        return m_e_map;

    }
    else if (this->diff == 'h')
    {

        char map[9][9];
        srand(time(NULL));
        int x = 9, y = 9;
        char letters[] = { '0','S','0','H','0','B','0','E','0','S' };
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                map[i][j] = letters[rand() % 10];
                //cout << easy_map[i][j] << " ";
            }


        }
        map[0][8] = 'K';
        map[0][7] = 'S';
        map[1][8] = 'S';
        map[1][1] = 'C';
        map[3][1] = 'C';
        map[3][0] = '0';

        char** e_map;
        e_map = new char* [x];

        for (int i = 0; i < x; i++)
        {
            e_map[i] = new char[y];

            for (int j = 0; j < y; j++)
            {
                // fill in some initial values
                // (filling in zeros would be more logic, but this is just for the example)
                e_map[i][j] = map[i][j];
            }
        }

        this->m_e_map = e_map;

        return m_e_map;

    }


}

void map::print(player p)
{
    if (diff == 'e')
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << m_e_map[i][j] << " ";
            }

            cout << endl;
        }
    }
    else if (diff == 'm')
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cout << m_e_map[i][j] << " ";
            }

            cout << endl;
        }
    }
    else if (diff == 'h')

    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << m_e_map[i][j] << " ";
            }

            cout << endl;
        }
    }
    p.status();

}
map::~map()
{
    delete[] m_e_map;
    // m_e_map = 0;

}
char map::action(map m, player p, characters* p1, unsigned int movement, char x)
{

    m.m_e_map[m.mx][m.my] = m.mp;

    print(p);
    cout << "take a move: 5:Up 2:Down 1:left 3:right :";


    cin >> movement;

    switch (movement)
    {
    case 5:
        if (m.mx - 1 >= 0)
        {
            switch (m_e_map[m.mx - 1][m.my])
            {
            case 'S': { cout << "You have encountered a soldier  \n  Fight:f Stay:s :";
                cin >> x;
                switch (x)
                {
                case'f': {

                    p.fight(m_e_map[m.mx - 1][m.my]);
                    p1 = &p;
                    if (p1->isdead())
                    {
                        system("CLS");
                        cout << "You died in the Battle \n\n Game Over\n\n";
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

                        break;

                    }
                    else
                    {
                        m_e_map[m.mx][m.my] = '0'; m.mx -= 1; m.mp = '^';   system("CLS"); cout << "You killed an Enemy soldier! \n"; action(m, p, p1, movement, x);
                    }
                }
                case 's':system("CLS"); action(m, p, p1, movement, x);
                default:system("CLS"); action(m, p, p1, movement, x);


                    break;
                }
            }
            case 'E': m_e_map[m.mx][m.my] = '0'; m.mx -= 1; m.mp = '^';   system("CLS"); p.enhance_power(); action(m, p, p1, movement, x);
            case 'H': m_e_map[m.mx][m.my] = '0'; m.mx -= 1; m.mp = '^'; system("CLS"); p.enhance_health(); action(m, p, p1, movement, x);
            case '0': m_e_map[m.mx][m.my] = '0'; m.mx -= 1; m.mp = '^'; system("CLS"); action(m, p, p1, movement, x);
            case 'B': m_e_map[m.mx][m.my] = '0';  m.mx -= 1, m.mp = '^'; system("CLS"); p.bomb(); action(m, p, p1, movement, x);
            case 'C': system("CLS"); cout << "Cant move up there is a wall \n"; action(m, p, p1, movement, x);
            case 'K': { cout << "You have encountered The king  \n  Fight:f Stay:s :";
                cin >> x;
                switch (x)
                {
                case'f': {

                    p.fight(m_e_map[m.mx - 1][m.my]);
                    p1 = &p;
                    if (p1->isdead())
                    {
                        system("CLS");
                        cout << "You died in the Battle \n\n Game Over\n\n";
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

                        break;

                    }
                    else
                    {
                        m_e_map[m.mx][m.my] = '0'; m.mx -= 1; m.mp = '^';   system("CLS"); cout << "You beated the King Congratulation you WON the Game!!!! \n";
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
                case 's':system("CLS"); action(m, p, p1, movement, x);
                default:system("CLS"); action(m, p, p1, movement, x);


                    break;
                }

            default:

                break;
            }
            }
        }
        else
        {
            system("CLS"); cout << "Cant move up more \n"; action(m, p, p1, movement, x);
        }
    case 2:
        if (m.mx + 1 < m.mhlen)
        {
            switch (m_e_map[m.mx + 1][m.my])
            {
            case 'S': { cout << "You have encountered a soldier  \n  Fight:f Stay:s :";
                cin >> x;
                switch (x)
                {
                case'f': {

                    p.fight(m_e_map[m.mx + 1][m.my]);
                    p1 = &p;
                    if (p1->isdead())
                    {
                        system("CLS");
                        cout << "You died in the Battle \n\n Game Over\n\n";
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

                        break;

                    }
                    else
                    {
                        m_e_map[m.mx][m.my] = '0'; m.mx += 1, m.mp = 'v';   system("CLS"); cout << "You killed an Enemy soldier! \n"; action(m, p, p1, movement, x);
                    }
                }
                case 's':system("CLS"); action(m, p, p1, movement, x);
                default:system("CLS"); action(m, p, p1, movement, x);


                    break;
                }


            case 'E':  m_e_map[m.mx][m.my] = '0'; m.mx += 1, m.mp = 'v'; system("CLS"); p.enhance_power(); action(m, p, p1, movement, x);
            case 'H':  m_e_map[m.mx][m.my] = '0'; m.mx += 1, m.mp = 'v'; system("CLS"); p.enhance_health(); action(m, p, p1, movement, x);
            case '0': m_e_map[m.mx][m.my] = '0'; m.mx += 1; m.mp = 'v'; system("CLS"); action(m, p, p1, movement, x);
            case 'B':  m_e_map[m.mx][m.my] = '0'; m.mx += 1, m.mp = 'v'; system("CLS"); p.bomb(); action(m, p, p1, movement, x);
            case 'C': system("CLS"); cout << "Cant move down there is a wall \n"; action(m, p, p1, movement, x);

            case 'K': { cout << "You have encountered the King  \n  Fight:f Stay:s :";
                cin >> x;
                switch (x)
                {
                case'f': {

                    p.fight(m_e_map[m.mx + 1][m.my]);
                    p1 = &p;
                    if (p1->isdead())
                    {
                        system("CLS");
                        cout << "You died in the Battle \n\n Game Over\n\n";
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

                        break;

                    }
                    else
                    {
                        m_e_map[m.mx][m.my] = '0'; m.mx += 1, m.mp = 'v';   system("CLS"); cout << "You beated the King Congratulation you WON the Game!!!! \n";
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
                case 's':system("CLS"); action(m, p, p1, movement, x);
                default:system("CLS"); action(m, p, p1, movement, x);


                    break;
                }



            default:

                break;
            }
            }
            }
        }
        else
        {
            system("CLS"); cout << "Cant move down more \n"; action(m, p, p1, movement, x);
        }

    case 1:
        if (m.my - 1 >= 0)
        {
            switch (m_e_map[m.mx][m.my - 1])
            {

            case 'S': { cout << "You have encountered a soldier  \n  Fight:f Stay:s :";
                cin >> x;
                switch (x)
                {
                case'f': {

                    p.fight(m_e_map[m.mx][m.my - 1]);
                    p1 = &p;
                    if (p1->isdead())
                    {
                        system("CLS");
                        cout << "You died in the Battle \n\n Game Over\n\n";
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

                        break;

                    }
                    else
                    {
                        m_e_map[m.mx][m.my] = '0'; m.my -= 1, m.mp = '<';   system("CLS"); cout << "You killed an Enemy soldier! \n"; action(m, p, p1, movement, x);
                    }
                }
                case 's':system("CLS"); action(m, p, p1, movement, x);
                default:system("CLS"); action(m, p, p1, movement, x);


                    break;
                }



            case 'E': m_e_map[m.mx][m.my] = '0'; m.my -= 1, m.mp = '<'; system("CLS"); p.enhance_power(); action(m, p, p1, movement, x);
            case 'H': m_e_map[m.mx][m.my] = '0'; m.my -= 1, m.mp = '<'; system("CLS"); p.enhance_health(); action(m, p, p1, movement, x);
            case '0':  m_e_map[m.mx][m.my] = '0'; m.my -= 1, m.mp = '<'; system("CLS"); action(m, p, p1, movement, x);
            case 'B': m_e_map[m.mx][m.my] = '0'; m.my -= 1, m.mp = '<'; system("CLS"); p.bomb(); action(m, p, p1, movement, x);
            case 'C': system("CLS"); cout << "Cant move left there is a wall \n"; action(m, p, p1, movement, x);

            case 'K': { cout << "You have encountered the King  \n  Fight:f Stay:s :";
                cin >> x;
                switch (x)
                {
                case'f': {

                    p.fight(m_e_map[m.mx][m.my - 1]);
                    p1 = &p;
                    if (p1->isdead())
                    {
                        system("CLS");
                        cout << "You died in the Battle \n\n Game Over\n\n";
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

                        break;

                    }
                    else
                    {
                        m_e_map[m.mx][m.my] = '0'; m.my -= 1, m.mp = '<';   system("CLS"); cout << "You beated the King Congratulation you WON the Game!!!! \n";
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
                case 's':system("CLS"); action(m, p, p1, movement, x);
                default:system("CLS"); action(m, p, p1, movement, x);


                    break;
                }



            default:

                break;
            }
            }
            }
        }
        else
        {
            system("CLS"); cout << "Cant move left more \n"; action(m, p, p1, movement, x);
        }
    case 3:
        if (m.my + 1 < m.mwlen)
        {
            switch (m_e_map[m.mx][m.my + 1])
            {
            case 'S': { cout << "You have encountered a soldier  \n  Fight:f Stay:s :";
                cin >> x;
                switch (x)
                {
                case'f': {

                    p.fight(m_e_map[m.mx][m.my + 1]);
                    p1 = &p;
                    if (p1->isdead())
                    {
                        system("CLS");
                        cout << "You died in the Battle \n\n Game Over\n\n";
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
                        break;
                    }
                    else
                    {
                        m_e_map[m.mx][m.my] = '0'; m.my += 1, m.mp = '>';   system("CLS"); cout << "You killed an Enemy soldier! \n"; action(m, p, p1, movement, x);
                    }
                }
                case 's':system("CLS"); action(m, p, p1, movement, x);
                default:system("CLS"); action(m, p, p1, movement, x);


                    break;
                }

            case 'E': m_e_map[m.mx][m.my] = '0'; m.my += 1, m.mp = '>'; system("CLS"); p.enhance_power(); action(m, p, p1, movement, x);
            case 'H':  m_e_map[m.mx][m.my] = '0'; m.my += 1, m.mp = '>'; system("CLS"); p.enhance_health(); action(m, p, p1, movement, x);
            case '0': m_e_map[m.mx][m.my] = '0'; m.my += 1, m.mp = '>'; system("CLS"); action(m, p, p1, movement, x);
            case 'B': m_e_map[m.mx][m.my] = '0'; m.my += 1, m.mp = '>'; system("CLS"); p.bomb(); action(m, p, p1, movement, x);
            case 'C': system("CLS"); cout << "Cant move right there is a wall \n"; action(m, p, p1, movement, x);

            case 'K': { cout << "You have encountered the King  \n  Fight:f Stay:s :";
                cin >> x;
                switch (x)
                {
                case'f': {

                    p.fight(m_e_map[m.mx][m.my + 1]);
                    p1 = &p;
                    if (p1->isdead())
                    {
                        system("CLS");
                        cout << "You died in the Battle \n\n Game Over\n\n";
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
                    else
                    {
                        m_e_map[m.mx][m.my] = '0'; m.my += 1, m.mp = '>';   system("CLS"); cout << "You beated the King Congratulation you WON the Game!!!! \n";
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
                case 's':system("CLS"); action(m, p, p1, movement, x);
                default:system("CLS"); action(m, p, p1, movement, x);


                    break;
                }



            default:

                break;
            }
            }
            }
        }
        else
        {
            system("CLS"); cout << "Cant move right more \n"; action(m, p, p1, movement, x);
        }


    default:
        system("CLS"); action(m, p, p1, movement, x);
        break;
    }
    return 0;
}