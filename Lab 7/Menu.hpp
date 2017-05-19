/****************************************************************************
** Program Filename: Lab 7
** Author: Stephen Townsend
** Date: 11/13/16
** Description: This is the Menu.hpp.  Used for function initialization.
** Input: None
** Output: None
*****************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include "LinearSearch.hpp"
#include "BubbleSort.hpp"
#include "BinarySearch.hpp"

#include <iostream>
#include <string>

using namespace std;

void menu(int *, int, int, string);
void menuInputVal(string &);
void yesOrNoValidation(string &);
void newSearch(int &);

#endif // !LINEARSEARCH_HPP