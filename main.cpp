#include <Windows.h>
#include <iostream>
#include <string>
#include "header.h"
using namespace std;


int main() {

    

    class player {
        public:
            int x = 105;
            int y = 25;
            
            int speed = 2;
    };
    player player;



    while (game)
    {
        
        
        
        


        if(GetKeyState('D') & 0x8000)
            {  
                if (player.x < x - player.speed) 
                    {
                    player.x += player.speed;
                    }
            }
        if(GetKeyState('A') & 0x8000)
            {   
                if (player.x > 0 + player.speed) 
                    {
                    player.x -= player.speed;
                    }

            }
        if(GetKeyState('W') & 0x8000)
            {   
                if (player.y > 0 + player.speed) 
                    {
                    player.y -= player.speed;
                    }
            }
        if(GetKeyState('S') & 0x8000)
            {   
                if (player.y < y-player.speed) 
                    {
                    player.y += player.speed;
                    }
            }







        pozadie();

        screen[player.y][player.x] = "@";



        clear();
        cout <<"Health: 100"<< endl;
        draw();
        cout << "konec";
        
        
    }
    

    
    system("PAUSE");
    return 0;
}
