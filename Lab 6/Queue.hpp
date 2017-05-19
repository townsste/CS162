/****************************************************************************
** Program Filename: Lab 6
** Author: Stephen Townsend
** Date: 11/6/16
** Description: This is the Queue.hpp.  It is used to make a Queue class.
** Input: None
** Output: None
*****************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <string>
#include <iostream>
using namespace std;

class Queue
{
private:	
	string number;
	Queue *head;
	Queue *next;
	Queue *nextPtr;
	Queue *transversePtr;

public:
	bool checkQueue();
	void push(string number);
	string pop();

	Queue();
	Queue(string);
	~Queue();
};
#endif // !QUEUE_HPP
