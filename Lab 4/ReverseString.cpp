/*****************************************************************************************

Author: Stephen Townsend
Date: 10/23/2016
Description: This is the ReverseString cpp.  This is used to reverse a string through 
recursion.  It accapts an input from the menu.

*****************************************************************************************/

#include "ReverseString.hpp"

string revString(string toReverse)
{
	if (toReverse.length() == 1)
	{
		return toReverse;
	}
	else
	{
		return revString(toReverse.substr(1, toReverse.length())) + toReverse.at(0); //Recursion
	}
}