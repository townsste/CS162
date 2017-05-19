/*****************************************************************************************

Author: Stephen Townsend
Date: 10/16/2016
Description: This is the Dice.hpp.  This is used to create the dice class and hold
information about the dice.  This is the base class for the LoadedDice class.

*****************************************************************************************/

#ifndef DICE_HPP
#define DICE_HPP

#include <iostream>
#include <ctime>

using namespace std;

class Dice
{
protected:
	int diceSides;

public:
	void setDiceSides(int);
	int roll();
	void getDiceSides();
	
//Default Constructor
	Dice();
};
#endif // !DICE_HPP