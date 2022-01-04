﻿#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

const int x = 211;
const int y = 49;
int Enemies = 0;
int EnemiesAlive = Enemies;
int wave = 0;
string screen[y][x];
bool game = true;
string RiadkovyText= "";

//bullety
vector<int> BulletL;

void farba(int);

void clear();

void draw();

void pozadie();

void playerDraw(int , int , int , int , string);

int random(int a , int b);

class Weapon
{
public:
    int id_upgrade = 0;
    string name = "";
    int ammo = 0;
    int reloadTime = 0;
    int fireRate = 0;
    int dmg = 0;
    int speedX = 0;
    int speedY = 0;
    string tvar ="";
    int pellets = 0;
    int burst = 0;
    Weapon(int a , string b, int c, int d, int e, int f, int g, string h, int i, int j);
};

Weapon::Weapon(int Id, string Name, int Ammo, int ReloadTime, int FireRate, int Dmg, int Speed, string Tvar, int Pellets, int Burst) {
    id_upgrade = Id;
    name = Name;
    ammo = Ammo;
    reloadTime = ReloadTime;
    fireRate = FireRate;
    dmg = Dmg;
    speedX = Speed;
    speedY = Speed /2;
    tvar = Tvar;
    pellets = Pellets;
    burst= Burst;
}





void clear()
{
    system("CLS");
}


void draw()
{
    for (int i = 0; i < y; i++)

    {
        for (int j = 0; j < x; j++)
        {
            RiadkovyText += screen[i][j];
        }
        cout << RiadkovyText << endl;
        RiadkovyText = "";
    }


}
void pozadie()
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    screen[i][j] = "\xDA";
                    continue;
                }
                if (j == x - 1)
                {
                    screen[i][j] = "\xBF";
                    continue;
                }
                screen[i][j] = "\xC4";
            }
            else if (i == y - 1)
            {
                if (j == 0)
                {
                    screen[i][j] = "\xC1";
                    continue;
                }

                if (j == x - 1)
                {
                    screen[i][j] = "\xD9";
                    continue;
                }
                screen[i][j] = "\xC4";
            }
            else if (j == 0)
            {

                screen[i][j] = '\xB3';
            }
            else if (j == x - 1)
            {
                screen[i][j] = '\xB3';
            }
            else
            {
                screen[i][j] = ' ';
            }
        }
    }
}


void playerDraw(int x, int y, int W, int H, string rotation)
{

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0)
            {
                if (j == 0 || j == W - 1)
                {
                    screen[y + i][x + j] = "\xDC";
                    continue;
                }
            }
            if (i == H - 1)
            {
                if (j == 0 || j == W - 1)
                {
                    screen[y + i][x + j] = "\xDF";
                    continue;
                }
            }
                if (i == 1)
                {
                    if (j == 1 || j == W - 2)
                    {
                        screen[y+i][x+j] = "O";
                        continue;
                    }
                }
         
                screen[y+i][x+j] = "\xDB";
        }
    }
    if (rotation == "vpravo")
    {
        screen[y + (H / 2)][x + W] = "\xC4";
        screen[y + (H / 2)][x + W + 1] = "\xC4";
    }
    if (rotation == "vlavo")
    {
        screen[y + (H / 2)][x - 1] = "\xC4";
        screen[y + (H / 2)][x - 2] = "\xC4";
    }
    if (rotation == "hore")
    {
        screen[y - 1][x + H - 1] = "\xB3";
    }
    if (rotation == "dole")
    {
        screen[y + H][x + H - 1] = "\xB3";
    }
}





void farba(int farba)                             // farba popredia + farba pozadia * 16
{                                                   //  0 = Black       8 = Gray
    HANDLE  hConsole;                               //  1 = Blue        9 = Light Blue
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     //  2 = Green       A = Light Green
    SetConsoleTextAttribute(hConsole, farba);       //  3 = Aqua        B = Light Aqua                                              
}                                                   //  4 = Red         C = Light Red
  /*                                                    5 = Purple      D = Light Purple
                                                        6 = Yellow      E = Light Yellow
                                                        7 = White       F = Bright White
 */
int random(int a,int b)
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(a,b); // distribution in range [1, 6]
    return dist6(rng);
}

