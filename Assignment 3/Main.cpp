/****************************************************************************
** Program Filename: Assignment 3
** Author: Stephen Townsend
** Date: 11/6/16
** Description: This is the Main.cpp. It help the user start the game by 
**					displaying what there input options are.
** Input: Creature choice for player 1 and player 2.  Play again?
** Output: The creature list options
*****************************************************************************/

#include "Game.hpp"
#include "Creature.hpp"
#include "Vampire.hpp"

#include <string>
#include <iostream>
using namespace std;

/****************************************************************************
** Function: int main()
** Description: Program driver
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: User chooses creature to play
** Return: Zero
*****************************************************************************/

int main()
{
	string playAgain = "Y";

	while (playAgain.compare("Y") == 0 || playAgain.compare("y") == 0)
	{

		playAgain = "RESET";

		Creature *player1;
		Creature *player2;

		string choice1;
		string choice2;

		cout << "::Choose your creature::" << endl
			<< "1. Vampire" << endl
			<< "2. Barbarian" << endl
			<< "3. Blue Men" << endl
			<< "4. Medusa" << endl
			<< "5. Harry Potter" << endl;

		cout << "\nPlayer 1: ";
		getline(cin, choice1);

		choice1 = inputVal(choice1); //Check user input is valid

		player1 = loadCreature(choice1); //Pass valid choice to create creature object

		cout << "\nPlayer 2: ";
		getline(cin, choice2);

		choice2 = inputVal(choice2); //Check user input is valid

		player2 = loadCreature(choice2); //Pass valid choice to create creature object

		play(player1, player2); //Play the game

		while (playAgain.compare("Y") != 0 && playAgain.compare("y") != 0 && playAgain.compare("N") != 0 && playAgain.compare("n") != 0)
		{
			cout << "Do you want to play again? (Y or N) ";
			getline(cin, playAgain);

			if (playAgain.compare("Y") != 0 && playAgain.compare("y") != 0 && playAgain.compare("N") != 0 && playAgain.compare("n") != 0)
				cout << "Please enter a valid response" << endl;

			cout << endl;
		}
	}
	return 0;	
}