/*****************************************************************************************

Author: Stephen Townsend
Date: 10/16/2016
Description: This is the LoadedDice.cpp.  It holds information for a loaded die.

*****************************************************************************************/

#include "LoadedDice.hpp"

/*****************************************************************************************
**										loadWeightRoll()
**  This is used to roll the weighted dice. The calculation is going to set the min 1/2
**  of diceSides.
*****************************************************************************************/
int LoadedDice::loadWeightRoll()
{
	return rand() % (diceSides - (diceSides / 2) + 1) + (diceSides / 2);
}