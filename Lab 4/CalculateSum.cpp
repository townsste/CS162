/*****************************************************************************************

Author: Stephen Townsend
Date: 10/23/2016
Description: This is the CalculateSum cpp.  This is used to calculate the sum of the user 
input in an array through recursion.  It accapts an input from the menu.

*****************************************************************************************/

#include "CalculateSum.hpp"

#include <iostream>

using namespace std;

int calcSum(int *pArray, int counter)
{
	if (counter <= 0)
		return 0;
	else
		return pArray[0] + calcSum(pArray + 1, counter - 1); //Recursion
}