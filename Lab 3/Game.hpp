/*****************************************************************************************

Author: Stephen Townsend
Date: 10/16/2016
Description: This is the Game.hpp.  This is used to create the Game class.  This is the
main class that will have dice.

*****************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Dice.hpp"
#include "LoadedDice.hpp"
#include <iostream>

using namespace std;

class Game
{

private:
	LoadedDice loadedPlayer1;
	LoadedDice loadedPlayer2;
	Dice normalPlayer1;
	Dice normalPlayer2;
	int rounds;
	int player1Score;
	int player2Score;
	int player1;
	int player2;
	int playerTurn;
	int loadPlayer;

public:
	void setTurn(int);
	int loPlayer(int);
	void setScore(int);
	void getOutcome();

	void play();
	void gameSettings();
	int inputValidation(int);

//Default Constructor
	Game();

};
#endif // !GAME_HPP