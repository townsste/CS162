/****************************************************************************
** Program Filename: Lab 6
** Author: Stephen Townsend
** Date: 11/6/16
** Description: This is the Stack.hpp.  It is used to make a Stack class.
** Input: None
** Output: None
*****************************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include <string>
#include <iostream>
using namespace std;

class Stack
{
private:
	string number;
	Stack *head;
	Stack *next;
	Stack *nextPtr;
	Stack *transversePtr;

public:
	bool checkStack();
	void push(string input);
	string pop();

	Stack();
	Stack(string, Stack*);
	~Stack();
};
#endif // !STACK_HPP