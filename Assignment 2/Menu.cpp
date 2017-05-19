/*****************************************************************************************

Author: Stephen Townsend
Date: 10/23/2016
Description: This is the Menu.cpp.  This is used to instruct the user so that they can 
start theprogram. It also includes an input validations that will test if a input is 
invalid.

*****************************************************************************************/


#include "Menu.hpp"

int main()
{
	char mChoice = 0;

	menu(mChoice);
}

/*****************************************************************************************
**										menu()
**  This is the menu function.  It will prompt the user for various options
*****************************************************************************************/
void menu(char mChoice)
{
	string name;
	string unit;
	double quantity;
	double price;

	Item *pItem = NULL;
	List listObj; 
	
	do
	{
		cout << "::Choose an Option::" << endl;
		cout << "1: Add Item" << endl;
		cout << "2: Remove Item" << endl;
		cout << "3: Show List" << endl;
		cout << "Q: Exit" << endl;
		cout << "\nChoice:  ";
		cin >> mChoice;

		mChoice = tolower(mChoice);

		clearBuffer();

		if (mChoice == 49) //If choice is 1 (Add Item)
		{
				cout << "\nName: ";
				getline(cin, name);

				cout << "\nUnit Type: ";
				getline(cin, unit);

				cout << "\nQuanitity: ";
				cin >> quantity;
				quantity = inputValidation(quantity);  //Validate that input is not char

				cout << "\nPrice: ";
				cin >> price;
				price = inputValidation(price); //Validate that input is not char

				pItem = new Item(name, unit, quantity, price);  //Create ItemObj with constructor

				if (listObj.checkItem(*pItem) == false)
				{
					listObj.addItem(pItem); //Call the addItem function in list
				}
				else
				{
					cout << endl << name << " is already in the list" << endl << endl;
				}
		}
		else if (mChoice == 50)  //If choice is 2 (Remove Item)
		{
			cout << "\nPlease enter the name of the item in the list to remove" << endl;
			getline(cin, name); //Get the name of item to remove

			listObj.removeItem(&name); //Call the removeItem function in list
		}
		else if (mChoice == 51) //If choice is 3 (Print List)
		{
			
			listObj.printList(); //Call the print function in list

		}

		else if (mChoice != 'q')
		{
			cout << "\nPlease enter 1, 2, 3 or Q: " << endl << endl;
		}
	}
	while (mChoice != 'q');
}

void clearBuffer()
{
	cin.clear(); //clear buffer error
	cin.ignore(100, '\n'); //clear the input buffer
}

double inputValidation(double input)
{
	while (cin.fail())
	{
		clearBuffer(); //Clear input flag to allow input

		cout << "Please enter a number: ";
		cin >> input;
	}

	clearBuffer(); //Clear input flag to allow input in case user entered intchar
	return input;  //return valid input
}
