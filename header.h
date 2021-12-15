﻿
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int x = 211;
const int y = 49;
string screen[y][x];
bool game = true;
string RiadkovyText= "";
//bullety
vector<int> BulletL;

void farba(int );


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
            screen[y + i][x + j] = "\xDB";
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


