/****************************************************************************
** Program Filename: Assignment 3
** Author: Stephen Townsend
** Date: 11/6/16
** Description: This is the Game.cpp. It is used to control the game data.
** Input: None
** Output: Character stats information.
*****************************************************************************/

#include "Game.hpp"

/****************************************************************************
** Function: inputVal()
** Description: Validates the user input from main for the menu
** Parameters: string check
** Pre-Conditions: None
** Post-Conditions: Input is valid
** Return: Valid input
*****************************************************************************/

string inputVal(string check)
{
	while (check.compare("1") != 0 && check.compare("2") != 0 &&  //Check input is 1 - 5
		check.compare("3") != 0 && check.compare("4") != 0 &&
		check.compare("5") != 0)
	{
		cout << "Please enter a valid creature: ";
		getline(cin, check);
	}
	return check; //Valid choice return
}

/****************************************************************************
** Function: Creature *loadCreature()
** Description: Create a Creature Object pointer
** Parameters: string creatureChoice
** Pre-Conditions: None
** Post-Conditions: Object is pointed to for player
** Return: Object pointed to.
*****************************************************************************/

Creature *loadCreature(string creatureChoice)
{
	Creature *creature; //Creature pointer object
	
	storyLine(creatureChoice); //Call and output character stroyline (optional addition)
	
	if (creatureChoice.compare("1") == 0) //Vampire
	{
		creature = new Vampire("Vampire", 1, 18, 1, 12, 1, 6); //Name, Armor, Strength, A Dice, Attack, D Dice, Defense
		return creature;
	}
	
	if (creatureChoice.compare("2") == 0) //Barbarian
	{
		creature = new Barbarian("Barbarian", 0, 12, 2, 6, 2, 6); //Name, Armor, Strength, A Dice, Attack, D Dice, Defense
		return creature;
	}
	else if (creatureChoice.compare("3") == 0) //Blue Men
	{
		creature = new Bluemen("Blue Men", 3, 12, 2, 10, 3, 6); //Name, Armor, Strength, A Dice, Attack, D Dice, Defense
		return creature;
	}
	else if (creatureChoice.compare("4") == 0) //Medusa
	{
		creature = new Medusa("Medusa", 3, 8, 2, 6, 1, 6); //Name, Armor, Strength, A Dice, Attack, D Dice, Defense
		return creature;
	}
	else if (creatureChoice.compare("5") == 0) //Harry Potter
	{
		creature = new Potter("Harry Potter", 0, 10, 2, 6, 2, 6); //Name, Armor, Strength, A Dice, Attack, D Dice, Defense
		return creature;
	}
}

/****************************************************************************
** Function: storyLine()
** Description: Outputs a storyline for each creature
** Parameters: string character
** Pre-Conditions: Valid creature chosen
** Post-Conditions: Outputs a story
** Return: None
*****************************************************************************/

void storyLine(string character)
{
	if (character.compare("1") == 0)  //Vampire Storyline
	{
		cout << "\nThe arena grows dark.  A dusting of fog appears throughout the battle field." << endl;
		cout << "From the sky drops a coffin.  The coffin shatters and it appears to be empty." << endl;
		cout << "Into the areana comes a sonic screetch. As the audience looks up in freight." << endl;
		cout << "You have mannifested into your true form." << endl;
		cout << "The Suave, Debonair, but Vicious and Surprisingly Resilient!" <<"  VAMPIRE" << endl << endl;
	}
	if (character.compare("2") == 0)  //Barbarian Storyline
	{
		cout << "\nIn the distance a battle horn is sounded.  The match is about to begin!!" << endl;
		cout << "The halls echo with a loud thunderious shout." << endl;
		cout << "The sound shakes the very walls that sourround the arena." << endl;
		cout << "Into the areana comes charging a large BARBARIAN." << endl;
		cout << "The Barbarian is dual wielding two large axes in hand ready for battle." << endl;
	}
	if (character.compare("3") == 0)  //Blue Men Storyline
	{
		cout << "\nSize and stregnth is not always the match determinant." << endl;
		cout << "Why settle for one when you can have many.  In a cadence, come marching in three BLUE MEN." << endl;
		cout << "Now do not be deceived, these small(6 inch tall) men are quite fast and tough." << endl;
		cout << "They are hard to hit and can take some damage. As for the attack, well this is another story." << endl;
		cout << "Watch your armor and you will find out, once they crawl inside armor or clothing then it will be no picnic." << endl;
	}
	if (character.compare("4") == 0)  //Medusa Storyline
	{
		cout << "\nThe legend and sometimes considered the myth.  A fair maiden approches the areana clothed in black." << endl;
		cout << "As she walks closer a hissing can be heard. As the womens cloak falls away, she is being" << endl;
		cout << "revealed.  The cloak falls to the ground and MEDUSA is revealed. She has a hideous face" << endl;
		cout << "and living venomous snakes in place of hair. Make sure not to look at her." << endl;
		cout << "She does not like that for if you do then you are sure to be turned into stone." << endl;
	}
	if (character.compare("5") == 0)  //Harry Potter Storyline
	{
		cout << "\nLets start with a quote. Happiness can be found, even in the darkest of times," << endl;
		cout << "if one only remembers to turn on the light... Faster then a Snitch, comes flying in an" << endl;
		cout << "individual on a broom.  The boy yells, while waving a stick, Expecto Patronum!!!." << endl;
		cout << "the dimmed arena is filled with a blinding light. The light fades to reveal the true" << endl;
		cout << "identity of this individual. It is none other than HARRY POTTER from Hogwatrs." << endl;
	}
}

/****************************************************************************
** Function: play()
** Description: The driver of the program. Calls the classes from a pointer
** Parameters: player1 and player2 pointers
** Pre-Conditions: Creatures chosen successfully
** Post-Conditions: NONE
** Return: None
*****************************************************************************/

void play(Creature *player1, Creature *player2)
{
	int attack;
	int defense;
	int damage;
	int turn = 1;

	cout << "\nPlease press enter to roll after each turn";
	cin.ignore(100, '\n'); //Pause game till enter is pressed

	while (player1->getState() == ALIVE && player2->getState() == ALIVE)
	{
		if (turn == 1) //Player 1 Turn
		{
			cout << left << setw(17) << "\nPlayer 1" << right << setw(21) << " Player 2" << endl; //Player output
			display(player1, player2); //Display call to output character information to user
			cout << "attack: "; //Output attack to correspond with roll.
			
			attack = player1->attack(); //Player 1 attack call.

			cout << right << setw(12); //Right justify players defense roll.

			defense = player2->defense(); //Player 2 defense call.

			cout << ":defend" << endl; //Output defend to correspond with roll.

			turn = 2; //Set next players turn

			if (player1->getCreature() == "Medusa" && attack == 12) //If player is Medusa (check for special kill)
			{
				player1->special(); //Call Medusa's special dialog.
				player2->damage(100); //Insta kill opponent.
				player2->isAlive(); //check and set player dead if strength == 0.
			}
			else
			{
				damage = player2->damage(attack - defense); //Send damage calculation to player 2.
				cout << endl << player2->getCreature() << " takes " << damage << " damage" << endl; //Output Player 2's damage to screen.
				player2->isAlive();
			}
			cin.ignore(100, '\n'); //Pause game till enter is pressed
			cout << "-------------------------------------------------------------" << endl; //Output spacer
		}
		else if (turn == 2) //Player 2 Turn
		{
			cout << left << setw(17) << "\nPlayer 1" << right << setw(20) << " Player 2" << endl; //Player output
			display(player1, player2); //Display call to output character information to user

			cout << "defend: "; //Output defend to correspond with roll.

			defense = player1->defense();  //Player 1 defense call.

			cout << right << setw(12); //Right justify players defense roll.

			attack = player2->attack(); //Player 2 attack call.

			cout << ":attack" << endl; //Output attack to correspond with roll.

			turn = 1;

			if (player2->getCreature() == "Medusa" && attack == 12) //If player is Medusa (check for special kill)
			{
				player2->special(); //Call Medusa's special dialog.
				player1->damage(100); //Insta kill opponent.
				player1->isAlive(); //check and set player dead if strength == 0.
			}
			else
			{
				damage = player1->damage(attack - defense); //Send damage calculation to player 1.
				cout << endl << player1->getCreature() << " takes " << damage << " damage" << endl; //Output Player 1's damage to screen.
				player1->isAlive();
			}

			cin.ignore(100, '\n'); //Pause game till enter is pressed
			cout << "-------------------------------------------------------------" << endl; //Output spacer
		}
	}

	if (player1->getState() == DEAD) //Check what player died
	{
		
		cout << "     " << "Player 1" << endl;
		cout << "     " << player1->getCreature() << " has lost" << endl << endl; //Player 1 Lost output
		getTombStone(player1); //Display RIP (Optional addition)
	}
	else
	{
		cout << "     " << "Player 2" << endl;
		cout << "     " << player2->getCreature() << " has lost" << endl << endl; //Player 2 Lost output
		getTombStone(player2); //Display RIP (Optional addition)
	}

	delete player1; //Delete allocated object
	player1 = NULL; //Prevent dangling pointer set NULL;
	delete player2; //Delete allocated object
	player2 = NULL; //Prevent dangling pointer set NULL;
}

/****************************************************************************
** Function: display()
** Description: Displays the creatures states for the user.
** Parameters: Player1 and Player2 pointers
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

void display(Creature *player1, Creature *player2)
{
	cout << "(" << player1->getStrength() << ") "; //Output creature remaining strength part 1
	cout << left << setw(12) << player1->getCreature() << setw(4) << "" << right << setw(11) << player2->getCreature(); //Output creature type
	cout << " (" << player2->getStrength() << ") " << endl //Output creature remaining strength part 2
		<< "Armor " << left << setw(12) << player1->getArmor() << right << setw(13) << player2->getArmor() << " Armor" << endl; //Output armor
}

/****************************************************************************
** Function: getTombStone
** Description: A fun tombstone output
** Parameters: Player pointer
** Pre-Conditions: Player dead
** Post-Conditions: None
** Return: None
*****************************************************************************/

void getTombStone(Creature *player) //Output tomebstone
{
	cout << setw(7) << "" << ".----------.		" << endl;
	cout << setw(5) << "" << ".'            `.	" << endl;
	cout << setw(5) << "" << "|    R  I  P   |	" << endl;
	cout << setw(5) << "" << "| " << left << setw(12) << player->getCreature() << right << setw(2) << "|" << endl; //Display dead creature name
	cout << setw(5) << "" << "|              |	" << endl;
	cout << setw(5) << "" << "|              |    " << endl;
	cout << setw(5) << "^^^^^^^^^^^^^^^^^^^^^^^^^^^ " << endl;
}
