/*****************************************************************************************

Author: Stephen Townsend
Date: 10/23/2016
Description: This is the List cpp.  This is where an Item will either be added to the list
or removed from the list.  It will also output the list when requested by the user.

*****************************************************************************************/

#include "List.hpp"


/*****************************************************************************************
**										List()
**
*****************************************************************************************/
List::List()
{
}


/*****************************************************************************************
**									addItem(Item *)
**  This is the addItem function.  It is used to add an item to the list.  If the item is 
**  already ini the list then the function will not run due to the overloaded operater in 
**  menu.
*****************************************************************************************/
void List::addItem(Item *prodItem)
{
	if (curItemTotal < itemAmount) //Test to see if the array size to item count
	{
			itemArray[curItemTotal] = *prodItem; //add elements to array from item pointer
	}
	else
	{
		itemAmount += 1; //Increase total array size by 1 to fit new item

		Item *addItem = new Item[itemAmount]; //addItem(Temp) dynamic array to store content

		for (int i = 0; i < curItemTotal; i++) //Loop to add itemArray contents to addItem array
			addItem[i] = itemArray[i];
		
		addItem[curItemTotal] = *prodItem; //Add new item in addItem array
		
		delete[] itemArray; //Delete itemArray to be able to re allocate
		
		itemArray = new Item[itemAmount]; //Recreate itemArray with increased size

		for (int j = 0; j < itemAmount; j++) //Loop to add AddItem contents back to new itemArray
			itemArray[j] = addItem[j];
		
		delete[] addItem;  //Delete AddItem array
	}
	cout << "\nSuccessfully added " << itemArray[curItemTotal].getName() << endl << endl;

	curItemTotal += 1; //array element position counter.  Increment by up
}


/*****************************************************************************************
**									removeItem(string *)
**  This is the removeItem function.  It is used to remove an item from the list.  If 
**  there is no item in the list with then the output will reflect that.
*****************************************************************************************/
void List::removeItem(string *removName)
{
	Item *keepItem = new Item[itemAmount]; //Create new array (keepItem) that holds the items to keep
	int count = 0; //Track the amount of items to remove if multiple
	int index = 0; //Keep track of array conent position

	for (int i = 0; i < curItemTotal; i++) //Loop to check array and what will be kept
	{
		if (itemArray[i].getName().compare(*removName) != 0)
		{
			keepItem[index] = itemArray[i]; //Put kept info in keepItem array

			index++; //Add one to index for location of next item to add
		}
		else
		{
			count++;
		}
	}

	curItemTotal -= count; //Reduce the current total of items by what was removed.

	for (int j = 0; j < curItemTotal; j++) //Loop to copy the kept items back into itemArray.
		itemArray[j] = keepItem[j];

	delete[] keepItem; //Delete keepItem array

	if (count == 0)
	{
		cout << endl << *removName << " was not found " << endl << endl;  //Output the item was removed

	}
	else
	{
		cout << "\nSuccessfully removed " << *removName << endl << endl;  //Output the item was removed
	}
}


/*****************************************************************************************
**									printList()
**  This is the printList function.  It will output the data that is held in the itemArray.
**  This is also used to clculate the total price of the list.
*****************************************************************************************/
void List::printList()
{
	double totalPrice = 0;
	
	cout << setw(38) << "::SHOPPING LIST::" << endl;  //Header
	cout << fixed << showpoint << setprecision(2); //Format
	
	cout << left << setw(25) << "\nProduct"  //titles
		 << left << setw(12) << "Unit" 
		 << right << setw(6) << "QTY" 
		 << right << setw(11) << "Price" 
		 << right << setw(11) << "Extended" << endl;

	for (int i = 0; i < curItemTotal; i++)
	{
		totalPrice += (itemArray[i].getPrice() * itemArray[i].getQuantity()); //loop through list and add up prices

		cout << left << setw(24) << itemArray[i].getName()  //Data
			<< left << setw(11) << itemArray[i].getUnit()
			<< right << setw(7) << itemArray[i].getQuantity()
			<< right << setw(11) << itemArray[i].getPrice()
			<< right << setw(11) << (itemArray[i].getPrice() * itemArray[i].getQuantity()) << endl;
	}
	cout << setw(54) << "Total Price: " << right << setw(10) << totalPrice << endl; //Footer - Total Price
}


/*****************************************************************************************
**									checkItem(Item &)
**  This is the checkItem function.  It is used to loop through the array and call the 
**  overloaded function to test the user defined name.
*****************************************************************************************/
bool List::checkItem(Item &testItem)
{
	
	for (int i = 0; i < curItemTotal; i++) //Lopp through array to check each element to compare
		if ((itemArray[i].operator== (testItem) == true)) //Call overloaded operator
		{
			return true;
		}
	return false;
}

