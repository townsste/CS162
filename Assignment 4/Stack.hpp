/****************************************************************************
** Program Filename: Assignment 4
** Author: Stephen Townsend
** Date: 11/20/16
** Description: This is the Stack.hpp.  It is used to make a Stack class.
** Input: None
** Output: None
*****************************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include "Creature.hpp"
#include <string>
#include <iostream>
using namespace std;

class Stack
{
private:
	Creature *creature;
	Stack *head;
	Stack *next;
	Stack *nextPtr;
	Stack *transversePtr;

public:
	void push(Creature *);
	void displayLineUp();
	Creature* getCreature();
	void pop();
	void cleanup();

	Stack();
	Stack(Creature *, Stack*);
	~Stack();
};
#endif // !STACK_HPP