/****************************************************************************
** Program Filename: Lab 9
** Author: Stephen Townsend
** Date: 11/27/16
** Description: This is the Main.cpp. It is used to asked the user what 
					function they want to run Queue Simulator or create a 
					Palindrome
** Input: Choose and option 1, 2, or 3 and follow prmopts.
** Output: The menue list
*****************************************************************************/

#include "Stack.hpp"
#include "Queue.hpp"
#include <iostream>	
#include <string>

using namespace std;


int main()
{
	srand(time(NULL)); // Seed random number generator

	string choice;
	string input;

	while (choice.compare("3") != 0)
	{
		cout << "1. Queue Simulator" << endl
			 << "2. Palindrome Creator" << endl
			 << "3. Exit" << endl;
		cout << "Choice: ";
		getline(cin, choice);

		while (choice.compare("1") != 0 && choice.compare("2") != 0 &&  //Check input is 1 - 3
			choice.compare("3") != 0)
		{
			cout << "Please enter a valid menu choice: ";
			getline(cin, choice);
		}

		if (choice.compare("1") == 0 || choice.compare("2") == 0)
		{
			if (choice.compare("1") == 0) //If option 1 or 2
			{
				int sim = 0;
				int add = 0;
				int remove = 0;

				cout << "\nPlease enter the percent to add random number into queue: ";
				add = checkIntVal(); //Check int input and set add percentage

				cout << "\nPlease enter the percent to remove random number into queue: ";
				remove = checkIntVal(); //Check int input and set remove percentage

				cout << "\nPlease enter times to run simulator: ";
				sim = checkIntVal(); //Check int input and set sim run time

				queueSimulator(sim, add, remove); //Run the queue simulator
			}
			else if (choice.compare("2") == 0) //Option 2 selected
			{
				cout << "\nEnter a string to be a palindrome: ";
				getline(cin, input);

				palindrome(input); //Run palindrome creator

				cout << endl << input << endl << endl; //Output the palindrome
			}
		}
	}
	return 0;
}
