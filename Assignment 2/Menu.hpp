/*****************************************************************************************

Author: Stephen Townsend
Date: 10/23/2016
Description: This is the menu header.  This is used to initialize the menu and input 
validation functions.  This is seperated out into its own header and cpp so that it can be 
reused as a tool in other code that requires a menu.

*****************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include "Item.hpp"
#include "List.hpp"

#include <iostream>
#include <string>

using namespace std;

void menu(char);
double inputValidation(double);
void clearBuffer();

#endif