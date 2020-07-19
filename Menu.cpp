#include<string>
#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include"Menu.h"

using namespace std;

Menu::Menu( )
{

}

void Menu::rpgGame( )
{

char Map[10][25]={"########################",
                  "#!                *    #",
                  "#                      #",
                  "#     ***  ######  *   #",
                  "#    **       ***      #",
                  "#                 *    #",
                  "#                      #",
                  "#                *  *  #",
                  "#@                     #",
                  "########################"};
int Gamespeed = 50;
int level = 1;
bool stopGame = false;
int HP = 100;
int MAX_HP = 100;
bool gameOver = false;
int gravityPower = 1;

  while(stopGame==false && level==1 && gameOver == false)
    {
        system("cls");

        for (int y=0; y<10; y++)
        {
            cout << Map[y] << endl;
        }
        cout<<"HP:" << HP << "/" << MAX_HP << endl;
        if(HP == 0)
    {
        gameOver = true;
    }
        for (int y=0; y<10; y++)
        {
            for (int x=0; x<25; x++)
            {
                switch(Map[y][x])
                {
                case '#':
                    {
                        Map[y][x] = 219;
                    }
                    case '@':
                    {
                        if(GetAsyncKeyState(VK_UP) != 0 )
                        {
                            int y2 = (y-1);
                            switch(Map[y2][x])
                            {
                                case ' ':
                                {
                                    Map[y][x]= ' ';
                                    y -= 1;
                                    Map[y2][x] = '@';
                                }break;
                                case '!':
                                    {
                                      level = 2;
                                    }break;
                                case '*':
                                    {
                                        HP -= 20;
                                        Map[y][x]= ' ';
                                        y -= 1;
                                        Map[y2][x] = '@';
                                    }break;

                            }
                        }
                        if(GetAsyncKeyState(VK_DOWN) != 0 )
                        {
                            int y2 = (y+1);
                            switch(Map[y2][x])
                            {
                               case ' ':
                                   {
                                       Map[y][x]= ' ';
                                       y += 1;
                                       Map [y2][x] = '@';
                                   }break;
                                   case '!':
                                    {
                                        level = 2;
                                    }break;
                                    case '*':
                                    {
                                        HP -= 20;
                                        Map[y][x]= ' ';
                                        y += 1;
                                        Map[y2][x] = '@';
                                    }break;

                            }
                        }
                        if(GetAsyncKeyState(VK_RIGHT) != 0 )
                        {
                            int x2 = (x+1);
                            switch(Map[y][x2])
                            {
                            case ' ':
                                   {
                                       Map[y][x]= ' ';
                                       x += 1;
                                       Map [y][x2] = '@';
                                   }break;
                                   case '!':
                                    {
                                        level = 2;
                                    }break;
                                    case '*':
                                    {
                                        HP -= 20;
                                        Map[y][x]= ' ';
                                        x += 1;
                                        Map[y][x2] = '@';
                                    }break;

                            }
                        }
                        if(GetAsyncKeyState(VK_LEFT) != 0 )
                        {
                            int x2 = (x-1);
                            switch(Map[y][x2])
                            {
                                case ' ':
                                   {
                                       Map[y][x]= ' ';
                                       x -= 1;
                                       Map [y][x2] = '@';
                                   }break;
                                   case '!':
                                    {
                                        level = 2;
                                    }break;
                                    case '*':
                                    {
                                        HP -= 20;
                                        Map[y][x]= ' ';
                                        x -= 1;
                                        Map[y][x2] = '@';
                                    }break;

                            }
                        }

                    }break;
                }
            }
        }
    Sleep(Gamespeed);
    }


    while(gameOver == true)
    {
        system("cls");
        cout<<"game Over"<< endl;
        system("pause");
       // return EXIT_SUCCESS;
    }
    while(stopGame == false && level == 2)
    {
        system("cls");
        cout << "congratulations!" << endl;
        system("pause");
       // return EXIT_SUCCESS
    }
}

void Menu::urlSearcher( )
{
    string url;
    int b;
    int a = 0;


    cout<<" video url:" << endl;
    cin >> url;
    cout << "How many times do you want to see this url?" << endl;
    cin >> b;

    while(a<b)
    {
        ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
        a++;
    }
    cin >> a;
}

