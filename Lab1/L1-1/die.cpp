/*
    Program name    : die.cpp

    Written by      : William Laffey

    Purpose         : 

    Inputs          : 

    Outputs         : 

    Calls           : 

    Structure       : BEGIN                                             
                           
                      STOP                                              
                           
                                                                        
   ---------------------------------------------------------------------
    Change Log:                                                         
                               Revision                                 
      Date        Changed  Rel Ver Mod Purpose                          
    00/00/21      wlaffey  001.000.000 Initial release of program       
                                                                        */
//include statements
#include "die.h"
#include <iostream>

using namespace std;

int main()
{
	//Header
    cout << endl << "William Laffey\t"
         << "L1-1\t"
         << "L1-1.exe" << endl;

    //declarations
    int dice;
    long rolls;
    die die;

    //asks for number of dice
    cout << "\nEnter the number of Dies to use (4, 5, or 6): ";
    cin >> dice;
    if (dice == 4 || dice == 5 || dice == 6)
    {
        cout << endl;
    }
    else
    {
        cout << "Please enter a valid number." << endl;
        return 0;
    }

    //asks for number of rolls
    cout << "\nEnter the number of times the " << dice << " are rolled (2500, 3000, or 5000): ";
    cin >> rolls;
    if (rolls == 2500 || rolls == 3000 || rolls == 5000)
    {
        cout << endl;
    }
    else
    {
        cout << "Please enter a valid number." << endl;
        return 0;
    }

    //rolls dice
    int n;
    die.roll(dice, n);
    cout << n << endl;

    //Waits for input to close program
    char q;
    cout << "\nPress any key to Exit.";
    cin.ignore(2, '\n');
    cin.get(q);

    return 0;
}
