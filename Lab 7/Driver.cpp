/****************************************************************************
** Program Filename: Lab 7
** Author: Stephen Townsend
** Date: 11/13/16
** Description: This is the Driver.cpp.  This program is used to open a file 
**		specified by name from the user.  The program will check to see if the 
**		file is accessable.  Once the file is opened, the program will read 
**		the data and performed the appropiate option from the user.
** Input: Enter a choice for the menu & filename
** Output: Outputs the options to make a choice for which function you want
**			   to run and the filename options.
*****************************************************************************/

#include "Menu.hpp"

#include <iostream>	
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	ifstream inputText; //Create the input stream
	string filename; //Used to capture users filename
	string choice;
	//string runAgain = "Y";

	while (choice.compare("4") != 0 )
	{
		string searchOveride;
		//runAgain = "RESET";
		int textInteger = 0;
		int search = 0;
		int count = 0;
		int position = 1;
		int *arrPtr = NULL;
		int open = 0;

		cout << "1. Linear Search" << endl
			 << "2. Bubble Sort" << endl
			 << "3. Binary Search" << endl
			 << "4. Exit" << endl;
		cout << "Choice: ";
		getline(cin, choice);

		menuInputVal(choice); //Check user input is valid. Pass reference

		if (choice.compare("1") == 0 || choice.compare("2") == 0 || choice.compare("3") == 0)
		{
			if (choice.compare("1") == 0 || choice.compare("2") == 0) //If option 1 or 2
			{
				cout << "\nEnter a filename followed by .txt" << endl;
				cout << "Options: (start, middle, end, original, or mixed)" << endl; //Files that works with linear search and Bubble Sort
			}
			else //Option 3 selected
			{
				cout << "\nEnter a filename followed by .txt" << endl;
				cout << "Options: (binary1, binary2, original, or the name of a list you sorted)" << endl; //Files that works with binary search
			}

			cout << "Choice: ";
			cin >> filename;

			cout << endl;
			cin.ignore(100, '\n'); //Clear buffer error due to Read File.

			while (open != 2) //Only open file twice
			{
				inputText.open(filename.c_str()); //Open the input file
				open++; //Increment counter

				if (inputText) //Check if file opened
				{
					if (open == 1) //File opened once to get total integers
					{
						while (inputText >> textInteger) //If a value was read
							count++; //Get total number of integers in file
					}
					else if (open == 2) //File opened twice to set dynamic array number
					{
						arrPtr = new int[count]; //Dynamic array od ints
						int next = 0; //Next element location

						while (inputText >> textInteger) //If a value was read
						{
							arrPtr[next] = textInteger; //Put integer in array
							next++; //Move to next element location
							cout << right << setw(3) << next << " "; //Output integer position for user
						}

						cout << " Position" << endl; //Goes inline with the previous output

						for (int i = 0; i < count; i++)
							cout << right << setw(3) << arrPtr[i] << " "; //Output array integers

						cout << " File Data"; //Goes inline with the previous output

						menu(arrPtr, count, search, choice); //Call menu to preform user selected function from menu choice
					}
				}
				else //File cannot be opened
				{
					cout << "\ncould not access file\n" << endl; //Display Error Message
					open = 2; //Close out of while loop now
				}

				inputText.close(); //Close Input Test File
			}

			delete arrPtr; //Dealocate memory array.
			arrPtr = NULL; //Set pointer to null.
		}
	}
	return 0;
}