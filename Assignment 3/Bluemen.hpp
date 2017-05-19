/****************************************************************************
** Program Filename: Assignment 3
** Author: Stephen Townsend
** Date: 11/6/16
** Description: This is the Bluemen.hpp. It is used create the Bluemen class
** Input: None
** Output: None
*****************************************************************************/

#ifndef BLUEMAN_HPP
#define BLUEMAN_HPP

#include "Creature.hpp"


class Bluemen : public Creature
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
	
	Bluemen();
	Bluemen(string, int, int, int, int, int, int);
};
#endif // !BLUEMAN_HPP