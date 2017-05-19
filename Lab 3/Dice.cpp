/*****************************************************************************************

Author: Stephen Townsend
Date: 10/16/2016
Description: This is the Dice.cpp.  It holds information for a normal die.

*****************************************************************************************/

#include "Dice.hpp"

/*****************************************************************************************
**										Dice()
**  Initialize dice sides to 0 and creates a seed for creating a random number generator 
**  based on the dice sides value.
*****************************************************************************************/
Dice::Dice()
{
	diceSides = 0;
	srand(time(0)); //creates a seed for rolling
}

/*****************************************************************************************
**									setDiceSides()
**  
*****************************************************************************************/
void Dice::setDiceSides(int die)
{
	diceSides = die;
}

/*****************************************************************************************
**										roll()
**  This is the roll function.  This is used to roll a normal die.
*****************************************************************************************/
int Dice::roll()
{
	return (rand() % diceSides) + 1; //generates a random value between 1 & n
}

/*****************************************************************************************
**									getDiceSides()
**  
*****************************************************************************************/
void Dice::getDiceSides()
{
	cout << "Side " << diceSides << endl;

}