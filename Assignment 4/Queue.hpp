/****************************************************************************
** Program Filename: Assignment 4
** Author: Stephen Townsend
** Date: 11/20/16
** Description: This is the Queue.hpp.  It is used to make a Queue class.
** Input: None
** Output: None
*****************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Creature.hpp"
#include <string>
#include <iostream>
using namespace std;

class Queue
{
private:
	Creature *creature;
	Queue *head;
	Queue *next;
	Queue *nextPtr;
	Queue *transversePtr;

public:
	void push(Creature *);
	void displayLineUp();
	Creature* getCreature();
	void pop();
	void cleanup();

	Queue();
	Queue(Creature *);
	~Queue();
};
#endif // !QUEUE_HPP
