#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include<cstdlib>
#include<iostream>
#include<conio.h>
#include<ctime>
#include<windows.h>

class Game
{
public:
    Game( );
    void Setup( );
    void Draw( );
    void Input( );
    void Logic( );
    void GameOver( );

private:


};



#endif // GAME_H_INCLUDED
