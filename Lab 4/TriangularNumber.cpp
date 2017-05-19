/*****************************************************************************************

Author: Stephen Townsend
Date: 10/23/2016
Description: This is the TriangularNumber cpp.  This is used to output the triangular of 
a number through recursion.  It accapts an input from the menu.

*****************************************************************************************/

#include "TriangularNumber.hpp"

int triangNumber(int pins)
{
	if (pins <= 0)
		return 0;
	else
		return pins + triangNumber(pins - 1);  //Recursion
}


