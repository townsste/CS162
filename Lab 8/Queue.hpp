/****************************************************************************
** Program Filename: Lab 8
** Author: Stephen Townsend
** Date: 11/20/16
** Description: This is the Queue.hpp.  It is used to make a Queue class.
** Input: None
** Output: None
*****************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <string>
#include <iostream>
using namespace std;


struct QueueNode
{
	int data;
	QueueNode *next;
	QueueNode *prev;
};

class Queue
{
private:	
	QueueNode *front;
	QueueNode *back;

public:
	void addBack(int number);
	void removeFront();
	int getFront();
	void displayEntireQueue();
	void cleanup();

	Queue();
	~Queue();
};
#endif // !QUEUE_HPP
