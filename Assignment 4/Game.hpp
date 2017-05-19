/****************************************************************************
** Program Filename: Assignment 4
** Author: Stephen Townsend
** Date: 11/20/16
** Description: This is the Game.Hpp. It is used to control the game data.
** Input: None
** Output: None
*****************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Queue.hpp"
#include "Stack.hpp"
#include "Creature.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "Bluemen.hpp"
#include "Medusa.hpp"
#include "Potter.hpp"

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

void displayChoices();
string inputVal(string);
int checkIntVal();
Creature *loadCreature(string creature);
void storyLine(string);
int play(Creature *, Creature *, int &, int &, string, string);
void display(Creature*, Creature*);
void getTombStone(Creature *player);
void closeGameData(Creature *, Creature *);

#endif // !GAME_HPP