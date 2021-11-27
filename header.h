#include <iostream>
using namespace std;

int x = 181;
int y = 60;
char text[60][181];


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
            cout << text[i][j];
        }
    }
}