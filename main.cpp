#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "header.h"
#include <ctype.h>
#include <time.h>
using namespace std;

class player {
public:
    int x = 105;
    int y = 25;
    int width = 5;
    int height = 3;
    int health = 100;

    int speedY = 1;
    int speedX = 2;

    int upgrade = 0;

    int fireRate = 5;
    int fireCounter = 5;

    int reloadTime = 20;
    int reloadCounter = 0;

    int ammo = 7;
    int maxAmmo = 7;

    int burst = 1;

    string rotation = "vpravo";


    void ChangeWeapon(int Upgrade, int FireRate, int ReloadTime, int MaxAmmo, int Burst) { 
        upgrade = Upgrade;
        fireRate = FireRate;
        reloadTime = ReloadTime;
        maxAmmo = MaxAmmo;
        burst = Burst;
        ammo = MaxAmmo;
    }
};

class Bullet {
public:
    int x;
    int y;
    int dmg = 1;
    int speedX = 4;
    int speedY = 2;
    bool exist = true;
    int pellets = 1;

    string rot;
    string tvar;

    Bullet(int playerX, int playerY, int UPGRADE, string rotation, int playerW, int playerH)
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
            x = playerX + (playerW / 2);
            y = playerY - 2;
        }
        else if (rotation == "dole")
        {
            x = playerX + (playerW / 2);
            y = playerY + playerH + 1;
        }

        rot = rotation;

        //urcovanie bulletu
        switch (UPGRADE)
        {
        case 0:
            tvar = "\xfa";
            dmg = 1;
            break;

        default:
            tvar = "\xfa";
            break;
        }
    }

    void ChangeWeapon(int Dmg, int SpeedX, int SpeedY, string Tvar, int Pellets) {
        dmg = Dmg;
        speedX = SpeedX;
        speedY = SpeedY;
        tvar = Tvar;
        pellets = Pellets;
    }

};
//---------ENEMY-------------
class Enemy {
public:
    int x;
    int y;

    int width = 5;
    int height = 3;

    bool alive = true;
    int health = 20;
    int dmg;
    int speedX = 2;
    int speedY = 1;

    int EnemySlower = 2;
    int EnemySlowerTick = 0;
};

class Boosts { 
    public:
        int x;
        int y;
        
        int width = 4;
        int height = 2;
    
    };



int main() {
    srand(time(NULL));

    int kills = 0, upgrade = 10, Upgrade;

    
    float multiplier = 0;

    player player;

    typedef std::vector<Boosts> boosts_list_t;

    Boosts boosts;
    // Create the vector.
    boosts_list_t boosts_list;


        for (int i = 0 ; i < 3 ; i++)
    {
        boosts_list.push_back(boosts);  // pridanie bulletu do listu (vectoru)
        boosts_list[i].x = random(2, (x - boosts_list[i].width - 2));
        boosts_list[i].y = random(1, (y - boosts_list[i].height - 1));   
    }

    typedef std::vector<Weapon> weapon_list_t;


    weapon_list_t weapon_list;

    string nazov[22] = { "Pistol","Revolver","Pistol+","Double barrel shotgun","Hunting rifle","Atomatic pistol","Pump action shotgun", "Bolt action rifle","Semi-automatic rifle","smg", "Semi-automatic shotgun", "Pump action shotgun +", "DMR", "Battle rifle", "Burst rifle", "Smg +", "Automatic shotgun", "Pump action shotgun ++", "Sniper rifle", "Automatic rifle", "Burst rifle+", "Smg++" };
    int ammo[22] = { 7, 6, 17, 2, 5, 20, 5, 5, 20, 30, 5, 7, 10, 20, 30, 30, 20, 8, 10, 30, 30, 50 };
    int reload[22] = { 15, 20, 10, 20, 15, 10, 20, 15, 20, 10 , 20, 15, 20, 20, 20, 10, 30, 14, 30, 18, 15, 10 };
    int fireRate[22] = { 7, 10, 4, 15, 16, 2, 13, 16, 7, 3, 7, 11, 10, 5, 10, 2, 4, 8, 15, 3, 10, 1 };
    int dmg[22] = { 5, 10, 5, 7, 25, 5, 10, 40, 25, 7, 10, 15, 50, 35, 25, 10, 15, 20, 125, 40, 30, 15};
    int speed[22] = { 4, 4, 4, 4, 8, 6, 4, 8, 8, 6, 4, 4, 10, 8, 8, 6, 4, 4, 10, 8, 8, 6};
    string shape[22] = {"·","•", "·", "∴", "•", "·", "∴", "·", "·", "·", "∴", "∴", "●", "•", "•", "·", "∴", "∴", "●", "•", "•", "·" };
    int pellets[22] = { 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1 };
    int burst[22] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1 };

    for (int i = 0; i < 22; i++) {
        weapon_list.push_back(Weapon(i, nazov[i], ammo[i], reload[i], fireRate[i], dmg[i], speed[i], shape[i], pellets[i], burst[i]));

            }

    Weapon current_weapon = weapon_list[0];
            
    string upgrade_name1 = "", upgrade_name2 = "";

    player.ChangeWeapon(current_weapon.id_upgrade, current_weapon.fireRate, current_weapon.reloadTime, current_weapon.ammo, current_weapon.burst);
    
    typedef std::vector<Bullet> bullet_list_t;
    
    bullet_list_t bullet_list;
    
        
    typedef std::vector<Enemy> enemy_list_t;
    Enemy enemy;
    // Create the vector.
    enemy_list_t enemy_list;

    

    
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

        bullet.ChangeWeapon(current_weapon.dmg, current_weapon.speedX, current_weapon.speedY, current_weapon.tvar, current_weapon.pellets);


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
            //strielanie pre burst rifle
            if (player.burst == 3 && player.ammo % 3 != 0) {
                player.fireRate = 1;
            }
            else if (player.burst == 3 && player.ammo % 3 == 0) {
                player.fireRate = fireRate[current_weapon.id_upgrade];
            }



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
        if (GetKeyState(49) & 0x8000) {
            if (kills >= upgrade + upgrade * multiplier)
            {
                if (current_weapon.id_upgrade == 0)
                {
                    current_weapon = weapon_list[current_weapon.id_upgrade + 1];
                }
                else if (current_weapon.id_upgrade == 1 || current_weapon.id_upgrade == 2)
                {
                    current_weapon = weapon_list[current_weapon.id_upgrade + 2];
                }
                else if (current_weapon.id_upgrade == 3 || current_weapon.id_upgrade == 4)
                {
                    current_weapon = weapon_list[current_weapon.id_upgrade + 3];
                }
                else if (current_weapon.id_upgrade == 5 || current_weapon.id_upgrade == 6)
                {
                    current_weapon = weapon_list[current_weapon.id_upgrade + 4];
                }
                else if (current_weapon.id_upgrade == 7 || current_weapon.id_upgrade == 8)
                {
                    current_weapon = weapon_list[current_weapon.id_upgrade + 5];
                }
                else if (current_weapon.id_upgrade == 9 || current_weapon.id_upgrade == 10 || current_weapon.id_upgrade == 11 || current_weapon.id_upgrade == 12 || current_weapon.id_upgrade == 13 || current_weapon.id_upgrade == 14 || current_weapon.id_upgrade == 15)
                {
                    current_weapon = weapon_list[current_weapon.id_upgrade + 6];
                }
                else if (current_weapon.id_upgrade == 16 || current_weapon.id_upgrade == 17 || current_weapon.id_upgrade == 18 || current_weapon.id_upgrade == 19 || current_weapon.id_upgrade == 20 || current_weapon.id_upgrade == 21) {
                    dmg[current_weapon.id_upgrade] += multiplier;
                }
                multiplier = multiplier + multiplier*0.5;
                kills = 0;
            }
            player.ChangeWeapon(current_weapon.id_upgrade, current_weapon.fireRate, current_weapon.reloadTime, current_weapon.ammo, current_weapon.burst);

        }
        if (GetKeyState(50) & 0x8000) {
            if (kills >= upgrade + upgrade * multiplier) {
                if (current_weapon.id_upgrade == 0)
                {
                    current_weapon = weapon_list[current_weapon.id_upgrade + 2];        
                }
                else if (current_weapon.id_upgrade == 1 || current_weapon.id_upgrade == 2)
                {
                    current_weapon = weapon_list[current_weapon.id_upgrade + 3];
                }
                else if (current_weapon.id_upgrade == 4)
                {
                    current_weapon = weapon_list[current_weapon.id_upgrade + 4];
                }
                else if (current_weapon.id_upgrade == 6)
                {
                    current_weapon = weapon_list[current_weapon.id_upgrade + 5];
                }
                else if (current_weapon.id_upgrade == 7 || current_weapon.id_upgrade == 8)
                {
                    current_weapon = weapon_list[current_weapon.id_upgrade + 6];
                }
                else if (current_weapon.id_upgrade == 16 || current_weapon.id_upgrade == 17 || current_weapon.id_upgrade == 18 || current_weapon.id_upgrade == 19 || current_weapon.id_upgrade == 20 || current_weapon.id_upgrade == 21) {
                    dmg[current_weapon.id_upgrade] += multiplier;
                }
                multiplier += 0.5;
                kills = 0;
            }
            player.ChangeWeapon(current_weapon.id_upgrade, current_weapon.fireRate, current_weapon.reloadTime, current_weapon.ammo, current_weapon.burst);
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
                                        
                                        if (enemy_list[enemy].health <= 0)
                                        {
                                            enemy_list[enemy].alive = false;
                                            kills++;
                                        }
                                        
                                    }
                                }
                                
                            }
                        }

                    }
                }
            }
        }
        //--------KONTROLA ALIVE ENEMAKOV A KONIEC KOLA -------------
        EnemiesAlive  = 0;
        for (int i = 0 ; i < enemy_list.size() ; i++)
        {
            if (enemy_list[i].alive) {
                EnemiesAlive += 1;
            }
        }







        //-----------ENEMY MOVE----------------------

        for (int enemy = 0 ; enemy < enemy_list.size() ; enemy ++)
        {
            
            if (enemy_list[enemy].alive)
            {

                if (enemy_list[enemy].EnemySlowerTick >= enemy_list[enemy].EnemySlower)
                {
                    bool move = true;
                    if (player.y < enemy_list[enemy].y)
                    {  
                        move = true;
                        for (int i = 0 ; i < enemy_list.size() ; i++)
                        {
                            
                            if (enemy_list[i].alive)
                            {
                                if (enemy_list[enemy].y > enemy_list[i].y)
                                {
                                    if (enemy_list[i].y + enemy_list[i].height >= enemy_list[enemy].y)
                                    {
                                        if (enemy_list[i].x + enemy_list[i].width > enemy_list[enemy].x)
                                        {
                                            if (enemy_list[i].x < enemy_list[enemy].x + enemy_list[enemy].width)
                                            {
                                                move = false;
                                            }
                                        } 
                                    }
                                }
                            }
                        }
                        if (move)
                        {
                            enemy_list[enemy].y -= enemy_list[enemy].speedY;
                        }
                    
                    }
                    if (player.y > enemy_list[enemy].y)
                    {  
                        
                        move = true;
                        for (int i = 0 ; i < enemy_list.size() ; i++)
                        {
                            
                            if (enemy_list[i].alive)
                            {
                                if (enemy_list[enemy].y < enemy_list[i].y)
                                {
                                    if (enemy_list[enemy].y + enemy_list[enemy].height >= enemy_list[i].y)
                                    {
                                        if (enemy_list[i].x + enemy_list[i].width > enemy_list[enemy].x)
                                        {
                                            if (enemy_list[i].x < enemy_list[enemy].x + enemy_list[enemy].width)
                                            {
                                                move = false;
                                            }
                                        } 
                                    }
                                }
                            }
                        }
                        if (move)
                        {
                            enemy_list[enemy].y += enemy_list[enemy].speedY;
                        }
                        
                    }
                    if (player.x > enemy_list[enemy].x)
                    {  
                        move = true;
                        for (int i = 0 ; i < enemy_list.size() ; i++)
                        {
                            
                            if (enemy_list[i].alive)
                            {
                                if (enemy_list[enemy].x < enemy_list[i].x)
                                {
                                    if (enemy_list[enemy].x + enemy_list[enemy].width >= enemy_list[i].x)
                                    {
                                        if (enemy_list[i].y + enemy_list[i].height > enemy_list[enemy].y)
                                        {
                                            if (enemy_list[i].y < enemy_list[enemy].y + enemy_list[enemy].height)
                                            {
                                                move = false;
                                            }
                                        } 
                                    }
                                }
                            }
                        }
                        if (move)
                        {
                            enemy_list[enemy].x += enemy_list[enemy].speedX;
                        }
                    }
                    if (player.x < enemy_list[enemy].x)
                    {  
                        move = true;
                        for (int i = 0 ; i < enemy_list.size() ; i++)
                        {
                            
                            if (enemy_list[i].alive)
                            {
                                if (enemy_list[enemy].x > enemy_list[i].x)
                                {
                                    if (enemy_list[i].x + enemy_list[i].width >= enemy_list[enemy].x)
                                    {
                                        if (enemy_list[i].y + enemy_list[i].height > enemy_list[enemy].y)
                                        {
                                            if (enemy_list[i].y < enemy_list[enemy].y + enemy_list[enemy].height)
                                            {
                                                move = false;
                                            }
                                        } 
                                    }
                                }
                            }
                        }
                        if (move)
                        {
                            enemy_list[enemy].x -= enemy_list[enemy].speedX;
                        }
                    }
                    

                    enemy_list[enemy].EnemySlowerTick = 0;
                }
                else
                {
                   enemy_list[enemy].EnemySlowerTick += 1; 
                }

            }
        }
        if (EnemiesAlive == 0)
        {
            enemy_list.clear();
            wave += 1;

            switch (wave)
            {
            case 1:
                Enemies = 2;
                break;
            case 2:
                Enemies = 3;
                break;
            case 3:
                Enemies = 5;
                break;
            case 4:
                Enemies = 7;
                break;
            case 5:
                Enemies = 10;
                break;
            case 6:
                Enemies = 12;
                break;
            case 7:
                Enemies = 15;
                break;
            case 8:
                Enemies = 17;
                break;
            case 9:
                Enemies = 20;
                break;
            case 10:
                Enemies = 25;
                break;
                            
            default:
                if (wave > 10) {
                Enemies = 25 + (wave - 10);
                }
                break;



            
            }
            //----------SPAWN----------------
            for (int i = 0 ; i < Enemies ; i++)
            {
                int r = random(0,3);
                if (r == 0)
                {
                    enemy_list.push_back(enemy);
                    enemy_list[i].y = 1;
                    enemy_list[i].x = random(1,205);
                    
                }
                else if (r == 1)
                {
                    enemy_list.push_back(enemy);
                    enemy_list[i].x = 1;
                    enemy_list[i].y = random(1,45);
                    

                }
                else if (r == 2)
                {
                    enemy_list.push_back(enemy);
                    enemy_list[i].y = 45;
                    enemy_list[i].x = random(1,205);
                    
                }
                else if (r == 3)
                {
                    enemy_list.push_back(enemy);
                    enemy_list[i].y = random(1,45);
                    enemy_list[i].x = 205;
                    
                }
                enemy_list[i].EnemySlower = random(1,3);
                enemy_list[i].dmg = random(1,3);
            }

        }

        //-------------ENEMY BITE -------------------------
        for (int enemy = 0 ; enemy < enemy_list.size() ; enemy++)
        {
            if (enemy_list[enemy].alive)
            {
                if (enemy_list[enemy].x + enemy_list[enemy].width >= player.x )
                {
                    if (enemy_list[enemy].x <= player.x + player.width)
                    {
                        if (enemy_list[enemy].y + enemy_list[enemy].height >= player.y )
                        {
                            if (enemy_list[enemy].y <= player.y + player.height)
                            {

                                player.health -= enemy_list[enemy].dmg;  
                            }
                        }
                    }
                }
            }
        }

        
        


        //mozne upgrady
        if (current_weapon.id_upgrade == 0)
        {
            upgrade_name1 = weapon_list[current_weapon.id_upgrade + 1].name;
            upgrade_name2 = weapon_list[current_weapon.id_upgrade + 2].name;
        }
        else if (current_weapon.id_upgrade == 1 || current_weapon.id_upgrade == 2)
        {
            upgrade_name1 = weapon_list[current_weapon.id_upgrade + 2].name;
            upgrade_name2 = weapon_list[current_weapon.id_upgrade + 3].name;
        }
        else if (current_weapon.id_upgrade == 3)
        {
            upgrade_name1 = weapon_list[current_weapon.id_upgrade + 3].name;
            upgrade_name2 = "";
        }
        else if(current_weapon.id_upgrade == 4)
        {
            upgrade_name1 = weapon_list[current_weapon.id_upgrade + 3].name;
            upgrade_name2 = weapon_list[current_weapon.id_upgrade + 4].name;
        }
        else if (current_weapon.id_upgrade == 5)
        {
            upgrade_name1 = weapon_list[current_weapon.id_upgrade + 3].name;
            upgrade_name2 = "";
        }
        else if (current_weapon.id_upgrade == 6 )
        {
            upgrade_name1 = weapon_list[current_weapon.id_upgrade + 4].name;
            upgrade_name2 = weapon_list[current_weapon.id_upgrade + 5].name;
        }
        else if (current_weapon.id_upgrade == 7 || current_weapon.id_upgrade == 8)
        {
            upgrade_name1 = weapon_list[current_weapon.id_upgrade + 5].name;
            upgrade_name2 = weapon_list[current_weapon.id_upgrade + 6].name;
        }
        else if (current_weapon.id_upgrade == 9 || current_weapon.id_upgrade == 10 || current_weapon.id_upgrade == 11 || current_weapon.id_upgrade == 12 || current_weapon.id_upgrade == 13 || current_weapon.id_upgrade == 14 || current_weapon.id_upgrade == 15)
        {
            upgrade_name1 = weapon_list[current_weapon.id_upgrade + 6].name;
            upgrade_name2 = "";
        }
        else if (current_weapon.id_upgrade == 16 || current_weapon.id_upgrade == 17 || current_weapon.id_upgrade == 18 || current_weapon.id_upgrade == 19 || current_weapon.id_upgrade == 20 || current_weapon.id_upgrade == 21)
        {
            upgrade_name1 = "+DMG";
            upgrade_name2 = "+AMMO";
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
        //---------Boosts--------------
        for (int i = 0; i < boosts_list.size(); i++)
        {
            
            for(int j = 0; j < boosts_list[i].height; j++)
            {
                for(int k = 0; k < boosts_list[i].width; k++)
                {
                    screen[boosts_list[i].y + j][boosts_list[i].x +k] = "█";

                }
            }
        }
        


        //------------ENEMY-------------------
        for (int k = 0 ; k < enemy_list.size() ; k++)
            {
                if (enemy_list[k].alive) 
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
            }








        Upgrade = upgrade + upgrade * multiplier;
        clear();
        cout << "health: "<<player.health << "    X:" << player.x << "    Y:" << player.y<<"    Ammo:" <<player.ammo <<"/"<< player.maxAmmo  <<"  Current weapon: "<< current_weapon.name <<"   Weapon Upgrade 1: "<< upgrade_name1 <<"   Weapon Upgrade 2: "<< upgrade_name2<<"   " << kills <<"/"<< upgrade + upgrade * multiplier <<endl;
        draw();
        if (bullet_list.size()>0)
        {
        cout << "pocet vystrelených nabojov: " <<bullet_list.size();
        }
    }


    clear();
    return 0;
}


