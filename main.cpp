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
            int width = 5;
            int height = 3;
            
            int speedY = 1;
            int speedX = 2;

            string rotation = "vpravo";
    };
    player player;



    while (game)
    {
        
        
        
        


        if(GetKeyState('D') & 0x8000)
            {  
                if (player.x < x - player.speedX - player.width - 1) 
                    {
                    player.x += player.speedX;
                    }
            }
        if(GetKeyState('A') & 0x8000)
            {   
                if (player.x > 0 + player.speedX + 1) 
                    {
                    player.x -= player.speedX;
                    }

            }
        if(GetKeyState('W') & 0x8000)
            {   
                if (player.y > 0 + player.speedY + 1) 
                    {
                    player.y -= player.speedY;
                    }
            }
        if(GetKeyState('S') & 0x8000)
            {   
                if (player.y < y-player.speedY-player.height - 1) 
                    {
                    player.y += player.speedY;
                    }
            }
        //-----------rotacia-----------
        if(GetKeyState('L') & 0x8000)
        {
            player.rotation = "vpravo";
        }
        else if(GetKeyState('J') & 0x8000)
        {
            player.rotation = "vlavo";
        }
        else if(GetKeyState('I') & 0x8000)
        {
            player.rotation = "hore";
        }
        else if(GetKeyState('K') & 0x8000)
        {
            player.rotation = "dole";
        }






        pozadie();
        
        //zatial rucne spraveny character
        playerDraw(player.x,player.y,player.width,player.height, player.rotation);
        

        clear();
        cout <<" Health: 100                  "<< "X:" << player.x <<"    Y:" << player.y << "     rotation: " << player.rotation << endl;
        draw();
        cout << "konec";
        
        
    }
    

    
    system("PAUSE");
    return 0;
}
