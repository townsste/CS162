/****************************************************************************
** Program Filename: Lab 6
** Author: Stephen Townsend
** Date: 11/6/16
** Description: This is the Queue.cpp.
** Input: Enter a choice for the menu
** Output: Outputs the options to make a choice for which function you want
**			   to run.
*****************************************************************************/

#include "Queue.hpp"

/****************************************************************************
** Function: Queue::Queue()
** Description: Default constructor setting the pointers to NULL
** Parameters: int input 1, 2, or 3
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

Queue::Queue(string num)
{
	number = num;
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
** Function: bool checkQueue()
** Description: Check to see if head is pointing to the first node.
** Parameters: if node exists then head will no be NULL
** Pre-Conditions: Head is either pointing to a node or not pointing to a node
** Post-Conditions: None
** Return: True or False
*****************************************************************************/

bool Queue::checkQueue()
{
	if (head == NULL)
		return false; //return false if head is pointing to NULL
	else
		return true; //return ture if head is pointing to node
}

/****************************************************************************
** Function: void push()
** Description: Create a new node and add a node to the queued list.
** Parameters: Check the nodes position in the queue.
** Pre-Conditions: Valid data input from menu.
** Post-Conditions: A new node is made and pointed to by a pointer as created.
** Return: None
*****************************************************************************/

void Queue::push(string data)
{
	if (head == NULL) //If there is no node then create the first.
	{
		head = new Queue(data); //Create first new node and point head to it.
	}
	else
	{
		nextPtr = head; //Set pointer to current node.  Ready to add new node.

		while (nextPtr->next != NULL) //Check if at the last node.
			nextPtr = nextPtr->next; //Move nextPtr to the last node in queue.

		nextPtr->next = new Queue(data); //Add a node to the queue. Point to the first node.
	}

	transversePtr = head; //Transverse pointer.  Used to output the queue.
	while (transversePtr != NULL) //While pointer is not at the end of queue linked list.
	{
		cout << transversePtr->number << endl; //Output the data in the current node.
		transversePtr = transversePtr->next; //Set pointer to next node.
	}
}

/****************************************************************************
** Function: string pop()
** Description: Check and move head to next node and remove node from list.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: A new node is added to the list.
** Return: Return data in the top node.
*****************************************************************************/

string Queue::pop()
{

	if (head->next == NULL) //Check to see onely one node in the queue
	{
		cout << "Only have one item in list cannot remove anything" << endl << endl; //output to user.
		return ""; //No number to return.  Return empty string.
	}

	nextPtr = head; //Move pointer to point to top node in queue.
	head = head->next; //Move head to the next node in queue.
	transversePtr = head; //Shift the transverse pointer.
	delete nextPtr; //Remove node that nextPtr is pointing to.
	nextPtr = NULL; //Set pointer to Null to prevent it from dangling.
	 
	while (transversePtr != NULL) //While pointer is not at the end of queued linked list.
	{
		cout << transversePtr->number << endl; //Output the data in the current node.
		transversePtr = transversePtr->next; //Set pointer to next node.
	}

	return head->number; //Return data in the top node.
}