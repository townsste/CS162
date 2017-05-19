/****************************************************************************
** Program Filename: Assignment 4
** Author: Stephen Townsend
** Date: 11/20/16
** Description: This is the Main.cpp. It help the user start the game by 
**					displaying what there input options are.
** Input: Creature choice for player 1 and player 2.  Play again?
** Output: The creature list options
*****************************************************************************/

#include "Game.hpp"
#include "Creature.hpp"
#include "Vampire.hpp"

#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

/****************************************************************************
** Function: int main()
** Description: Program driver
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: User chooses creature lineup to play
** Return: Zero
*****************************************************************************/

int main()
{
	string playAgain = "Y";

	while (playAgain.compare("Y") == 0 || playAgain.compare("y") == 0)
	{
		playAgain = "RESET";

		Creature *player1 = NULL;
		Creature *player2 = NULL;
		Stack looserOne;
		Stack looserTwo;
		Queue queueOne;
		Queue queueTwo;
		Queue *linkOne = &queueOne;
		Queue *linkTwo = &queueTwo;
		Queue looserStack;

		int lineupCountKeep;
		int lineCount1AndScore;
		int lineCount2AndScore;
		string teamOneName;
		string teamTwoName;
		string choice1;
		string choice2;
		int dead = 0;
		int round = 1;

		cout << "How many creatures will each player have? Default is 1: ";
		
		lineupCountKeep = checkIntVal();
		
		if (lineupCountKeep < 0)
			lineupCountKeep = 1; //Default option

		lineCount1AndScore = lineCount2AndScore = lineupCountKeep; //Create two copies one for each player.
		
		cout << "\nName First Team: ";
		getline(cin, teamOneName); //First Team name

		cout << "\nName Second Team: ";
		getline(cin, teamTwoName); //Second Team name

		cout << "\n::Choose your creature lineup::";
		displayChoices();

		cout << teamOneName <<"'s first creature: ";

		while (lineCount1AndScore != 0)
		{
			getline(cin, choice1); //Get creature choice for player 1

			choice1 = inputVal(choice1); //Check user input is valid	
			
			player1 = loadCreature(choice1); //Pass valid choice to create creature object

			linkOne->push(player1); //Add creature to first queue

			lineCount1AndScore--; //Decrease creature total

			if (lineCount1AndScore == 0)
			{
				cout << "\n::Line up selected::" << endl;
				linkOne->displayLineUp(); //Display the lineup
				cout << endl
					 << "-----------------------------------------------------------" << endl; //Line for aesthetics
			}
			else
			{
				displayChoices();
				cout << "Enter next creature: ";
			}
		}
		cout << "::Choose your creature lineup::";
		displayChoices();
		cout << teamTwoName << "'s first creature: ";

		while (lineCount2AndScore != 0)
		{
			getline(cin, choice2); //Get creature choice for player 2

			choice2 = inputVal(choice2); //Check user input is valid

			player2 = loadCreature(choice2); //Pass valid choice to create creature object

			linkTwo->push(player2); //Add creature to second queue

			lineCount2AndScore--; //Decrease creature total

			if (lineCount2AndScore == 0)
			{
				cout << "\n::Line up selected::" << endl;
				linkTwo->displayLineUp(); //Display the lineup
				cout << endl 
					 << "-----------------------------------------------------------" << endl; //Line for aesthetics
			}
			else
			{
				displayChoices();
				cout << "Enter next creature: ";
			}
		}

		cout << "\nPlease press enter to roll after each turn\n" << endl; //Directions
		cin.ignore(100, '\n'); //Pause game till enter is pressed
		
		cout << "THE MATCH IS ABOUT TO BEGIN!!" << endl;

		do
		{
			cout << endl
				<< "-----------------------------------------------------------" << endl; //Line for aesthetics

			cout << "Score:";
			cout << endl << "Team " << left << setw(12) << teamOneName << " " << lineCount1AndScore 
				 << endl << "Team " << left << setw(12) << teamTwoName << " " << lineCount2AndScore << endl; //Output team score

			cout << endl << right << setw(17) << "Round " << round << endl << endl; //Output round
			cout << right << setw(12);
			player1 = linkOne->getCreature(); //Output Creature name
			cout << " VS ";
			cout << left << setw(12);
			player2 = linkTwo->getCreature(); //Output Creature name
			cout << endl << endl << right << setw(18) << "READY!!" << endl; //Output Ready
			cout << endl << right << setw(18) << "FIGHT!!" << endl; //Output Fight

			cin.ignore(100, '\n'); //Pause game till enter is pressed

			dead = play(player1, player2, lineCount1AndScore, lineCount2AndScore, teamOneName, teamTwoName); //Play the game
			
			if (dead == 1) //If Player 1 died
			{
				looserOne.push(player1); //Add looser to their stack
				linkOne->pop(); //Remove from queue
				dead = 0; //Reset dead
				linkTwo->pop(); //Remove winning creature from their queue
				linkTwo->push(player2); //Add winning creature to back of queue
			}
			else if (dead == 2) //If Player 1 died
			{
				looserTwo.push(player2); //Add looser to their stack
				linkTwo->pop(); //Remove from queue
				dead = 0; //Reset dead
				linkOne->pop(); //Remove winning creature from their queue
				linkOne->push(player1); //Add winning creature to back of queue
			}
			round++;
		} 
		while (lineCount1AndScore != lineupCountKeep && lineCount2AndScore != lineupCountKeep); //While there is no winner

		cout << endl << endl << "Final Score:" << endl // Output Final Score to user
			 << endl << "Team " << left << setw(12) << teamOneName << " " << lineCount1AndScore
			 << endl << "Team " << left << setw(12) << teamTwoName << " " << lineCount2AndScore << endl << endl; //Output team score

		if (lineCount1AndScore > lineCount2AndScore) //If Team 1 wins
		{
			cout << "Team " << teamOneName << " won" << endl; //Output winner
			cout << "-----------------------------------------------------------" << endl; //Line for aesthetics
			cout << "\nFoes Vanquished by Team " << teamOneName << endl << endl; //Display lossing teams stack
			looserTwo.displayLineUp(); //Looser stack
			cout << "-----------------------------------------------------------" << endl; //Line for aesthetics
			cout << "\nTeam " << teamOneName <<" 's Creatures lost" << endl << endl; //Display winning lost creatures
			looserOne.displayLineUp(); //Looser stack
		}
		else //Team 2 wins
		{
			cout << "Team " << teamTwoName << " won" << endl; //Output winner
			cout << "-----------------------------------------------------------" << endl; //Line for aesthetics
			cout << "\nFoes Vanquished by Team " << teamTwoName << endl << endl; //Display lossing teams stack
			looserOne.displayLineUp(); //Looser stack
			cout << "-----------------------------------------------------------" << endl; //Line for aesthetics
			cout << "\nTeam " << teamTwoName << " 's Creatures lost" << endl << endl; //Display winning lost creatures
			looserTwo.displayLineUp(); //Looser stack
		}

		//Cleanup and Deallocate memory
		closeGameData(player1, player2); //Cleanup Player 1 and 2
		linkOne->cleanup(); //Clear linkOne Node Queue
		linkOne = NULL; //Set pointer to NULL;
		linkTwo->cleanup(); //Clear linkTwo Node Queue
		linkTwo = NULL; //Set pointer to NULL;
		looserOne.cleanup(); //Clear looserOne Node Stack
		looserTwo.cleanup(); //Clear looserTwo Node Stack

		while (playAgain.compare("Y") != 0 && playAgain.compare("y") != 0 && playAgain.compare("N") != 0 && playAgain.compare("n") != 0)
		{
			cout << "\n\nDo you want to play again? (Y or N) ";
			getline(cin, playAgain);

			if (playAgain.compare("Y") != 0 && playAgain.compare("y") != 0 && playAgain.compare("N") != 0 && playAgain.compare("n") != 0)
				cout << "Please enter a valid response" << endl;

			cout << endl;
		}
	}
	return 0;	
}