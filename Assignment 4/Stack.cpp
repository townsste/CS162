/****************************************************************************
** Program Filename: Assignment 4
** Author: Stephen Townsend
** Date: 11/20/16
** Description: This is the Stack.cpp.
** Input: Enter a choice for the menu
** Output: Outputs the options to make a choice for which function you want
**			   to run.
*****************************************************************************/
#include "Stack.hpp"

/****************************************************************************
** Function: Stack::Stack()
** Description: Default constructor setting the pointers to NULL
** Parameters: None
** Pre-Conditions: pointers initialized in header
** Post-Conditions: Pointers set to NULL
** Return: None
*****************************************************************************/

Stack::Stack()
{
	head = NULL;
	nextPtr = NULL;
	next = NULL;
	transversePtr = NULL;
}

/****************************************************************************
** Function: Stack::Stack(2 Parameter)
** Description: Two parameter constructor.  Used to initialize input and 
**					pointer into the object.
** Parameters: string num and stack *newPtr
** Pre-Conditions: None
** Post-Conditions: Object now has user input and a pointer to the object
** Return: None
*****************************************************************************/

Stack::Stack(Creature *data, Stack *newPtr)
{
	creature = data;
	next = newPtr;
}

/****************************************************************************
** Function: ~Stack()
** Description: Deconstructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Deallocate memory items.
** Return: None
*****************************************************************************/

Stack::~Stack()
{
}

/****************************************************************************
** Function: void push()
** Description: Create a new node and add a node to the stacked list.
** Parameters: Check the nodes position in the stack.
** Pre-Conditions: Valid data input from menu.
** Post-Conditions: A new node is made and pointed to by a pointer as created.
** Return: None
*****************************************************************************/

void Stack::push(Creature *data)
{
	if (head == NULL) //If there is no node then create the first.
	{
		head = new Stack(data, head); //Create first new node and point head to it.
	}
	else
	{
		nextPtr = head; //Set pointer to current node.  Ready to add new node.
		head = new Stack(data, nextPtr); //Add a node to the stack. Point to the first node.
	}
}

/****************************************************************************
** Function: void displayLineUp()
** Description: Display the creatures in Stack
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

void Stack::displayLineUp()
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
** Description: Get the creature at head of stack to fight
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: Return creature pointer
*****************************************************************************/

Creature* Stack::getCreature()
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

void Stack::pop()
{
	nextPtr = head; //Move pointer to point to top node in stack.
	head = head->next; //Move head to the next node in stack.
	transversePtr = head; //Shift the transverse pointer.
	delete nextPtr; //Remove node that nextPtr is pointing to.
	nextPtr = NULL; //Set pointer to Null to prevent it from dangling.
}

/****************************************************************************
** Function: void cleanup()
** Description: Delete all the stack and set pointers to Null
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Everything is deallocated
** Return: None
*****************************************************************************/

void Stack::cleanup()
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