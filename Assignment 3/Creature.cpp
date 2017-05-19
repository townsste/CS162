/****************************************************************************
** Program Filename: Assignment 3
** Author: Stephen Townsend
** Date: 11/6/16
** Description: This is the Creature.cpp. It is used set each objects data 
**					through the shared default construictor
** Input: None
** Output: None
*****************************************************************************/

#include "Creature.hpp"

/****************************************************************************
** Function: Creature::Creature()
** Description: Default constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

Creature::Creature()
{
}

/****************************************************************************
** Function: Creature::Creature()
** Description: 7 Parameter constructor. Uses Creature constructor
** Parameters: Object data
** Pre-Conditions: None
** Post-Conditions: Set Objects data
** Return: None
*****************************************************************************/

Creature::Creature(string name, int a, int s, int attDieNum, int attack, int defDieNum, int defense)
{
	creature = name; //Set creauture name
	armor = a; //Set armor
	strength = s; //Set strength
	aNum = attDieNum; //Set number of attack dice to roll
	attackDice = attack; //Set attack dice sides
	dNum = defDieNum; //Set number of defense dice to roll
	defenseDice = defense; //Set defense dice sides
	state = ALIVE; //Creature starts alive
	srand(time(NULL)); // Seed random number generator
}