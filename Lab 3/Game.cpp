/*****************************************************************************************

Author: Stephen Townsend
Date: 10/16/2016
Description: This is the Game.cpp.  This is used to control the entire game.  The default 
constructor is used to initialize the starting values of private member functions.  There
is a game setting function that will takethe user input on how they want to control the 
game.  After the settings, the play function will becalled.  Play is where the gam begins.
Play is used to direct the users rolls and call various functions to display the results.

*****************************************************************************************/

#include "Game.hpp"

/*****************************************************************************************
**										Game()
**  This is teh Game default constructor.  This is used to initialize private member
**  functions to their default startingvalues.
*****************************************************************************************/
Game::Game()
{
	rounds = 0;
	player1Score = 0;
	player2Score = 0;
	player1 = 1;
	player2 = 2;
	playerTurn = 1;
}

/*****************************************************************************************
**										setTurn()
**  setTurn is used to set the turn of the current player.  The player is set to 1 by 
**  default
*****************************************************************************************/
void Game::setTurn(int turn)
{
	if (turn == 1)
		playerTurn = 2;
	else
		playerTurn = 1;
}

/*****************************************************************************************
**										loPlayer()
**  loPlayer is used to keep track of which player will have loaded dice.  It also has a 
**  validation check to make sure the user inputs 0-3.  The user is able to pass a number
**  greater then 3, but this will request the number be changedand then return the int.
*****************************************************************************************/
int Game::loPlayer(int loadPlay)
{
	while (loadPlay < 0 || loadPlay > 3)
	{
		cout << "Not a valid input. Please choose (0 - 3) ";
		cin >> loadPlay;
		cin.clear();
		cin.ignore(100, '\n');
	}
		return loadPlayer = loadPlay;
}

/*****************************************************************************************
**									  setScore()
**  setScore function is used to increment the total score by one point for each win.
*****************************************************************************************/
void Game::setScore(int player)
{
	if (player == 1)
		player1Score += 1;
	else
		player2Score += 1;
}

/*****************************************************************************************
**									getOutcome()
**  This is the getOutcome function.  This is used to output the final score to the user.
*****************************************************************************************/
void Game::getOutcome()
{
	cout << "Player 1 won " << player1Score << " games" << endl;
	cout << "Player 2 won " << player2Score << " games" << endl;

	if (player1Score > player2Score)
		cout << "Player 1 won overall" << endl;
	else if (player1Score < player2Score)
		cout << "Player 2 won overall" << endl;
	else if (player1Score == player2Score)
		cout << "Player 1 & Player 2 won the same amount of games." << endl;
}

/*****************************************************************************************
**										play()
**  This is the play function.  Thisfunction is used to keep track of the game rounds and
**  used to call each players roll.
*****************************************************************************************/
void Game::play()
{	
	int currentRounds = 0;
	int rollOne;
	int rollTwo;
	
	while (currentRounds != rounds) //Compare current rounds to game rounds
	{
		cout << "Player " << playerTurn << endl;

		for (int i = 0; i < 2; i++)
		{
			if (playerTurn == 1) //Player 1 roll
			{
				if (loadPlayer == 1 || loadPlayer == 3) //Check Player 1 dice type
					rollOne = loadedPlayer1.loadWeightRoll(); //P1 Loaded Roll
				else
					rollOne = normalPlayer1.roll(); //P1 Normal roll

				cout << rollOne << endl; //output player 1 roll
			}

			else if (playerTurn == 2) //Player 2 roll
			{
				if (loadPlayer == 2 || loadPlayer == 3) //Check Player 2 dice type
					rollTwo = loadedPlayer2.loadWeightRoll(); //Loaded roll
				else
					rollTwo = normalPlayer2.roll(); //Normal roll
				
				cout << rollTwo << endl; //output player 2 roll
				cout << "Player " << playerTurn << endl << endl;
			}
			setTurn(playerTurn); //Switch player
		}
		
		//Test the winner of each round
		if (rollOne > rollTwo)  //Player 1 won
		{
			cout << "Player " << player1 << " won" << endl << endl;
			setScore(player1);
		}
		else if (rollOne == rollTwo) //Tie
		{
			cout << "The game was a tie " << endl << endl;
			currentRounds--; //replay the game if tie
		}
		else
		{						//Player 2 won
			cout << "Player " << player2 << " won" << endl << endl;
			setScore(player2);
		}
		currentRounds++; //Increment rounds
	}
	getOutcome(); //Output the score
}

/*****************************************************************************************
**									gameSettings()
**  
*****************************************************************************************/
void Game::gameSettings()
{
	int loadPlayer;
	int die1;
	int die2;
	
	//Input for game settings
	cout << "How many rounds do you want to play "; //Rounds
	cin >> rounds;
	rounds = inputValidation(rounds);
	
	cout << "\nWhich player has loaded dice? 0, 1, 2 or both (3)? "; //Who is using loaded
	cin >> loadPlayer;
	loadPlayer = inputValidation(loadPlayer);
	
	loadPlayer = loPlayer(loadPlayer);  //Set load player and return valid input

	cout << "\nHow many sides does Die 1 have? "; //Player 1 Dice sides
	cin >> die1;
	die1 = inputValidation(die1);

	cout << "\nHow many sides does Die 2 have? "; //Player 2 Dice sides
	cin >> die2;
	die2 = inputValidation(die2);

	//Settings Recap -- Shows what the user inputed.
	cout << "\n\n::Game Settings::" << endl;
	cout << "You will play " << rounds << " rounds" << endl;
		if (loadPlayer == 0)
			cout << "No players have loaded dice " << endl;
		else if(loadPlayer == 1)
			cout << "Player 1 has loaded dice " << endl;
		else if (loadPlayer == 2)
			cout << "Player 2 has loaded dice " << endl;
		else if (loadPlayer == 3)
			cout << "Player 1 & Player 2 have loaded dice " << endl;
		cout << "Dice 1 has " << die1 << " sides" << endl
		     << "Dice 2 has " << die2 << " sides" << endl;

		cout << "\nPress enter to continue..." << endl;
		cin.get();

//Set the dice type: Loaded or Normal basedon loadPlayer value
	if (loadPlayer == 0)
	{
		normalPlayer1.setDiceSides(die1); //Player 1 Normal Dice
		normalPlayer2.setDiceSides(die2); //Player 2 Normal Dice
	}
	else if (loadPlayer == 1)
	{
		loadedPlayer1.setDiceSides(die1); //Player 1 Loaded Dice
		normalPlayer2.setDiceSides(die2); //Player 2 Normal Dice
	}
	else if (loadPlayer == 2)
	{
		normalPlayer1.setDiceSides(die1); //Player 1 Normal Dice
		loadedPlayer2.setDiceSides(die2); //Player 2 Loaded Dice
	}
	else if (loadPlayer == 3)
	{
		loadedPlayer1.setDiceSides(die1); //Player 1 Loaded Dice
		loadedPlayer2.setDiceSides(die2); //Player 2 Loaded Dice
	}

	//Calls the play function and starts the game
	play();
}

/*****************************************************************************************
**									inputValidation()
**  This function is used to test all the cin statements.  If the user enters a char then
**  the cin statement will toss up a flag.  This is used to clear that flag, and clear the
**  buffer to prevent crashes or infinite loops; due to input.
*****************************************************************************************/
int Game::inputValidation(int input)
{
	while (cin.fail()) //Loop until a int is in the front
	{
		cin.clear(); //Clear buffer error flag if user entered a char
		cin.ignore(100, '\n'); //Clear the input buffer if the user entered a char
		cout << "Please enter an integer ";
		cin >> input;
	}
	cin.clear(); //clear buffer error again before returning (if user ented char behind int)
	cin.ignore(100, '\n'); //clear the input buffer  before returning valid int.

	return input;
}