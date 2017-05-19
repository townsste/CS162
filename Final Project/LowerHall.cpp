/****************************************************************************
** Program Filename: Final Project
** Author: Stephen Townsend
** Date: 12/6/16
** Description: This is the LowerHall.cpp. This uses class specific functions
** Input: None
** Output: None
*****************************************************************************/

#include "LowerHall.hpp"

/****************************************************************************
** Function: LowerHall()
** Description: Default Constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

LowerHall::LowerHall()
{
}

/****************************************************************************
** Function: LowerHall(string loc)
** Description: 1 parameter constructor.  Uses Hospital constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

LowerHall::LowerHall(string loc) : Hospital(loc)
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

void LowerHall::choices()
{
	if (action == 0)
		story();
		
	action++;

	if (action == 2)
	{
		cout << "Which hall will take?" << endl;
		cout << "     1. Front Doors" << endl
			 << "     2. Laboratory" << endl
			 << "     3. Library" << endl;
	}
	if (action == 3)
	{
		cout << "Back in the Hall" << endl << endl;
		cout << "Which hall will take?" << endl;
		cout << "     1. Front Doors" << endl
			 << "     2. Laboratory" << endl
			 << "     3. Library" << endl;
		action--;
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

void LowerHall::useItem()
{
	bag = "EMPTY";
}

/****************************************************************************
** Function: setItem(string item)
** Description: Uses an item if there is one and sets to empty
** Parameters: String item
** Pre-Conditions: Set item from main
** Post-Conditions: None
** Return: None
*****************************************************************************/

void LowerHall::setItem(string item)
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

string LowerHall::getItem()
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

string LowerHall::getRoom()
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

bool LowerHall::somethingHappens(int choice)
{
	return true;
}

/****************************************************************************
** Function: setLocation()
** Description: Sets the rooms name
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The room is named
** Return: None
*****************************************************************************/

void LowerHall::setLocation()
{
	position = "LowerHall";
}

/****************************************************************************
** Function: setDead()
** Description: The player dies.
** Parameters: None
** Pre-Conditions: Player dies in game
** Post-Conditions: Status updates to dead
** Return: None
*****************************************************************************/

void LowerHall::setDead()
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

STATUS LowerHall::getState()
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

void LowerHall::story()
{
	action++;

	cout << "\nYou were able to make it to the bottom floor." << endl;
	cout << "As you start walking down the hall you see a sign that shows three halls. Front Doors, Laboratory, and Library." << endl << endl;
}