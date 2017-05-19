/****************************************************************************
** Program Filename: Final Project
** Author: Stephen Townsend
** Date: 12/6/16
** Description: This is the FrontDoor.cpp. This uses class specific functions
** Input: None
** Output: None
*****************************************************************************/

#include "FrontDoor.hpp"

/****************************************************************************
** Function: FrontDoor()
** Description: Default Constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

FrontDoor::FrontDoor()
{
}

/****************************************************************************
** Function: FrontDoor(string loc)
** Description: 1 parameter constructor.  Uses Hospital constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

FrontDoor::FrontDoor(string loc) : Hospital(loc)
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

void FrontDoor::choices()
{
	if (action == 0)
		story();

	action++;
	
		cout << "What will you do?" << endl;
		cout << "     1. Open Front Doors" << endl
			 << "     2. Search the admissions desk" << endl
			 << "     3. Go Back" << endl;
}

/****************************************************************************
** Function: useItem()
** Description: Uses an item if there is one and sets to empty
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

void FrontDoor::useItem()
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

void FrontDoor::setItem(string item)
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

string FrontDoor::getItem()
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

string FrontDoor::getRoom()
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

bool FrontDoor::somethingHappens(int choice)
{
	if (choice == 1)
	{
		if (action == 2 || action == 3)
		{
			cout << "You triggered an alarm!!" << endl << endl;
			cout << "You hurry and locate a fire estinguisher on the wall." << endl
				<< "You use the estinguisher to bash the alarm control panel in the corner to disable the alarm" << endl << endl;
			cout << "In less then a minute you are cornered by security." << endl << endl
				<< "Becareful what you choose, security is trained." << endl << endl
				<< "What do you do?" << endl
				<< "     1. Struggle and hope you can escape. (Chance - Low)" << endl
				<< "     2. Grab the nearby fire estinguisher and use it against security. (Chance - Moderate)" << endl
				<< "     3. Run towards Security and hope you are in the Matrix. (Chance - Low)" << endl
				<< "     4. Give up and get on your knees. (Chance - Find Out)" << endl
				<< "Choice: ";
			cin >> choice;
			cin.ignore(10, '\n');

			cout << endl;


			if (choice == 1) //Died
			{
				if (itemResult = rand() % 100 < 25)
				{
					cout << "Succesfully struggled and passed by security.  You bolted back down the hall." << endl << endl;
					action++;
					return true;
				}
				else
				{
					cout << "You fell to the security guards.  They were comanded to take you at all costs" << endl
						<< "and that meant with you life." << endl << endl;
					setDead();
				}
			}
			else if (choice == 2)
			{
				if (itemResult = rand() % 100 < 50)
				{
					cout << "Succesfully used the fire estinguisher. You defended yourself against Security" << endl
						<< "They retreated" << endl << endl;
					action++;
				}
				else
				{
					cout << "You fell to the security guards.  They were comanded to take you at all costs" << endl
						<< "and that meant with your life." << endl << endl;
					setDead();
				}
			}
			else if (choice == 3) //Died
			{
				if (itemResult = rand() % 100 < 25)
				{
					cout << "Succesfully used matrix like fighting techniques and disabled security" << endl
						<< "You are amazed those movies actually helped you." << endl << endl;
					action++;
				}
				else
				{
					cout << "You fell to the security guards.  They were comanded to take you at all costs" << endl
						<< "and that meant with your life." << endl << endl;
					setDead();
				}
			}
			else if (choice == 4)
			{
				cout << "A Lab Scientist comes around the conner and tosses test bottles of." << endl;
				cout << "Potassium Hydroxide (20%) and Formalin at Security." << endl << endl;
				cout << "The Lab Scientist Walks away to continue their research." << endl << endl;
				action++;
			}
			return false;
		}
		else
		{
			cout << "The Door is Locked." << endl << endl;
			action--;
			return false;
		}
	}
	else if (choice == 2)
	{
		cout << "You search the admissions desk" << endl << endl;
			
		if (bag.compare("key") == 0 || bag.compare("Lab Keycard") == 0)
		{
			cout << "There is nothing usefull" << endl << endl;
			action--;
		}
		else
		{
			cout << "You found a key, it does not say what to." << endl << endl;
			bag = "key";
		}
		return false;
	}
	else if (choice == 3)
	{
		cout << "You are going back to the hall." << endl << endl;
		action--;
		return true;
	}
}

/****************************************************************************
** Function: setLocation()
** Description: Sets the rooms name
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The room is named
** Return: None
*****************************************************************************/

void FrontDoor::setLocation()
{
	position = "FrontDoor";
}

/****************************************************************************
** Function: setDead()
** Description: The player dies.
** Parameters: None
** Pre-Conditions: Player dies in game
** Post-Conditions: Status updates to dead
** Return: None
*****************************************************************************/

void FrontDoor::setDead()
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

STATUS FrontDoor::getState()
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

void FrontDoor::story()
{
	action++;

	cout << "You walked down the hall and made it to the front doors of the hospital." << endl
		<< "To the right there is a waiting room and a admissions desk behind you." << endl << endl;
}