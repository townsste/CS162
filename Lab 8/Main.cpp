/****************************************************************************
** Program Filename: Lab 8
** Author: Stephen Townsend
** Date: 11/20/16
** Description: This is the Main.cpp.
** Input: Enter a choice for the menu
** Output: Outputs the options to make a choice for which function you want 
**			   to run.
*****************************************************************************/

#include "Queue.hpp"

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

/****************************************************************************
** Function: int main()
** Description: Starting point for the program.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: A choice of 1, 2, 3, 4, or 5 must be entered before 
						proceeding
** Return: Zero to end program.
*****************************************************************************/
int main()
{
	string choice;
	string check;
	int input = 0;
	Queue item;

	while (choice.compare("5") != 0)
	{
		cout << "1. Add" << endl
			 << "2. Remove" << endl
		 	 << "3. Display first node" << endl
			 << "4. Display the queue contents" << endl
			 << "5. Exit to main" << endl
			 << "Choice: ";
		getline(cin, choice);

		if (choice.compare("1") == 0) //Add to Queue
		{
			cout << "\nPlease enter an int: "; //Input into queue

			while (getline(cin, check))
			{
				stringstream test(check); //Stream string object to test
				test >> input; //Push string object into int

				if (test.eof()) //if end of string and valid then
					break; //Exit loop
				else
					cout << "Please enter an integer: "; //String not valid
			}

			item.addBack(input); //Add item to queue (pass input)

			cout << "\nSuccessfully Added\n" << endl;
		}

		else if (choice.compare("2") == 0) //Remove from queue
		{
			item.removeFront(); //Item in queue. Run to remove item.
		}
		else if (choice.compare("3") == 0) //Exit loop and back to main
		{
			if (item.getFront() != -1)
				cout << endl << item.getFront() << endl << endl;
			else
				cout << "\nThe queue is empty\n" << endl;
		}
		else if (choice.compare("4") == 0) //Display the queue contents
		{
			item.displayEntireQueue();
		}
		else if (choice.compare("5") == 0) //Exit loop and back to main
			return 0;
		else
			cout << "\nPlease enter a valid choice" << endl << endl; //Input not valid
	}
	item.cleanup(); //Clean everything up to prevent memory leak
}