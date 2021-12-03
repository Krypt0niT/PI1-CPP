#include <iostream>
#include <string>
using namespace std;

const int x = 211;
const int y = 48;
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
            screen[i][j] = ' ';
        }
    }
}