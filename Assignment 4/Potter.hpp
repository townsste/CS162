/****************************************************************************
** Program Filename: Assignment 4
** Author: Stephen Townsend
** Date: 11/20/16
** Description: This is the Potter.hpp. It is used create the Potter class
** Input: None
** Output: None
*****************************************************************************/

#ifndef POTTER_HPP
#define POTTER_HPP

#include "Creature.hpp"


class Potter : public Creature
{

protected:
	int extraLife = 1; //Life count due to special

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
	virtual void combatRestHealth(); //Rest and Restore Health after battle
	virtual SPECIAL special(); //Creature special if applicable

	Potter();
	Potter(string, int, int, int, int, int, int);
};
#endif // !POTTER_HPP