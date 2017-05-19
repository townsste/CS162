/****************************************************************************
** Program Filename: Final Project
** Author: Stephen Townsend
** Date: 12/6/16
** Description: This is the Library.cpp. This uses class specific functions
** Input: None
** Output: None
*****************************************************************************/

#include "Library.hpp"

/****************************************************************************
** Function: Library()
** Description: Default Constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

Library::Library()
{
}

/****************************************************************************
** Function: Library(string loc)
** Description: 1 parameter constructor.  Uses Hospital constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

Library::Library(string loc) : Hospital(loc)
{
}

/****************************************************************************
** Function: choices()
** Description: Used to display player menu options
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/
void Library::choices()
{
	if (action == 0)
	{
		story();
	}
	
	if (action == 1)
	{
		cout << "What will you do?" << endl;
		cout << "    1. Open the door" << endl
			<< "    2. Go Back" << endl;
	}

	if (action == 3)
	{
		cout << "As you enter you see someone sitting at a table with a reference book opened." << endl
			<< "You take a harder look and see that it is a Lab Scientist." << endl << endl;

		cout << "What do you do?" << endl
			<< "     1. Talk to them and hope they are friendly." << endl
			<< "     2. Go Back" << endl;
	}
}

/****************************************************************************
** Function: useItem()
** Description: Uses an item if there is one and sets to empty
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

void Library::useItem()
{
	if (getItem().compare("key") == 0)
	{
		bag = "EMPTY";
		action = 2;
	}
}

/****************************************************************************
** Function: setItem(string item)
** Description: Uses an item if there is one and sets to empty
** Parameters: String item
** Pre-Conditions: Set item from main
** Post-Conditions: None
** Return: None
*****************************************************************************/

void Library::setItem(string item)
{
	bag = item;
}

/****************************************************************************
** Function: getItem()
** Description: Returns the stored item to the calling function
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: bag
*****************************************************************************/

string Library::getItem()
{
	return bag;
}

/****************************************************************************
** Function: getRoom()
** Description: Returns the room name
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: position
*****************************************************************************/

string Library::getRoom()
{
	return position;
}

/****************************************************************************
** Function: somethingHappens(int choice)
** Description: This is the action of the class that is based onn the menu
** Parameters: int choice
** Pre-Conditions: User selected an option to run
** Post-Conditions: The result is played out
** Return: Bool
*****************************************************************************/

bool Library::somethingHappens(int choice)
{
	//Action 1
	if (choice == 1)
	{
		useItem();

		if (action == 1)
		{
			cout << "The door is locked" << endl << endl;
			return false;
		}
		else if (action == 2)
		{
			cout << "The key from the admissions desk opened the door to the Library" << endl << endl;
			action = 3;
			return false;
		}
		if (action == 3)
		{
			cout << "You talk with the Lab Scientist and tell them your situtaion." << endl
				<< "As a result, they decide that they would like to help you." << endl
				<< "You recieved the Lab Keycard" << endl << endl;

			cout << "You walked out of the library and the door lock behind you." << endl << endl;
			bag = "Lab Keycard";
			action = 0;
			return true;
		}	
	}
	else if (choice == 2)
	{
		cout << "Back to the hall" << endl << endl;
		action--;
		return true;
	}
	cout << "Please enter a valid choice" << endl << endl;
}

/****************************************************************************
** Function: setLocation()
** Description: Sets the rooms name
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The room is named
** Return: None
*****************************************************************************/

void Library::setLocation()
{
	position = "Library";
}

/****************************************************************************
** Function: setDead()
** Description: The player dies.
** Parameters: None
** Pre-Conditions: Player dies in game
** Post-Conditions: Status updates to dead
** Return: None
*****************************************************************************/

void Library::setDead()
{
	state = DEAD;
}

/****************************************************************************
** Function: getState()
** Description: Returns the player state. Alive or Dead
** Parameters: None
** Pre-Conditions: Player state
** Post-Conditions: None
** Return: STATUS state
*****************************************************************************/

STATUS Library::getState()
{
	return state;
}

/****************************************************************************
** Function: story()
** Description: The room first transition story
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

void Library::story()
{
	action++;

	cout << "The Door Reads : Library" << endl << endl;
}
