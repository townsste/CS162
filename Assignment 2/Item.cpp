/*****************************************************************************************

Author: Stephen Townsend
Date: 10/23/2016
Description: This is the Item cpp.  This where the Item class creates objects dynamically
based on the users inputes.  Everything things is set through the 4 parameter constructor.
The functions are accessor functions besides the operator function.  The operator function
is used to overload the == operator to compare an Item object name before it is added into
the list.  This operator is called within the List class.

*****************************************************************************************/

#include "Item.hpp"


/*****************************************************************************************
**										Item()
**  This is the default constructor.  It initializes the member variables to their 
**  respective zeros.
*****************************************************************************************/
Item::Item()
{
	name = "";
	unit = "";
	quantity = 0;
	unitPrice = 0.0;
}


/*****************************************************************************************
**							Item(sting, string, double, double)
**  Four parameter constructor.  This initializes the member variables to the users 
**  inputs.
*****************************************************************************************/
Item::Item(string prodName, string unitType, double qty, double price)
{
	name = prodName;
	unit = unitType;
	quantity = qty;
	unitPrice = price;
}


/*****************************************************************************************
**										getName()
**  
*****************************************************************************************/
string Item::getName()
{
	return name;
}


/*****************************************************************************************
**										getUnit()
**  
*****************************************************************************************/
string Item::getUnit()
{
	return unit;
}


/*****************************************************************************************
**									  getQuantity()
**  
*****************************************************************************************/
double Item::getQuantity()
{
	return quantity;
}


/*****************************************************************************************
**										getPrice()
**  
*****************************************************************************************/
double Item::getPrice()
{
	return unitPrice;
}


/*****************************************************************************************
**									operator==(Item &)
**  This is the overloading operator function.  It is used to compare an object name with 
**  what is in the list.
*****************************************************************************************/
bool Item::operator==(Item &item)
{
	return this->getName() == item.getName();
}
