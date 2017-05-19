/****************************************************************************
** Program Filename: Final Project
** Author: Stephen Townsend
** Date: 12/6/16
** Description: This is the UpperHall.cpp. This uses class specific functions
** Input: None
** Output: None
*****************************************************************************/

#include "UpperHall.hpp"

/****************************************************************************
** Function: UpperHall()
** Description: Default Constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

UpperHall::UpperHall()
{
}

/****************************************************************************
** Function: UpperHall(string loc)
** Description: 1 parameter constructor.  Uses Hospital constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

UpperHall::UpperHall(string loc) : Hospital(loc)
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

void UpperHall::choices()
{
	if (action == 0)
		story();
	
	action++;
	
	if (action == 2)
	{
		cout << "Which will you do?" << endl;
		cout << "     1. Take the elevator" << endl
			 << "     2. Take the stairs" << endl
			 << "     3. Check your vitals" << endl;
	}

	if (action == 3)
	{
		cout << "Which will you take?" << endl;
		cout << "     1. Take the elevator" << endl
			 << "     2. Take the stairs" << endl;
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

void UpperHall::useItem()
{	
	if (getItem().compare("Blood Pressure Cuff") == 0)
	{
		cout << "Using the blood pressure cuff, you determine that your BP is: ";
	}

	if (itemResult == 1)
	{
		cout << "175/120" << endl;
		cout << "\nYour BP is high you may want to exert less energy." << endl;
	}
	else if (itemResult == 2)
	{
		cout << "60/40" << endl;
		cout << "\nYour BP is low you may want to exert more energy." << endl;
	}

	cout << "\nYou used up the blood pressure cuff" << endl;

	cout << "\nYou hope you checked your vitals correctly" << endl << endl;
}

/****************************************************************************
** Function: setItem(string item)
** Description: Uses an item if there is one and sets to empty
** Parameters: String item
** Pre-Conditions: Set item from main
** Post-Conditions: None
** Return: None
*****************************************************************************/

void UpperHall::setItem(string item)
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

string UpperHall::getItem()
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

string UpperHall::getRoom()
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

bool UpperHall::somethingHappens(int choice)
{	
	if (action == 2)
		itemResult = (rand() % (2 - 1 + 1) + 1);

	if (choice == 1)
	{
		if (itemResult == 2) //Took Elevator and died
		{
			cout << "You took the elevator and and you sit becasue you get very dizzy.  Becasue of your low blood pressure" << endl
				<< "your body shuts down, you passout, and stop breathing." << endl << endl
				<< "YOU DIED!!" << endl;
			setDead();
			return false;
		}
		else if (itemResult == 1) //Took Elevator and live
		{
			cout << "You enter the elevator and sit down, As you sit" << endl
				<< "you are feeling better by lowering your blood pressure, if you took the stairs you would not had made it" << endl;
			return true;
		}
	}
	if (choice == 2)
	{
		if (itemResult == 1) //Took Stairs and died
		{
			cout << "You took the stairs and becasue of your high blood pressure your body cannot take exercise." << endl
				<< "You start feeling chest pains and your left arm is going numb.  You fall to your knees and gasp for air." << endl << endl
				<< "YOU DIED!!" << endl;
			setDead();
			return false;
		}
		else if (itemResult == 2) //Took Stairs and live
		{
			cout << "You start down the stairs and" << endl
				<< "you are feeling better by increasing your blood pressure, if you took the elevator you would not had made it" << endl;
			return true;
		}
	}
	if (choice == 3 && action == 2)
	{
		useItem();
		return false;
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

void UpperHall::setLocation()
{
	position = "UpperHall";
}

/****************************************************************************
** Function: setDead()
** Description: The player dies.
** Parameters: None
** Pre-Conditions: Player dies in game
** Post-Conditions: Status updates to dead
** Return: None
*****************************************************************************/

void UpperHall::setDead()
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

STATUS UpperHall::getState()
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

void UpperHall::story()
{
	action++;

	cout << "As you run down the hall you see an elevator and stairs going down." << endl;
	cout << "However, you start experiencing shortness of breath." << endl
		<< "You may need to try and check your state or risk your life" << endl << endl;
}