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

using namespace std;

int main()
{
	//Header
    cout << endl << "William Laffey\t"
         << "L1-1\t"
         << "L1-1.exe" << endl;

    //declarations
    int dice, sum;
    int largestNum = 0;
    long rolls;
    int array[36] = {0};
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

    //rolls dice (got help from Bailey Nichols)
    for (int i = 0; i < rolls; i++)
    {
        for (int j = 0; j < dice; j++)
        {
            die.roll();
            sum = sum + die.getNum();
        }
        array[sum] += 1;
        sum = 0;
    }

    //determines largest number for bar graph
    for (int y = 0; y < (dice * 6 + 1); y++) 
    {
        if (array[y] > largestNum)
        {
            largestNum = array[y];
        }
    }

    cout << "For " << dice << " dice, rolled " << rolls << " times" << endl;
    cout << "Count %:---   0    10   20   30   40   50   60   70   80   90   100" << endl;
    cout << "Sum    count  |....|....|....|....|....|....|....|....|....|....|" << endl;

    //displays sum and count
    for (int k = 0; k < (dice * 6 + 1); k++)
    {
        cout << " "   << setw(2) << k ;
        cout << "  (" << setw(4) << array[k] << ")   ";
        for (float l = 0; l < (array[k] / largestNum); l = l + .02) 
        {
            cout << "*";
        }
        cout << endl;
    }

    //Waits for input to close program
    char q;
    cout << "\nPress any key to Exit.";
    cin.ignore(2, '\n');
    cin.get(q);

    return 0;
}
// Sum    count  |....|....|....|....|....|....|....|....|....|....|