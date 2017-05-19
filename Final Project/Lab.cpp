/****************************************************************************
** Program Filename: Final Project
** Author: Stephen Townsend
** Date: 12/6/16
** Description: This is the Lab.cpp. This uses class specific functions
** Input: None
** Output: None
*****************************************************************************/

#include "Lab.hpp"

/****************************************************************************
** Function: Lab()
** Description: Default Constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

Lab::Lab()
{
}

/****************************************************************************
** Function: Lab(string loc)
** Description: 1 parameter constructor.  Uses Hospital constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

Lab::Lab(string loc) : Hospital(loc)
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

void Lab::choices()
{
	if (action == 0)
	{
		story();
	}	

	cout << "What will you do?" << endl;
	cout << "    1. Open the door" << endl
		 << "    2. Go Back" << endl;
}

/****************************************************************************
** Function: useItem()
** Description: Uses an item if there is one and sets to empty
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

void Lab::useItem()
{
	if (getItem().compare("Lab Keycard") == 0)
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

void Lab::setItem(string item)
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

string Lab::getItem()
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

string Lab::getRoom()
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

bool Lab::somethingHappens(int choice)
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
			cout << "The keycard opened the doors to the lab" << endl;
			setDead();
			return false;
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

void Lab::setLocation()
{
	position = "Lab";
}

/****************************************************************************
** Function: setDead()
** Description: The player dies.
** Parameters: None
** Pre-Conditions: Player dies in game
** Post-Conditions: Status updates to dead
** Return: None
*****************************************************************************/

void Lab::setDead()
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

STATUS Lab::getState()
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

void Lab::story()
{
	action++;

	cout << "The Door Reads : Laboratory (Restricted Access)" << endl << endl;
}