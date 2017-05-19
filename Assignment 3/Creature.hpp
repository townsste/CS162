/****************************************************************************
** Program Filename: Assignment 3
** Author: Stephen Townsend
** Date: 11/6/16
** Description: This is the Creature.hpp. It is used create the Creature class
** Input: None
** Output: None
*****************************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;

enum STATUS { ALIVE, DEAD };
enum SPECIAL { CHARM, MOB, HOGWARTS, NONE};

class Creature
{

protected:
	int armor;
	int strength;
	int attackDice;
	int defenseDice;
	int aNum;
	int dNum;
	STATUS state;
	string creature;

public:
	virtual string getCreature() = 0; //Creature name
	virtual int attack() = 0; //Creature attack
	virtual int defense() = 0; //Creature defense
	virtual int getArmor() = 0; //Creature armor
	virtual void isAlive() = 0; //Creature strength check
	virtual STATUS getState() = 0; //Creature Alive or Dead
	virtual int getStrength() = 0; //Creature strength
	virtual int damage(int) = 0; //Creature damage
	virtual int rollDice(int, int, int) = 0; //Creature roll
	virtual SPECIAL special() = 0; //Creature special if applicable
	
	Creature(); //Default constructor
	Creature(string, int, int, int, int, int, int); //7 parameter constructor.  Set object information
};
#endif // !CREATURE_HPP