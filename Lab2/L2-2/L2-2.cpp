/*
    Program name    : L2-2.cpp

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
#include <iostream>
#include <iomanip>
#include "invalidHr.h"
#include "invalidMin.h"
#include "invalidSec.h"
using namespace std;

int main() 
{
    //Header
    cout << endl << "William Laffey\t"
         << "L2-2\t"
         << "L2-2.exe" << endl;

    

    //Waits for input to close program
    char q;
    cout << "\nPress any key to Exit.";
    cin.ignore(2, '\n');
    cin.get(q);

    return 0;
}
