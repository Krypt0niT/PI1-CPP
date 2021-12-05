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
            int width = 6;
            int height = 3;
            
            int speedY = 1;
            int speedX = 2;
    };
    player player;



    while (game)
    {
        
        
        
        


        if(GetKeyState('D') & 0x8000)
            {  
                if (player.x < x - player.speedX - player.width) 
                    {
                    player.x += player.speedX;
                    }
            }
        if(GetKeyState('A') & 0x8000)
            {   
                if (player.x > 0 + player.speedX) 
                    {
                    player.x -= player.speedX;
                    }

            }
        if(GetKeyState('W') & 0x8000)
            {   
                if (player.y > 0 + player.speedY) 
                    {
                    player.y -= player.speedY;
                    }
            }
        if(GetKeyState('S') & 0x8000)
            {   
                if (player.y < (y-player.speedY)-player.height) 
                    {
                    player.y += player.speedY;
                    }
            }







        pozadie();
        
        //zatial rucne spraveny character
        playerDraw(player.x,player.y,player.width,player.height);
        

        clear();
        cout <<" Health: 100                  "<< "X:" << player.x <<"    Y:" << player.y << endl;
        draw();
        cout << "konec";
        
        
    }
    

    
    system("PAUSE");
    return 0;
}
