/****************************************************************************
** Program Filename: Assignment 4
** Author: Stephen Townsend
** Date: 11/20/16
** Description: This is the Barbarian.cpp. It is roll the dice and get
**					information specific for this class from its object
** Input: None
** Output: Dice rolls and special if applicable
*****************************************************************************/

#include "Barbarian.hpp"

/****************************************************************************
** Function: Barbarian::Barbarian()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

Barbarian::Barbarian()
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

Barbarian::Barbarian(string name, int a, int s, int attDieNum, int attack, int defDieNum, int defense) : Creature(name, a, s, attDieNum, attack, defDieNum, defense)
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

string Barbarian::getCreature()
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

int Barbarian::attack()
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

int Barbarian::defense()
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

int Barbarian::getArmor()
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

void Barbarian::isAlive()
{
	if (strength <= 0) //Check strength
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

STATUS Barbarian::getState()
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

int Barbarian::getStrength()
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

int Barbarian::damage(int damage)
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

int Barbarian::rollDice(int roll, int dieType, int dieNum)
{
	if (dieNum == 0)
		return 0;
	else
		roll = rand() % (dieType - 1 + 1) + 1; //roll = random from 1 to max dice
	cout << roll << " "; //Output Dice roll to user
	return roll + rollDice(roll, dieType, dieNum - 1); //Recursion to add dice rolls
}

/****************************************************************************
** Function: combatRestHealth()
** Description: Adds 20% health to the combatant after battle
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Strength increased
** Return: None
*****************************************************************************/

void Barbarian::combatRestHealth()
{
	int restore = (12 * 0.2);

	strength += restore;

	if (strength > 12)
	{
		cout << "Barbarian's health is fully restored due to taking little damage to no" << endl;
		strength = 12;
	}
	else
		cout << "Barbarian restored " << restore << " health" << endl;
}

/****************************************************************************
** Function: special()
** Description: Special based on programs specifications
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: NONE
*****************************************************************************/

SPECIAL Barbarian::special()
{
	return NONE; //No special
}