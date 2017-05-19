/*****************************************************************************************

Author: Stephen Townsend
Date: 10/23/2016
Description: This is the Menu.cpp.  This is used to instruct the user so that they can 
start theprogram. It also includes a set of input validations for parameter of the grid and
the X and Y coordinates for the ants location.

*****************************************************************************************/


#include "Menu.hpp"

int main()
{
	char mChoice = 0;

	menu(mChoice);
}

/*****************************************************************************************
**										menu()
**  This is the menu function.  It will prompt the user for various options
*****************************************************************************************/
void menu(char mChoice)
{
	do
	{
		cout << "::Choose an Option::" << endl;
		cout << "1: Reverse a string" << endl;
		cout << "2: Calculate the sum of an array" << endl;
		cout << "3: Calculate the triangular number for N" << endl;
		cout << "Q: Exit" << endl;
		cin >> mChoice;

		mChoice = tolower(mChoice);

		clearBuffer();

		if (mChoice == 49)
		{
			string userString;
			cout << "\nEnter a string to be reversed: ";
			getline(cin, userString);

			userString = revString(userString);

			cout << "\nThe string is now " << userString << endl << endl;
		}
		else if (mChoice == 50)
		{
			int userSum = 0;
			int counter = 1;
			int i = 0;
			int* array = new int[counter];
		
			cout << "\nEnter any char when finished ex: Q " << endl
				 << "Please enter your values" << endl;
			do
			{
				if (!cin.fail())
				{
					for (i; i < counter; i++)
					{
						cin >> array[i];
					}
					
					counter++;
				}
			}
			while (!cin.fail());

			counter -= 2;

			clearBuffer();

			userSum = calcSum(array, counter);

			cout << "\nThe sum is " << userSum << endl << endl;;
		}
		else if (mChoice == 51)
		{
			int userPins = 0;
			cout << "\nPlease enter an integer: ";
			cin >> userPins;
			clearBuffer();

			userPins = triangNumber(userPins);

			cout << "\nThe triangle is: " << userPins << endl << endl;

		}

		else if (mChoice != 'q')
		{
			cout << "\nPlease enter 1, 2, 3 or Q: " << endl << endl;
		}
	}
	while (mChoice != 'q');
}

void clearBuffer()
{
	cin.clear(); //clear buffer error
	cin.ignore(100, '\n'); //clear the input buffer
}