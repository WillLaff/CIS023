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
#include "die.h"
#include <iostream>

using namespace std;

int main()
{
	//Header
    cout << endl << "William Laffey\t"
         << "L1-1\t"
         << "L1-1.exe" << endl;

    

    //Waits for input to close program
    char q;
    cout << "\nPress any key to Exit.";
    cin.ignore(2, '\n');
    cin.get(q);

    return 0;
}
