/****************************************************************************
** Program Filename: Assignment 3
** Author: Stephen Townsend
** Date: 11/6/16
** Description: This is the Potter.cpp. It is used to control the Potter class
** Input: None
** Output: Dice rolls and special if applicable
*****************************************************************************/

#include "Potter.hpp"

/****************************************************************************
** Function: Potter::Potter()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

Potter::Potter()
{
}

/****************************************************************************
** Function: Vampire::Vampire()
** Description: 7 Parameter constructor. Uses Creature constructor
** Parameters: Object data
** Pre-Conditions: None
** Post-Conditions: Set Objects data
** Return: None
*****************************************************************************/

Potter::Potter(string name, int a, int s, int attDieNum, int attack, int defDieNum, int defense) : Creature(name, a, s, attDieNum, attack, defDieNum, defense)
{
	//Use creature constructor
}

/****************************************************************************
** Function: getCreature()
** Description: Return the creature name
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

string Potter::getCreature()
{
	return creature;
}

/****************************************************************************
** Function: attack()
** Description: Call the roll dice function while passing attack information
** Parameters: int 0, int attackDice, and int aNum
** Pre-Conditions: None
** Post-Conditions: None
** Return: Total attack dice roll
*****************************************************************************/

int Potter::attack()
{
	return rollDice(0, attackDice, aNum); //roll is zero, dice sides, and amount of dice
}

/****************************************************************************
** Function: defense()
** Description: Call the roll dice function while passing defense information
** Parameters: int 0, int defenseDice, and int dNum
** Pre-Conditions: None
** Post-Conditions: None
** Return: Total defense dice roll
*****************************************************************************/

int Potter::defense()
{
	return rollDice(0, defenseDice, dNum); //roll is zero, dice sides, and amount of dice
}

/****************************************************************************
** Function: getArmor()
** Description: Get the armor information for creature
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: Armor
*****************************************************************************/

int Potter::getArmor()
{
	return armor; //Get armor
}

/****************************************************************************
** Function: isAlive()
** Description: Check if strength is zero. Set to dead.
** Parameters: None
** Pre-Conditions: Players health must be zero
** Post-Conditions: Player is dead
** Return: None
*****************************************************************************/

void Potter::isAlive()
{
	special(); //Call special if Harry died once

	if (strength <= 0 && extraLife == 0) //Check strength
		state = DEAD; //Creature Died
}

/****************************************************************************
** Function: getState()
** Description: Get the life status for creature
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: State.  Whether Alive or Dead
*****************************************************************************/

STATUS Potter::getState()
{
	return state;
}

/****************************************************************************
** Function: getStrength()
** Description: Get the strength information for creature
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: Strength
*****************************************************************************/

int Potter::getStrength()
{
	return strength;
}

/****************************************************************************
** Function: damage()
** Description: Decreses players strength based on damage and armor rating
** Parameters: int damage
** Pre-Conditions: Pass the damage calculation
** Post-Conditions: Decrease strength based on damage
** Return: Return total damage
*****************************************************************************/

int Potter::damage(int damage)
{
	damage -= getArmor(); //Reduce damage based on armor
	
	if (damage > 0) //Damage cannot be less then zero
	{
		strength -= damage; //Reduce strength by final damage amount

		if (strength < 0) //check for overkill
			strength = 0; //Set strength to zero if if overkilled

		return damage;
	}
	else
		return 0; //Damage would have been negative
}

/****************************************************************************
** Function: rollDice()
** Description: Rolls the dice based on passed in parameters. Uses recursion
** Parameters: int roll, int dieType, int dieNum
** Pre-Conditions: Passed in parameters based on object starting data
** Post-Conditions: Pointers set to NULL
** Return: returns total of dice roll
*****************************************************************************/

int Potter::rollDice(int roll, int dieType, int dieNum)
{
	if (dieNum == 0)
		return 0;
	else
		roll = rand() % (dieType - 1 + 1) + 1; //roll = random from 1 to max dice
	cout << roll << " "; //Output Dice roll to user
	return roll + rollDice(roll, dieType, dieNum - 1); //Recursion to add dice rolls
}

/****************************************************************************
** Function: special()
** Description: Special based on programs specifications
** Parameters: None
** Pre-Conditions: Strength needs to be zero
** Post-Conditions: Potter has a new strength set
** Return: HOGWARTS or NONE
*****************************************************************************/

SPECIAL Potter::special()
{
	if (strength == 0 && extraLife == 1) //If strength is zero and has extra life then special
	{
		cout << "\nPoor, Poor, Harry.  He was the chosen one." << endl //Special Dialog
			<< "The one who was to stop the one whos name shall not be spoken" << endl
			<< "*A screetch echos through the halls*" << endl
			<< "BY THE POWER OF HOGWARTS and Dumbledore's Phoenix" << endl
			<< "The healing tears from the golden bird has made Harry stronger and brought him new life" << endl << endl;

		strength = 20; //New strength
		extraLife -= 1; //Last life
		return HOGWARTS;
	}
	else
		return NONE;
}