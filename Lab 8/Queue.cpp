/****************************************************************************
** Program Filename: Lab 8
** Author: Stephen Townsend
** Date: 11/20/16
** Description: This is the Queue.cpp.
** Input: Enter a choice for the menu
** Output: Outputs the options to make a choice for which function you want
**			   to run.
*****************************************************************************/

#include "Queue.hpp"

/****************************************************************************
** Function: Queue::Queue()
** Description: Default constructor setting the pointers to the first node
** Parameters: None
** Pre-Conditions: pointers initialized in header
** Post-Conditions: Pointers set to NULL
** Return: None
*****************************************************************************/

Queue::Queue()
{
	front = new QueueNode; //New front node
	front->data = -1; //Node Empty
	back = front; //Set back to front for first node
	front->next = back; //Set front next to back node
	back->prev = front; //Set back prev to front node
	front->prev = back; //Set front prev to back node
	back->next = front; //Set back next to front node
}

/****************************************************************************
** Function: ~Queue()
** Description: Deconstructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Deallocate memory items.
** Return: None
*****************************************************************************/

Queue::~Queue()
{
}

/****************************************************************************
** Function: void addBack()
** Description: Create a new node and add a node to the queued list.
** Parameters: Check the nodes position in the queue.
** Pre-Conditions: Valid data input from menu.
** Post-Conditions: A new node is made and pointed to by a pointer as created.
** Return: None
*****************************************************************************/

void Queue::addBack(int data)
{
	if (front-> data == -1) //Is front empty
	{
		front->data = data; //Add data to front node
		back = front; //Bring back to front due to empty queue
	}
	else if (back->next->data == -1) //Check for another empty node
	{
		back = back->next; //Move back to next empty node
		back->data = data; //Set empty nodes data
	}
	else if (back->next == front) //If next node is front then no empty nodes
	{
		back->next = new QueueNode; //Add new node to back of list
		back->next->prev = back; //The new nodes prev point to last back node
		back = back->next; //Move back to new node after connection made
		back->data = data; //Set new node data
		back->next = front; //Point back node to front node
		front->prev = back; //Point front node to back node
	}
}

/****************************************************************************
** Function: string removeFront()
** Description: Check and move front to next node and set to -1.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: A new node is top of the list.
** Return: None
*****************************************************************************/

void Queue::removeFront()
{
	if (front->data == -1) //Queue is empty
		cout << "\n\nThe queue is empty" << endl << endl; //Output empty
	else
	{
		front->data = -1; //Set node to empty
		front = front->next; //Move front to next node
		if (back == front)
			back = back->next; //Move back if front is at the back

		cout << "\nSuccessfully Removed\n" << endl; //Output confirmation
	}
}

/****************************************************************************
** Function: void getFront()
** Description: Display The top node.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

int Queue::getFront()
{
	return front->data; //Return data in the top node.
}

/****************************************************************************
** Function: void displayEntireQueue()
** Description: Display everything in the linked list
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

void Queue::displayEntireQueue()
{
	QueueNode *transverseNode = front->prev; //Transverse pointer.  Used to output the queue.
	int nodeCounter = 0;
	int emptyNodeCounter = 0;
	
	cout << endl; //Output new line

	do
	{
		nodeCounter++; //Add one to count for position
		if (transverseNode->data == -1)
			emptyNodeCounter++; //Node is empty add to its own count to display the total empty nodes

		transverseNode = transverseNode->next; //Move transverse to next node
	} 
	while (transverseNode->next != front); //Check entire list

	transverseNode = front; //Start at front

	if (emptyNodeCounter == nodeCounter) //Empty List
	{
		cout << "The Queue is completely empty"; 
		nodeCounter == 0;
	}
	
	while (nodeCounter > 0)
	{
		if (transverseNode->data != -1) //Dont output empty node
		{
			cout << transverseNode->data << " "; //Output the data in the current node.
			transverseNode = transverseNode->next; //Move to next node
		}
		
		nodeCounter--; //Reduce counter by one.
	}

	cout << "\nEmpty Nodes: " << emptyNodeCounter << endl << endl; //Total amount of empty nodes

	transverseNode = NULL; //Remove pointer and set to NULL
}

/****************************************************************************
** Function: void cleanup()
** Description: Delete all allocated memory and NULL all pointers to prevent 
					leaks.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Everything is deallocated and set to NULL.
** Return: None
*****************************************************************************/

void Queue::cleanup()
{
	delete back->prev;
	back->prev = NULL;
	delete back->next;
	back->next = NULL;
	delete back;
	back = NULL;
	delete front->prev;
	front->prev = NULL;
	delete front->next;
	front->next = NULL;
	delete front;
	front = NULL;
}
