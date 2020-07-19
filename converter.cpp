#include<iostream>
#include<windows.h>
#include"converter.h"

using namespace std;

char whichConverter;
float current;
float voltage;
float resistance;
float power;
char know;
float comparater;

Converter::Converter( )
{

}

void Converter::printSelection()
{
    cout << "what are you looking for? \n a: current \n b: voltage \n c: resistance \n d: power" << endl;
    cin >> whichConverter;
}

void Converter::powerSelection()
{
    if(know == 'y')
    {
        system("cls");
        cout << "what is the current?" << endl;
        cin >> current;
        cout << "what is the voltage?" << endl;
        cin >> voltage;
    }
    else if(know == 'n')
    {
        system("cls");
        cout << "what is the resistance?" << endl;
        cin >> resistance;
        cout << "what is the current?" << endl;
        cin >> current;
    }
    else
    {
        system("cls");
        cout << "not an option" << endl;
    }
}

void Converter::Input( )
{
     if(whichConverter == 'a') // current
    {
        system("cls");
        cout << "what is the resistance?" << endl;
        cin >> resistance;
        cout << "what is the voltage?" << endl;
        cin >> voltage;
    }
    else if(whichConverter == 'b') // voltage
    {
        system("cls");
        cout << "what is the resistance?" << endl;
        cin >> resistance;
        cout << "what is the current?" << endl;
        cin >> current;
    }
    else if(whichConverter == 'c') // resistance
    {
        system("cls");
        cout << "what is the current?" << endl;
        cin >> current;
        cout << "what is the voltage?" << endl;
        cin >> voltage;

    }
    else if(whichConverter == 'd') // power
    {
        system("cls");
        cout << "do you know the voltage \n y:yes \n n:no" << endl;
        cin >> know;
        powerSelection( );
    }
    else
    {
        system("cls");
        cout << "not an option" << endl;
    }
}

void Converter::Conversion( )
{
     if(whichConverter == 'a' && resistance != 0 && voltage != 0)
    {
        if(.001 <= current < 1)
        {
            cout << "the current is " << voltage / resistance *1000 << "m amps"<< endl;
        }
        else if(.000001 <= current < .001)
        {
            cout << "the current is " << voltage / resistance *1000000 << " u amps"<< endl;
        }
        else if(.000000001 <= current < .000001)
        {
            cout << "the current is " << voltage / resistance *1000000000 << " n amps"<< endl;
        }
        else if(current < .000000001)
        {
            cout << "the current is " << voltage / resistance *1000000000000 << " p amps"<< endl;
        }
        else
        {
            cout << "the current is " << voltage / resistance << " amps" << endl;
        }
    }
    else if(whichConverter == 'b' && resistance != 0 && current != 0)
    {
        if(.001 <= voltage < 1)
        {
            cout << "the voltage is " << current * resistance *1000<< " m volts" << endl;
        }
        else if(.000001 <= voltage < .001)
        {
            cout << "the voltage is " << current * resistance *1000000<< " u volts" << endl;
        }
        else if(.000000001 <= voltage <.000001)
        {
            cout << "the voltage is " << current * resistance *1000000000<< " n volts" << endl;
        }
        else if(voltage <.000000001)
        {
            cout << "the voltage is " << current * resistance *1000000000000<< " p volts" << endl;
        }
        else
        {
            cout << "the voltage is " << current * resistance << " volts" << endl;
        }

    }
    else if(whichConverter == 'c' && current != 0 && voltage != 0)
    {
         if(.001 <= resistance < 1)
        {
            cout << "the resistance is " << voltage / current *1000 <<" m ohms" << endl;
        }
        else if(.000001 <= resistance < .001)
        {
            cout << "the resistance is " << voltage / current *1000000<<" u ohms" << endl;
        }
        else if(.000000001 <= resistance <.000001)
        {
            cout << "the resistance is " << voltage / current *1000000000<<" n ohms" << endl;
        }
        else if(resistance <.000000001)
        {
            cout << "the resistance is " << voltage / current *1000000000000 <<" p ohms" << endl;
        }
        else
        {
            cout << "the resistance is " << voltage / current <<" ohms" << endl;
        }

    }
    else if(whichConverter == 'd' && current != 0)
    {
        if(know == 'y')
        {
            if(.001 <= power < 1)
            {
                cout << "the power is " << voltage * current *1000<< " m watts" << endl;
            }
            else if(.000001 <= power < .001)
            {
                cout << "the power is " << voltage * current *1000000<< " u watts" << endl;
            }
            else if(.000000001 <= power <.000001)
            {
                cout << "the power is " << voltage * current *1000000000<< " n watts" << endl;
            }
            else if(power <.000000001)
            {
                cout << "the power is " << voltage * current *1000000000000<< " p watts" << endl;
            }
            else
            {
                cout << "the power is " << voltage * current << " watts" << endl;
            }
        }
        else if(know == 'n')
        {
            if(.001 <= power < 1)
            {
                cout << "the power is " << current * current * resistance *1000<< "m watts" << endl;
            }
            else if(.000001 <= power < .001)
            {
                cout << "the power is " << current * current * resistance *1000000<< "u watts" << endl;
            }
            else if(.000000001 <= power <.000001)
            {
                cout << "the power is " << current * current * resistance *1000000000<< "n watts" << endl;
            }
            else if(power <.000000001)
            {
                cout << "the power is " << current * current * resistance *1000000000000<< "p watts" << endl;
            }
            else
            {
                cout << "the power is " << current * current * resistance << " watts" << endl;
            }
        }
        else
        {
            cout << "not an option" << endl;
        }

    }
    else if(resistance != 0 && voltage != 0 && current != 0)
    {
        if(whichConverter == 'a')
        {
            cout << "the current is " << 0 << " amps" << endl;
        }
        else if(whichConverter == 'b')
        {
            cout << "the voltage is " << 0 << " volts" << endl;
        }
        else if(whichConverter == 'c')
        {
            cout << "the resistance is " << 0 << " ohms" << endl;
        }
        else if(whichConverter == 'd')
        {
            cout << "the power is " << 0 << " watts" << endl;
        }
    }
}
