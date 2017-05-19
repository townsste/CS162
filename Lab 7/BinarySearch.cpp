/****************************************************************************
** Program Filename: Lab 7
** Author: Stephen Townsend
** Date: 11/13/16
** Description: This is the BinarySearch.cpp.  This program is used to preform
**		a binary search from data inside a text file that the user selected.
**
** Obtained: Page 599 from "Starting out with C++ Early Objects 8th Edition"
**
** Input: None
** Output: The position of the searched integer.
*****************************************************************************/

#include "BinarySearch.hpp"

/****************************************************************************
** Function: void binarySearch()
** Description: Runs a binary search from user selected txt file.
** Parameters: array pointer, int, count, int search.
** Pre-Conditions: Every option was valid.
** Post-Conditions: Outputs the positon of the searched integer in the file.
** Return: Nothing
*****************************************************************************/
void binarySearch(int *arrPtr, int count, int search) //BINARY SEARCH OBTAINED from book
{
	int first = 0,											//First array element
		last = count - 1,									//Last array element
		middle,												//Midpoint of search
		position = -1;										//Position of search value
	bool found = false;										//Flag
	
	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (arrPtr[middle] == search)
		{
			position = middle;
			
			cout << "\nFound " << search << " in position " << position + 1 << endl << endl;
			found = true;
		}
		else if (arrPtr[middle] > search)					 //If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;								//If value is in upper half
	}
	if (found == false) //Not found Output
		cout << endl << search << " was not found in the search." << endl << endl;
}