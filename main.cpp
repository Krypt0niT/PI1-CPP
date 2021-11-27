#include <iostream>
#include "header.h"
using namespace std;


int main() {

    
    //tvorba defaultného okna
    
    for (int i = 0; i < y ; i++)
    {
        for (int j = 0 ; j < x ; j++)
        {
            text[i][j] = ' ';
        }
    }
    //---------------------
    

    draw();

    
    text[30][60] = 'Q';
    clear();
    draw();
    
    system("PAUSE");
    return 0;
}
