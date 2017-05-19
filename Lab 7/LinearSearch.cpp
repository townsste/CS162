/****************************************************************************
** Program Filename: Lab 7
** Author: Stephen Townsend
** Date: 11/13/16
** Description: This is the LinearSearch.cpp.  This program is used to preform
**		a Linear search from data inside a text file that the user selected.
**
** Obtained: Page 596 from "Starting out with C++ Early Objects 8th Edition"
**
** Input: None
** Output: The position of the searched integer.
*****************************************************************************/

#include "LinearSearch.hpp"

/****************************************************************************
** Function: void linearSearch()
** Description: Runs a linear search from user selected txt file.
** Parameters: array pointer, int, count, int search.
** Pre-Conditions: Every option was valid.
** Post-Conditions: Outputs the positon of the searched integer in the file.
** Return: Nothing
*****************************************************************************/
void linearSearch(int *arrPtr, int count, int search)
{
	int position = 1;
	bool found = false;

		for (int j = 0; j < count; j++)
	{
		if (search == arrPtr[j]) //LINEAR SEARCH OBTAINED from book
		{
			cout << "\nFound " << search << " in position " << position << endl << endl;
			found = true;
		}
		else
			position++; //Check next position
	}
	
	if (found == false) //Not found Output
		cout << endl << search << " was not found in the search." << endl << endl;
}