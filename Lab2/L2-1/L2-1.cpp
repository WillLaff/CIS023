/*
    Program name    : L2-1.cpp

    Written by      : William Laffey

    Purpose         : Overloads each operator to produce desired output

    Inputs          : None

    Outputs         : Result of each overloaded operator

    Calls           : Class file called rectangleType.h

    Structure       : BEGIN                                             
                           Straight through, no sub-processes
                      STOP                                              
                           End of process
                                                                        
   ---------------------------------------------------------------------
    Change Log:                                                         
                               Revision                                 
      Date        Changed  Rel Ver Mod Purpose                          
    00/00/21      wlaffey  001.000.000 Initial release of program       
                                                                        */
#include <iostream>
#include <iomanip>
#include "rectangleType.h"
using namespace std;

int main() 
{
    //Header
    cout << endl << "William Laffey\t"
         << "L2-1\t"
         << "L2-1.exe" << endl;

    //declare objects 
    rectangleType r1(10, 10);
    rectangleType r2(10, 10);
    rectangleType sum;

    //test pre increment
    ++r1;
    cout << "\nNew length and width is " << r1.getLength() << " and " << r1.getWidth() << endl;
    //test post increment
    r1++;
    cout << "New length and width is " << r1.getLength() << " and " << r1.getWidth() << endl;
    //test pre decrement
    --r1;
    cout << "New length and width is " << r1.getLength() << " and " << r1.getWidth() << endl;
    //test post decrement
    r1--;
    cout << "New length and width is " << r1.getLength() << " and " << r1.getWidth() << endl;

    //tests + operator
    sum = r1 + r2;
    cout << "New rectangle dimensions are " << sum.getLength() << " and " << sum.getWidth() << endl;
    //tests - operator
    sum = r1 - r2;
    cout << "New rectangle dimensions are " << sum.getLength() << " and " << sum.getWidth() << endl;
    //tests * operator
    sum = r1 * r2;
    cout << "New rectangle dimensions are " << sum.getLength() << " and " << sum.getWidth() << endl;

    //tests == operator
    if (r1 == r2)
        cout << "r1 is the same as r2" << endl;
    else   
        cout << "r1 is not the same as r2" << endl;
    //tests != operator
    if (r1 != r2)
        cout << "r1 is not equal to r2" << endl;
    else   
        cout << "r1 is equal to r2" << endl;
    //tests <= operator
    if (r1 <= r2)
        cout << "r1 is less than or equal to r2" << endl;
    else   
        cout << "r1 is greater than r2" << endl;
    //tests < operator
    if (r1 < r2)
        cout << "r1 is less than r2" << endl;
    else   
        cout << "r1 is greater than r2" << endl;
    //tests >= operator
    if (r1 >= r2)
        cout << "r1 is greater than or equal to r2" << endl;
    else   
        cout << "r1 is less than r2" << endl;
    //tests > operator
    if (r1 > r2)
        cout << "r1 is greater than r2" << endl;
    else   
        cout << "r1 is less than r2" << endl;

    //Waits for input to close program
    char q;
    cout << "\nPress any key to Exit.";
    cin.ignore(2, '\n');
    cin.get(q);

    return 0;
}