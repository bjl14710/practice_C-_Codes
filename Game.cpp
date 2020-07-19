#include<cstdlib>
#include<iostream>
#include<conio.h>
#include<ctime>
#include<windows.h>
#include"Game.h"

using namespace std;

    bool gameOver;
    const int width = 20;
    const int height = 20;
    int x, y, fruitx, fruity, score;
    enum eDirection{STOP = 0, LEFT, RIGHT, UP, DOWN};
    eDirection dir;
    int TailX[100], TailY[100];
    int nTail;

Game::Game( )
{

}

void Game::Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitx = rand( ) % width;
    fruity = rand( ) % height;
    score = 0;
}

void Game::Draw( )
{
     system("cls");
    for (int i = 0; i < width + 2; i++)

        cout << "#";
        cout << endl;

    for(int i = 0; i < height; i++)
    {
        for(int j=0; j < width; j++)
        {
            if(j==0)
                cout << "#";
            if(i==y && j==x)
                cout << "0";
            else if(i==fruity && j==fruitx)
                cout << "F";
            else
            {
                bool print = false;
                for(int k = 0; k < nTail; k++)
                {
                    if(TailX[k] == j && TailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if(!print)
                    cout << " ";

            }
            if(j == width - 1)
                cout << "#";

        }
        cout<<endl;
    }

    for (int i = 0; i < width + 2; i++)

        cout << "#";
        cout << endl;
        cout << "Score:" << score << endl;
}

void Game::Input( )
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'w':
            dir = UP;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Game::Logic( )
{
    int prevX = TailX[0];
    int prevY = TailY[0];
    int prev2x, prev2y;
    TailX[0] = x;
    TailY[0] = y;
    for( int i = 1; i < nTail; i++)
    {
        prev2x = TailX[i];
        prev2y = TailY[i];
        TailX[i] = prevX;
        TailY[i] = prevY;
        prevX = prev2x;
        prevY = prev2y;
    }
    switch(dir)
    {
case LEFT:
        x--;
        break;
    case RIGHT:
    x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
         break;

    }
    if(x > width || x < 0 || y > height || y < 0)
    gameOver = true;
    /*string url = "www.youtube.com";
    if( gameOver == true)
        ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL); */

    for(int i = 0; i < nTail; i++)
        if( TailX[i] == x && TailY[i] == y)
            gameOver = true;

    if( x == fruitx && y == fruity)
    {
    score += 10;
    fruitx = rand( ) % width;
    fruity = rand( ) % height;
    nTail++;
    }
}

void Game::GameOver( )
{
    if(gameOver == true)
    {
        system("cls");
        cout << "game over" << endl;
    }
}




