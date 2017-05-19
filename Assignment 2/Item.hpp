/*****************************************************************************************

Author: Stephen Townsend
Date: 10/23/2016
Description: This is the Item header.  This is used to initialize the Item class and
all of its variables and functions.

*****************************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>


using namespace std;

class Item
{
private:
	string name;
	string unit;
	double quantity;
	double unitPrice;

public:
//Accessors
	string getName();
	string getUnit();
	double getQuantity();
	double getPrice();
	bool operator==(Item&);

//Constructors
	Item();
	Item(string, string, double, double);
};
#endif // !ITEM_HPP