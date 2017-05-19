/*****************************************************************************************

Author: Stephen Townsend
Date: 10/16/2016
Description: This is the LoadedDice.hpp.  This is used to create the loaded dice class and hold
information about the dice.  LoadedDice inherits from the dice class.

*****************************************************************************************/

#ifndef LOADEDDICE_HPP
#define LOADEDDICE_HPP

#include "Dice.hpp"


class LoadedDice : public Dice
{
private:
	//int diceSides;		  from base class

public:
	int loadWeightRoll();

	//void setDiceSides(int); from base class
	//int roll();			  from base class
	//void getDiceSides();    from base class
};
#endif // !LOADEDDICE_HPP