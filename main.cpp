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

        int fireRate = 5;
        int fireCounter = 5;

        int reloadTime = 20;
        int reloadCounter = 0;

        int ammo = 7;
        int maxAmmo = 7;

        string rotation = "vpravo";
    };
    player player;





    class Bullet { 
    public:
        int x;
        int y;
        int dmg = 1;
        int speedX = 4;
        int speedY = 2;
        bool exist = true;

        string rot;
        string tvar; 

        Bullet(int playerX,int playerY , int UPGRADE, string rotation, int playerW , int playerH)
        {

            if (rotation == "vpravo")
            {
                x = playerX + playerW + 2;
                y = playerY + (playerH / 2);
            }
            else if (rotation == "vlavo")
            {
                x = playerX - 3;
                y = playerY + (playerH / 2);
            }
            else if (rotation == "hore")
            {
                x = playerX + (playerW/2);
                y = playerY - 2;
            }
            else if (rotation == "dole")
            {
                x = playerX + (playerW/2);
                y = playerY + playerH + 1;
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
    
    //---------ENEMY-------------
    class Enemy { 
    public:
        int x = 20;
        int y = 20;
        
        int width = 5;
        int height = 3;

        bool alive = true;
        int health = 20;
    
    };
    typedef std::vector<Enemy> enemy_list_t;
    Enemy enemy;
    // Create the vector.
    enemy_list_t enemy_list;

    enemy_list.push_back(enemy);

    
    while (game)
    {
        Bullet bullet(player.x,player.y, player.upgrade , player.rotation , player.width , player.height);
    //-----------------dynamicka aktualizacia pre constructor----------
        player.fireCounter += 1;
        if(player.ammo == 0)
        {
            player.reloadCounter += 1;
            if (player.reloadCounter >= player.reloadTime)
            {
                player.ammo = player.maxAmmo;
                player.reloadCounter = 0;
            }
        }



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
            if(player.ammo > 0)
            {
                if(player.fireCounter >= player.fireRate)
                {
                bullet_list.push_back(bullet);
                player.fireCounter = 0;
                player.ammo -= 1;
                }
            }
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


        //----------HIT-------------------
        for (int enemy = 0; enemy < enemy_list.size() ; enemy++)
        {
            if (enemy_list[enemy].alive)
            {
                for (int bullet = 0 ; bullet < bullet_list.size(); bullet++)
                {
                    if (bullet_list[bullet].exist)
                    {
                        if (bullet_list[bullet].x >= enemy_list[enemy].x)
                        {
                            if (bullet_list[bullet].x <= enemy_list[enemy].x + enemy_list[enemy].width) 
                            {
                                if (bullet_list[bullet].y >= enemy_list[enemy].y)
                                {
                                    if (bullet_list[bullet].y <= enemy_list[enemy].y + enemy_list[enemy].height) 
                                    {
                                        
                                        enemy_list[enemy].health -= bullet_list[bullet].dmg;
                                        bullet_list[bullet].exist = false;
                                        
                                    }
                                }
                                
                            }
                        }

                    }
                }
            }
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




        //------------ENEMY-------------------
        for (int k = 0 ; k < enemy_list.size() ; k++)
            {
                for (int i = 0 ; i < enemy_list[k].width; i++)
                {
                    for (int j = 0 ; j < enemy_list[k].height ; j++)
                    {
                        if (j == 0)
                        {
                            if (i == 0 || i == enemy_list[k].width - 1)
                            {
                                screen[enemy_list[k].y + j][enemy_list[k].x + i] = "▄"; 
                                continue;
                            }
                        }
                        if (j == enemy_list[k].height - 1)
                        {
                            if (i == 0 || i == enemy_list[k].width - 1)
                            {
                                screen[enemy_list[k].y + j][enemy_list[k].x + i] = "▀";
                                continue;
                            }    
                        }
                        if (j == 1)
                        {
                            if (i == 1 || i == enemy_list[k].width -2)
                            {
                                screen[enemy_list[k].y + j][enemy_list[k].x + i] = "X";
                                continue;
                            }
                        }
                        screen[enemy_list[k].y + j][enemy_list[k].x + i] = "█";
                    }
                }
                
            }








        clear();
        //farba(4);
        cout << " Health: 100                  " << "X:" << player.x << "    Y:" << player.y << "     rotation: " << player.rotation <<"    Ammo:" <<player.ammo <<"/"<< player.maxAmmo <<"                    "<< enemy_list[0].health <<endl;
        //farba(2);
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


