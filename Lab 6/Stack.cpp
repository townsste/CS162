/****************************************************************************
** Program Filename: Lab 6
** Author: Stephen Townsend
** Date: 11/6/16
** Description: This is the main.cpp.
** Input: Enter a choice for the menu
** Output: Outputs the options to make a choice for which function you want
**			   to run.
*****************************************************************************/
#include "Stack.hpp"

/****************************************************************************
** Function: Stack::Stack()
** Description: Default constructor setting the pointers to NULL
** Parameters: int input 1, 2, or 3
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

Stack::Stack(string num, Stack *newPtr)
{
	number = num;
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
** Function: bool checkStack()
** Description: Check to see if head is pointing to the first node.
** Parameters: if node exists then head will no be NULL
** Pre-Conditions: Head is either pointing to a node or not pointing to a node
** Post-Conditions: None
** Return: True or False
*****************************************************************************/

bool Stack::checkStack()
{
	if (head == NULL)
		return false; //return false if head is pointing to NULL
	else
		return true; //return ture if head is pointing to node
}

/****************************************************************************
** Function: void push()
** Description: Create a new node and add a node to the stacked list.
** Parameters: Check the nodes position in the stack.
** Pre-Conditions: Valid data input from menu.
** Post-Conditions: A new node is made and pointed to by a pointer as created.
** Return: None
*****************************************************************************/

void Stack::push(string data)
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

	transversePtr = head; //Transverse pointer.  Used to output the stack.
	while (transversePtr != NULL) //While pointer is not at the end of stacked linked list.
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

string Stack::pop()
{
	if (head->next == NULL) //Check to see onely one node in the stack
	{
		cout << "Only have one item in list cannot remove anything" << endl << endl; //output to user.
		return ""; //No number to return.  Return empty string.
	}

	nextPtr = head; //Move pointer to point to top node in stack.
	head = head->next; //Move head to the next node in stack.
	transversePtr = head; //Shift the transverse pointer.
	delete nextPtr; //Remove node that nextPtr is pointing to.
	nextPtr = NULL; //Set pointer to Null to prevent it from dangling.

	while (transversePtr != NULL) //While pointer is not at the end of stacked linked list.
	{
		cout << transversePtr->number << endl; //Output the data in the current node.
		transversePtr = transversePtr->next; //Set pointer to next node.
	}
	return head->number; //Return data in the top node.
}