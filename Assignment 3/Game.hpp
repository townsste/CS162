/****************************************************************************
** Program Filename: Assignment 3
** Author: Stephen Townsend
** Date: 11/6/16
** Description: This is the Game.Hpp. It is used to control the game data.
** Input: None
** Output: None
*****************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP


#include "Creature.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "Bluemen.hpp"
#include "Medusa.hpp"
#include "Potter.hpp"

#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

Creature *loadCreature(string creature);
void storyLine(string);
void play(Creature *player1, Creature *player2);
void getTombStone(Creature *player);
void display(Creature*, Creature*);
string inputVal(string);


#endif // !GAME_HPP