#include <iostream>
#include <string>
using namespace std;

const int x = 211;
const int y = 49;
string screen[y][x];
bool game = true;
string RiadkovyText= "";


void clear()
{
    system("CLS");
}


void draw()
{
    for (int i = 0; i < y ; i++)

    {
        for (int j = 0 ; j < x ; j++)
        {
            RiadkovyText += screen[i][j];
        }
    cout <<RiadkovyText<< endl;
    RiadkovyText = "";
    }
    

}
void pozadie()
{
     for (int i = 0; i < y ; i++)
    {
        for (int j = 0 ; j < x ; j++)
        {
            if (i == 0 || i == y-1)
            {
                screen[i][j] = '-';
            }
            else if (j == 0 )
            {
                screen[i][j] = '|';
            }
            else if (j == x-1)
            {
                screen[i][j] = '|';
            }
            else
            {
            screen[i][j] = ' ';
            }
        }
    }
}

