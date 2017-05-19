/****************************************************************************
** Program Filename: Lab 6
** Author: Stephen Townsend
** Date: 11/6/16
** Description: This is the Main.cpp.
** Input: Enter a choice for the menu
** Output: Outputs the options to make a choice for which function you want 
**			   to run.
*****************************************************************************/

#include "Menu.hpp"

#include <string>
#include <iostream>
using namespace std;

/****************************************************************************
** Function: int main()
** Description: Starting point for the program.
** Parameters: int input 1, 2, or 3
** Pre-Conditions: None
** Post-Conditions: A choice of 1, 2, or 3 must be entered before proceeding
** Return: Zero to end program.
*****************************************************************************/
int main()
{
	string choice;

	while (choice.compare("3") != 0) // If 3 then exit
	{
		cout << "1. Stack" << endl
			<< "2. Queue" << endl
			<< "3. Exit" << endl
			<< "Choice: ";
		getline(cin, choice);

		if (choice.compare("1") == 0 || choice.compare("2") == 0) //If valid input
			menu(choice); //Proceeds to program
		
		else if (choice.compare("3") == 0)
			cout << endl;
		else

			cout << "\nPlease enter a valid option" << endl << endl; //Input not valid
	}
	return 0;
}