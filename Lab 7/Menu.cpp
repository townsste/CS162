/****************************************************************************
** Program Filename: Lab 7
** Author: Stephen Townsend
** Date: 11/13/16
** Description:  This is the Menu.cpp.  It allows the user to make a choice
**					for what function they want to run.
** Input: None
** Output: None
*****************************************************************************/

#include "Menu.hpp"

/****************************************************************************
** Function: void menu()
** Description: Calls the function that the user wasnts to run from main.
** Parameters: array pointer, int, count, int search, string choice.
** Pre-Conditions: Use valid choice input from main.
** Post-Conditions: A choice of 1, 2, or 3 must be entered before proceeding
** Return: Nothing
*****************************************************************************/
void menu(int *arrPtr, int count, int search, string choice)
{
	if (choice.compare("1") == 0)
	{
		newSearch(search); //Call to choose search option
		linearSearch(arrPtr, count, search); //Linear Search function call
	}
	else if (choice.compare("2") == 0)
	{
		bubbleSort(arrPtr, count, search); //Bubble Sort function call
	}
	else if (choice.compare("3") == 0)
	{
		newSearch(search); //Call to choose search option
		binarySearch(arrPtr, count, search); //Binary Search function call
	}
	else
		cout << "Invalid Choice" << endl; //Choice error output
}

/****************************************************************************
** Function: void menuInputVal()
** Description: Check to make sure valid menu option is selected
** Parameters: string &check.
** Pre-Conditions: Use choice input from main to validate.
** Post-Conditions: Validated menu choice
** Return: Nothing
*****************************************************************************/
void menuInputVal(string &check)
{
	while (check.compare("1") != 0 && check.compare("2") != 0 &&  //Check input is 1 - 3
		check.compare("3") != 0 && check.compare("4") != 0)
	{
		cout << "Please enter a valid menu choice: ";
		getline(cin, check);
	}
}

/****************************************************************************
** Function: void yesOrNoValidation()
** Description: Choose what task you wan to run for the function chosen.
** Parameters: string &test.
** Pre-Conditions: Use choice input from main to validate Y or N response
** Post-Conditions: A valid Y or N to continue or chose what to search.
** Return: Nothing
*****************************************************************************/
void yesOrNoValidation(string &test)
{
	while (test.compare("Y") != 0 && test.compare("y") != 0 && test.compare("N") != 0 && test.compare("n") != 0) //Loop till valid input
	{
			cout << "Please enter a valid response: ";
			getline(cin, test);
	}
}

/****************************************************************************
** Function: void newSearch()
** Description: Choose what task you wan to run for the function chosen.
** Parameters: string &search.
** Pre-Conditions: None
** Post-Conditions: User will chose a different search option then default 0
** Return: Nothing
*****************************************************************************/
void newSearch(int &search)
{
	string searchOveride;

	cout << endl << "\nWould you like to search a specific integer? Y / N"
		<< endl << search << " is default: ";
	getline(cin, searchOveride);

	yesOrNoValidation(searchOveride); //Call to check if input is Y or N

	if (searchOveride.compare("Y") == 0 || searchOveride.compare("y") == 0) //If yes then ask for search
	{
		cout << "\nPlease enter the integer to search for: ";
		cin >> search;

		while (cin.fail()) //Loop if not valid int
		{
			cout << "Please enter an integer: ";
			cin.clear(); //Clear cin flag
			cin.ignore(100, '\n'); //Ignore any chars in buffer
			cin >> search;
		}
			cin.ignore(100, '\n');
	}
	cout << "\nSearching for " << search << endl; //This is the new search
}