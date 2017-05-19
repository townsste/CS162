/****************************************************************************
** Program Filename: Lab 6
** Author: Stephen Townsend
** Date: 11/6/16
** Description:  This is the Menu.cpp.  It allows the user to make a choice
**					for what function they want to run.
** Input: Enter a choice for what you want to do in the function.
** Output: The options for a specific function task.
*****************************************************************************/

#include "Menu.hpp"

/****************************************************************************
** Function: void menu()
** Description: Choose what task you wan to run for the function chosen.
** Parameters: string choice.
** Pre-Conditions: Use valid choice input from main.
** Post-Conditions: A chice of 1, 2, or 3 must be entered before proceeding
** Return: Nothing
*****************************************************************************/
void menu(string choice)
{
	string toDo;
	string input;


	if ((choice.compare("1")) == 0) //Choice from main to run stack
	{
		Stack item;

		while (toDo.compare("3") != 0)
		{
			cout << "\n1. Add" << endl
				<< "2. Remove" << endl
				<< "3. Exit to main" << endl
				<< "Choice: ";
			getline(cin, toDo);


			if (toDo.compare("1") == 0) //Add to Stack
			{
				cout << "\nPlease enter a string: "; //Input into stack
				getline(cin, input);

				item.push(input); //Add item to stack (pass input)
			}

			else if (toDo.compare("2") == 0) //Remove from Stack
			{
				if (item.checkStack() == false) //Check if there is an item already in queue
					cout << "Nothing in stack" << endl; //Inform user if stack is empty

				else
					item.pop(); //Item in stack. Run to remove item.
			}
			else if (toDo.compare("3") == 0) //Exit loop and back to main
				cout << endl; //Output a new line for aesthetics

			else
				cout << "\nPlease enter a valid choice" << endl;
		}
	}
	else if ((choice.compare("2")) == 0) //Choice from main to run queue
	{
		Queue item;

		while (toDo.compare("3") != 0)
		{
			cout << "\n1. Add" << endl
				<< "2. Remove" << endl
				<< "3. Exit to main" << endl
				<< "Choice: ";
			getline(cin, toDo);


			if (toDo.compare("1") == 0) //Add to Queue
			{
				cout << "\nPlease enter a string: "; //Input into queue
				getline(cin, input);

				item.push(input); //Add item to queue (pass input)
			}

			else if (toDo.compare("2") == 0) //Remove from queue
			{
				if (item.checkQueue() == false) //Check if there is an item already in queue
					cout << "Nothing in queue" << endl; //Inform user if queue is empty

				else
					item.pop(); //Item in queue. Run to remove item.
			}
			else if (toDo.compare("3") == 0) //Exit loop and back to main
				cout << endl; //Output a new line for aesthetics

			else
				cout << "\nPlease enter a valid choice" << endl; //Input not valid
		}
	}
}