#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "header.h"
#include <ctype.h>
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
        
        int upgrade = 0;

        string rotation = "vpravo";
    };
    player player;





    class Bullet { 
    public:
        int x;
        int y;
        int dmg;
        int speedX = 4;
        int speedY = 2;
        bool exist = true;

        string rot;
        string tvar; 

        Bullet(int playerX,int playerY , int UPGRADE, string rotation)
        {

            if (rotation == "vpravo")
            {
                x = playerX + 8;
                y = playerY + 1;
            }
            else if (rotation == "vlavo")
            {
                x = playerX - 3;
                y = playerY + 1;
            }
            else if (rotation == "hore")
            {
                x = playerX + 2;
                y = playerY - 2;
            }
            else if (rotation == "dole")
            {
                x = playerX + 2;
                y = playerY + 4;
            }

            rot = rotation;

            //urcovanie bulletu
            switch (UPGRADE)
            {
            case 0:
                tvar = "•";
                dmg = 1;
                break;
            
            default:
                tvar = "•";
                break;
            }
        }
    
    };
    typedef std::vector<Bullet> bullet_list_t;
    

    bullet_list_t bullet_list;
    
    while (game)
    {
        Bullet bullet(player.x,player.y, player.upgrade , player.rotation);
    //-----------------dynamicka aktualizacia pre constructor----------




        if (GetKeyState('D') & 0x8000)
        {
            if (player.x < x - player.speedX - player.width - 1)
            {
                player.x += player.speedX;
            }
        }
        if (GetKeyState('A') & 0x8000)
        {
            if (player.x > 0 + player.speedX + 1)
            {
                player.x -= player.speedX;
            }

        }
        if (GetKeyState('W') & 0x8000)
        {
            if (player.y > 0 + player.speedY + 1)
            {
                player.y -= player.speedY;
            }
        }
        if (GetKeyState('S') & 0x8000)
        {
            if (player.y < y - player.speedY - player.height - 1)
            {
                player.y += player.speedY;
            }
        }
        //-----------rotacia-----------
        if (GetKeyState('L') & 0x8000)
        {
            player.rotation = "vpravo";
        }
        else if (GetKeyState('J') & 0x8000)
        {
            player.rotation = "vlavo";
        }
        else if (GetKeyState('I') & 0x8000)
        {
            player.rotation = "hore";
        }
        else if (GetKeyState('K') & 0x8000)
        {
            player.rotation = "dole";
        }
        if (GetKeyState(32) & 0x8000) // t.j. medzerník

        {
            //prida bullet
            bullet_list.push_back(bullet);
        }

        if (GetKeyState(27) & 0x8000) // esc
        {
            game = false;
            char close = ' ';
            cout << "close?(Y/N)";
            cin >> close;
            close = ((char)toupper(close));
            if (close == 'Y')
                break;
            else
                game = true;
        }


        
        









        pozadie();

        //zatial rucne spraveny character
        playerDraw(player.x, player.y, player.width, player.height, player.rotation);

        //bullet draw
        for (int i=0;i<bullet_list.size();i++)
        {
            if (bullet_list[i].exist)
            {
            
            int By = bullet_list[i].y;
            int Bx = bullet_list[i].x;
            string Bt = bullet_list[i].tvar;
            string Br = bullet_list[i].rot;
            


            
            
            screen[By][Bx] = Bt;
            
            //bullet move
            if (Br == "vpravo")
            { 
                if (Bx < 211 - bullet_list[i].speedX) {
                bullet_list[i].x += bullet_list[i].speedX;
                }
                else{
                    bullet_list[i].exist = false;
                }
            }
            else if (Br == "vlavo")
            {
                if (Bx > 0 + bullet_list[i].speedX) {
                bullet_list[i].x -= bullet_list[i].speedX;
                }
                else{
                    bullet_list[i].exist = false;
                }
            }
            else if (Br == "hore")
            {
                if (By > 0 + bullet_list[i].speedY) {
                bullet_list[i].y -= bullet_list[i].speedY;
                }
                else{
                    bullet_list[i].exist = false;
                }
            }
            else if (Br == "dole")
            {
                if (By < 49 - bullet_list[i].speedY) {
                bullet_list[i].y += bullet_list[i].speedY;
                }
                else{
                    bullet_list[i].exist = false;
                }
            }
            }

        }
        









        clear();
        farba(4);
        cout << " Health: 100                  " << "X:" << player.x << "    Y:" << player.y << "     rotation: " << player.rotation << endl;
        farba(2);
        draw();
        if (bullet_list.size()>0)
        {
        cout << "pocet vystrelených nabojov: " <<bullet_list.size();
        }
    }


    clear();
    farba(0);
    return 0;
}


