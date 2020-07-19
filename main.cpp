#include<cstdlib>
#include<iostream>
#include<conio.h>
#include<ctime>
#include<windows.h>
#include"Game.h"
#include"Game.cpp"

int main( )
{
    Game a;
    a.Setup();

    while( !gameOver)
    {
    a.Draw( );
    a.Input( );
    a.Logic( );
    a.GameOver();
    Sleep(10);
    }
    return 0;

}
