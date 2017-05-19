/****************************************************************************
** Program Filename: Lab 7
** Author: Stephen Townsend
** Date: 11/13/16
** Description: This is the BubbleSort.cpp.  This program is used to preform
**		a bubble sort from data inside a text file that the user selected.
**
** Obtained: Page 607 from "Starting out with C++ Early Objects 8th Edition"
**
** Input: None
** Output: The sorted file data.
*****************************************************************************/

#include "BubbleSort.hpp"

/****************************************************************************
** Function: void bubbleSort()
** Description: Runs a bubble sort from user selected txt file.
** Parameters: array pointer, int, count, int search.
** Pre-Conditions: Every option was valid.
** Post-Conditions: Outputs the sorted integers and outputs them in a new txt.
** Return: Nothing
*****************************************************************************/
void bubbleSort(int *arrPtr, int count, int search) 
{
	ofstream outputText;
	string name;
	int temp;
	bool swap;

	cout << endl << "\nPlease name your sorted file followed by .txt (ex sort.txt): " << endl
		<< "Name: ";
	getline(cin, name);

	outputText.open(name); //Open Output Text File
	
	//BUBBLE SORT OBTAINED from book
	do
	{
		swap = false;
		for (int i = 0; i < (count - 1); i++)
		{
			if (arrPtr[i] > arrPtr[i + 1])
			{
				temp = arrPtr[i];
				arrPtr[i] = arrPtr[i + 1];
				arrPtr[i + 1] = temp;
				swap = true;
			}
		}
	} while (swap); //Loop again if a swap occurred on this pass.

	cout << endl;

	for (int j = 0; j < count; j++)
	{
		cout << right << setw(3) << arrPtr[j] << " "; //Output sorted array integers
		outputText << arrPtr[j] << endl; //Write to user file.txt
	}

	cout << " Sorted Data" << endl << endl;

	outputText.close(); //Close Output Text File
}