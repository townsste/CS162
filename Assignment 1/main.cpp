/*****************************************************************************************

Author: Stephen Townsend
Date: 10/08/2016
Description: This program is used to play through Langton's Ant.  The purpose of the 
program is to deminstarte a turning machine in 2D space.  The grid will use the forground
black squares and # markes for white squares.  The Ant isa extended ascii square character.

When the ant touches a white square it is supose to turnright 90 degrees and turn the 
square it was on black.  If the ant touches a black square then it will turn left 90 degrees
and tun the previous square white.

*****************************************************************************************/


#include "Menu.hpp"

int main()
{
	char mChoice = 0;

	cout << "The grid will be limited to a min of 20x20 and max of 60x60, " 
		<< "due to screen size differences" << endl;

	cout << "\nOption 1: Choose Location" << endl
		 << "Option 2: Random Location" << endl
		 << "Please enter a choice: ";
	cin >> mChoice;

	menu(mChoice);

		//cin.get();
		//cin.get();

		return 0;
	}