/*****************************************************************************************

Author: Stephen Townsend
Date: 10/08/2016
Description: This is the Menu.cpp.  This is used to instruct the user so that they can 
start theprogram. It also includes a set of input validations for parameter of the grid and
the X and Y coordinates for the ants location.

*****************************************************************************************/


#include "Menu.hpp"

/*****************************************************************************************
**										menu()
**  This is the menu function.  It will prompt the user for various options
*****************************************************************************************/
void menu(char choice)
{	
	int rowChoice = 40;
	int colChoice = 40;
	int startX;
	int startY;
	int steps;

	while (choice > 50)
	{
		cout << "Choice '" << choice << "' in not valid. "
			 << "Please enter 1 or 2: ";
		cin >> choice;
	}

	if (choice == 49)
	{
		cout << "\n::Choose Location::" << endl;

		cout << "How many rows are in the grid? (ex 40): ";
		cin >> rowChoice;

		rowChoice = paraInputValidation(rowChoice); //Input Validation Check

		cout << "How many columns are in the grid? (ex 40): ";
		cin >> colChoice;

		colChoice = paraInputValidation(colChoice); //Input Validation Check
		
		cout << "Starting X: (ex 20): ";
		cin >> startX;
		
		startX = locInputValidation(startX, rowChoice); //Input Validation Check

		cout << "Starting Y: (ex 20): ";
		cin >> startY;
		
		startY = locInputValidation(startY, colChoice); //Input Validation Check
		
	}

	else if (choice == 50)
	{
		int lowRange = 10;  //Lower bounds to be within the set size
		int upRange = 30;  //Upper bounds to be within the set size

		srand(time(0)); //creates a seed

		startX = rand() % (upRange - lowRange + 1) + lowRange;  //Set a random X location
		startY = rand() % (upRange - lowRange + 1) + lowRange;	//Set a random Y location
		
		cout << "\n::Random Location::" << endl;
		cout << "X: " << startX << ", Y: " << startY << endl;
	}

	cout << "\nLast question, how many steps would like your ant to take? (ex 3000): ";
	cin >> steps;


	AntGrid gridObj(rowChoice, colChoice);  //Create an AntGrid object with row and col

	gridObj.setGrid(rowChoice, colChoice); //Call to set the grid size
	
	gridObj.setLocation(startX, startY); //Call to set the ants location
		
	gridObj.setSteps(steps); //Call to set the ants steps

	gridObj.move(); //Call to get the program running. Move the ant.
}



/*****************************************************************************************
**								paraInputValidation()
**  Checks the users parameter input
*****************************************************************************************/
int paraInputValidation(int userChoice)
{
	while (userChoice > 61 || userChoice < 19)
	{
			cout << "The minimum is 20 and max is 60: " 
				 << "Pleease choose a new value: ";
			cin >> userChoice;
	}
		return userChoice;
}



/*****************************************************************************************
**								locInputValidation()
**  Checks the users location input
*****************************************************************************************/
int locInputValidation(int loc, int para)
{
	int paraUpper = para - (para * 0.3);
	int paraLower = para * 0.3;

	while (loc > paraUpper || loc < paraLower)
	{
			cout << "\nBased on your parameter, " << loc << " will not work."
				<< " the min will be " << paraLower
				<< " the max will be " << paraUpper << " :";
			cin >> loc;
	}
	
	return loc;
}