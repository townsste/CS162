/****************************************************************************
** Program Filename: Lab 10
** Author: Stephen Townsend
** Date: 12/3/16
** Description: This is the Main.cpp. This program demonstrates the time 
					difference from recursion and iteration algorithms, by 
					using the Fibonacci sequence
** Input: Choose an Integer
** Output: The algorithm runtime
*****************************************************************************/

#include "Recursion.hpp"
#include "Iteration.hpp"
#include <ctime>  
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

int main()
{
	int checkIntVal(); //Function Prototype
	string runAgain = "Y";
	int input;
	string testDifferent;
	clock_t start;
	clock_t end;
	unsigned long time;

	while (runAgain.compare("Y") == 0 || runAgain.compare("y") == 0)
	{
		runAgain = "RESET";

		int input = 0;

		//Recursion Code from: Page 910 in Starting out with C++ Early Objects 8th Edition

		cout << "Fibonacci Recursion" << endl;
		input = checkIntVal(); //Input and Check int input

		cout << "\nStarting Fibonacci Recursion" << endl;
		cout << "     Running Recursion..." << endl;

		start = clock(); //Start time of algorithm

		for (int x = 0; x < input; x++)
			fibRecurs(x); //Recursion Call

		end = clock(); //Stop time of algorithm
		time = end - start; //Total Run time
		cout << "\n\nCompleted Iteration in " << time << " clocks and " << (float) time / CLOCKS_PER_SEC << " seconds" << endl << endl << endl;

	
		//Iteration Code from: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c

		cout << "Fibonacci Iteration" << endl;
		input = checkIntVal(); //Input and Check int input

		cout << "\nStarting Fibonacci Iteration" << endl;
		cout << "     Running Iteration..." << endl;

		FibonacciNR fnr(input); //Iteration object
		
		start = clock(); //Start time of algorithm

		fnr.PrintFibonacci(); //Iteration Call
		
		end = clock(); //Stop time of algorithm
		time = end - start; //Total Run time
		cout << "\nCompleted Iteration in " << time << " clocks and " << (float) time / CLOCKS_PER_SEC << " seconds" << endl << endl << endl;


		while (runAgain.compare("Y") != 0 && runAgain.compare("y") != 0 && runAgain.compare("N") != 0 && runAgain.compare("n") != 0)
		{
			cout << "Do you want to run again? (Y or N) ";
			getline(cin, runAgain);

			if (runAgain.compare("Y") != 0 && runAgain.compare("y") != 0 && runAgain.compare("N") != 0 && runAgain.compare("n") != 0)
				cout << "Please enter a valid response" << endl;

			cout << endl;
		}
	}
	return 0;
}

/****************************************************************************
** Function: checkIntVal()
** Description: Validates the user int input from main
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Input is valid
** Return: Valid input
*****************************************************************************/

int checkIntVal()
{
	string check;
	int val;

	cout << "Please enter an integer: ";

	while (getline(cin, check))
	{
		stringstream test(check); //Stream string object to test
		test >> val; //Push string object into int

		if (test.eof()) //if end of string and valid then
			return val; //return int
		else
			cout << "Please enter a valid integer: "; //String not valid
	}
}