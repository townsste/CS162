/****************************************************************************
** Program Filename: Assignment 3
** Author: Stephen Townsend
** Date: 11/6/16
** Description: This is the Vampire.hpp. It is used create the Vampire class
** Input: None
** Output: None
*****************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"


class Vampire : public Creature
{

protected:

public:
	virtual string getCreature(); //Creature name
	virtual int attack(); //Creature attack
	virtual int defense(); //Creature defense
	virtual int getArmor(); //Creature armor
	virtual void isAlive(); //Creature strength check
	virtual STATUS getState(); //Creature Alive or Dead
	virtual int getStrength(); //Creature strength
	virtual int damage(int); //Creature damage
	virtual int rollDice(int, int, int); //Creature roll
	virtual SPECIAL special(); //Creature special if applicable
	
	Vampire();
	Vampire(string, int, int, int, int, int, int);
};
#endif // !VAMPIRE_HPP