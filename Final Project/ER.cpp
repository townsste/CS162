/****************************************************************************
** Program Filename: Final Project
** Author: Stephen Townsend
** Date: 12/6/16
** Description: This is the ER.cpp. This uses class specific functions
** Input: None
** Output: None
*****************************************************************************/

#include "ER.hpp"

/****************************************************************************
** Function: ER()
** Description: Default Constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/
ER::ER()
{
}

/****************************************************************************
** Function: ER(string loc)
** Description: 1 parameter constructor.  Uses Hospital constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

ER::ER(string loc) : Hospital(loc)
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

void ER::choices()
{
	cout << "1. Be admitted." << endl;
	cout << "2. I am fine and want to leave." << endl;
}

/****************************************************************************
** Function: useItem()
** Description: Uses an item if there is one and sets to empty
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

void ER::useItem()
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

void ER::setItem(string item)
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

string ER::getItem()
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

string ER::getRoom()
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

bool ER::somethingHappens(int choice)
{
	if (choice == 1)
	{
		cout << "Nurse: " << endl
			<< "     Thank you for your consent. We will do our best to make you comfortable." << endl;
		
		story();
		return true;
	}
	else if (choice == 2)
	{
		cout << "Nurse: " << endl
			<< "     I am sorry but you are in no condition to leave in your current state." << endl;
		
		story();
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

void ER::setLocation()
{
	position = "ER";
}

/****************************************************************************
** Function: setDead()
** Description: The player dies.
** Parameters: None
** Pre-Conditions: Player dies in game
** Post-Conditions: Status updates to dead
** Return: None
*****************************************************************************/

void ER::setDead()
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

STATUS ER::getState()
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

void ER::story()
{
	cin.get();

	cout << "As the nurse leaves the room you hear the nurse and doctor whispering about you." << endl
		 << "Another nurse comes in and administers something into your IV line" << endl
		 << "You start to feel very dizzy and as you fade out of conciousness" << endl
		 << "you over hear the doctor whispering a person's organs with this condition sells for" << endl
		 << "alot of money to research facilities." << endl;

	cin.get();

	cout << "----------------------------------------------------------------------------------" << endl
		<< "GOAL:: Try to Escape to the Laboratory and try not to die" << endl
		<< "----------------------------------------------------------------------------------" << endl;

	cin.get();
}
