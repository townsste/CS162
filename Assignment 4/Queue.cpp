/****************************************************************************
** Program Filename: Assignment 4
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
** Description: Default constructor setting the pointers to NULL
** Parameters: None
** Pre-Conditions: pointers initialized in header
** Post-Conditions: Pointers set to NULL
** Return: None
*****************************************************************************/

Queue::Queue()
{
	head = NULL;
	nextPtr = NULL;
	next = NULL;
	transversePtr = NULL;
}

/****************************************************************************
** Function: Queue::Queue(1 Parameter)
** Description: One parameter constructor.  Used to initialize input into the 
**			    	object.
** Parameters: string num and stack *newPtr
** Pre-Conditions: None
** Post-Conditions: Object now has user input.
** Return: None
*****************************************************************************/

Queue::Queue(Creature *add)
{
	creature = add;
	next = NULL;
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
** Function: void push()
** Description: Create a new node and add a node to the queued list.
** Parameters: Check the nodes position in the queue.
** Pre-Conditions: Valid data input from menu.
** Post-Conditions: A new node is made and pointed to by a pointer as created.
** Return: None
*****************************************************************************/

void Queue::push(Creature *add)
{
	if (head == NULL) //If there is no node then create the first.
	{
		head = new Queue(add); //Create first new node and point head to it.
	}
	else
	{
		nextPtr = head; //Set pointer to current node.  Ready to add new node.

		while (nextPtr->next != NULL) //Check if at the last node.
			nextPtr = nextPtr->next; //Move nextPtr to the last node in queue.

		nextPtr->next = new Queue(add); //Add a node to the queue. Point to the first node.
	}

	
}

/****************************************************************************
** Function: void displayLineUp()
** Description: Display the creatures in Queue
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

void Queue::displayLineUp()
{
	transversePtr = head; //Transverse pointer.  Used to output the queue.
	while (transversePtr != NULL) //While pointer is not at the end of queue linked list.
	{
		cout << transversePtr->creature->getCreature() << endl; //Output the data in the current node.
		transversePtr = transversePtr->next; //Set pointer to next node.
	}
}

/****************************************************************************
** Function: Creature* getCreature()
** Description: Get the creature at head of Queue to fight
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: Return creature pointer
*****************************************************************************/

Creature* Queue::getCreature()
{
	if (head != NULL)
		cout << head->creature->getCreature();
		return head->creature;
}


/****************************************************************************
** Function: string pop()
** Description: Check and move head to next node and remove node from list.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: A new node is added to the list.
** Return: Return data in the top node.
*****************************************************************************/

void Queue::pop()
{
	nextPtr = head; //Move pointer to point to top node in queue.
	head = head->next; //Move head to the next node in queue.
	transversePtr = head; //Shift the transverse pointer.
	delete nextPtr; //Remove node that nextPtr is pointing to.
	nextPtr = NULL; //Set pointer to Null to prevent it from dangling.
}

/****************************************************************************
** Function: void cleanup()
** Description: Delete all the Queue and set pointers to Null
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Everything is deallocated
** Return: None
*****************************************************************************/

void Queue::cleanup()
{
	delete head;
	head = NULL;
	delete nextPtr;
	nextPtr = NULL;
	delete next;
	next = NULL;
	delete transversePtr;
	transversePtr = NULL;
}