/*****************************************************************************************

Author: Stephen Townsend
Date: 10/23/2016
Description: This is the List header.  This is used to initialize the List class and
all of its variables and functions.

*****************************************************************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include "Item.hpp"

#include <iostream>
#include <iomanip>

using namespace std;

class List
{
private:
//Class variables
	int itemAmount = 4; //Total Array size
	int curItemTotal; //Amount of items in array
	Item *itemArray = new Item[itemAmount];  //Dynamic allocate Item array
	

public:
//Class member functions
	void addItem(Item*);
	void removeItem(string*);
	void printList();
	bool checkItem(Item&);

//Constructor
	List(); //default
};
#endif // !LIST_HPP