#include<iostream>
#include<string>
#include"windows.h"
#include"Menu.h"
#include"Menu.cpp"



using namespace std;

char selection;
int main( )
{
    cout << "please select one \n A: Game \n B: Url searcher \n" << endl;
    cin >> selection;

    Menu a;

    if(selection == 'a')
    {
        system("cls");
        a.rpgGame( );
    }
    else if(selection == 'b')
    {
        system("cls");
        a.urlSearcher( );
    }
    else
    {
        system("cls");
        cout << "error not an option" << endl;
    }


}
