#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
class die
{
public:
    die()
    {
        num = 1;
    }
    //Default constructor
    //Sets the default number rolled by a die to 1

    void roll();
    //Function to roll a die.
    //This function uses a random number generator to randomly
    //generate a number between 1 and 6, and stores the number
    //in the instance variable num.

    int getNum() const;
    //Function to return the number on the top face of the die.
    //Returns the value of the instance variable num.

private:
    int num; //The value of this instance ( 1 through 6) variable num.
};

void die::roll()
{
        srand(time(0));
        num = (rand() % 6 + 1);
}

int die::getNum() const
{
    return num;
}