/****************************************************************************
** Program Filename: Final Project
** Author: Stephen Townsend
** Date: 12/6/16
** Description: This is the IP.cpp. This uses class specific functions
** Input: None
** Output: None
*****************************************************************************/

#include "IP.hpp"

/****************************************************************************
** Function: IP()
** Description: Default Constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

IP::IP()
{
}

/****************************************************************************
** Function: IP(string loc)
** Description: 1 parameter constructor.  Uses Hospital constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

IP::IP(string loc) : Hospital(loc)
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

void IP::choices()
{
	if (action == 0)
		story();
	
	action++;

	cout << "What will you do?" << endl;
	cout << "     1. Turn Lights on" << endl;
	cout << "     2. Searh the room in the dark." << endl;
}

/****************************************************************************
** Function: useItem()
** Description: Uses an item if there is one and sets to empty
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

void IP::useItem()
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

void IP::setItem(string item)
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

string IP::getItem()
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

string IP::getRoom()
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

bool IP::somethingHappens(int choice)
{
	if (choice == 1)
	{
		cout << "The nurses notice the lights turn on and come barging in and yell." << endl
			<< "You are going to be too much trouble.  Luckily we dont need you alive for our plans." << endl << endl
			<< "So they restrain you to the bed and inject you with potassium chloride." << endl << endl
			<< "Your chest feels like it is burning and in a few moments your heart starts to slow and then stops." << endl << endl;

		cout << "YOU HAVE ENTERED CARDIAC ARREST AND DIED!!" << endl
			<< "By lethal injection." << endl << endl;

		setDead();
		return false;
	}
	
	if (choice == 2)
	{
		cout << "You searched the room and found" << endl
			 << "     A Blood Pressure Cuff." << endl;

		bag = "Blood Pressure Cuff";

		cout << "\nYou have successfully retreived the item." << endl << endl;
		cout << "You then quietly sneak out of the room undetected." << endl << endl;
		return true;
	}
	cout << "Please enter a valid choice" << endl << endl;
	action--;
}

/****************************************************************************
** Function: setLocation()
** Description: Sets the rooms name
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The room is named
** Return: None
*****************************************************************************/

void IP::setLocation()
{
	position = "IP";
}

/****************************************************************************
** Function: setDead()
** Description: The player dies.
** Parameters: None
** Pre-Conditions: Player dies in game
** Post-Conditions: Status updates to dead
** Return: None
*****************************************************************************/

void IP::setDead()
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

STATUS IP::getState()
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

void IP::story()
{
	action++;

	cout << "As you start regaining conciousness you find yourself" << endl
		<< "in a dark room that is very quiet. You try to remember what the Doctor said." << endl << endl
		<< "Now that you are awake" << endl << endl;
}