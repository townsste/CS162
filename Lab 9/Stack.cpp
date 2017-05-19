/****************************************************************************
** Program Filename: Lab 9
** Author: Stephen Townsend
** Date: 11/27/16
** Description: This is the Stack.cpp. It is used to create a palindrome from 
					a string.
** Input: None
** Output: If the string was already a palindrome.
*****************************************************************************/

#include "Stack.hpp"

string palindrome(string &input)
{
	string stackString;
	char strChar;

	stack<char, vector<char> > palStack; //STL Stack with vector

	for (int i = 0; i < input.size(); i++) //Loop through stack to push input
	{
		strChar = input[i]; //Get string character
		palStack.push(strChar); //Add string character to stack
	}
			
			
	while (!palStack.empty()) //Do while stack is not empty
	{
		stackString += palStack.top(); //Add stack character to a new string
		palStack.pop(); //Remove character from stack
	}


	if (input.compare(stackString) == 0) //Compare the input string with new stack stream
	{
		cout << endl << input << " is already a palindrome" << endl; //String was a palindrome
		return input; //Return original.  No modification
	}
	else
	{
		input += stackString; //String not palindrome.  Add the new stack string to the input string
		return input; //Return as palindrome
	}
}