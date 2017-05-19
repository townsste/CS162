/****************************************************************************
** Program Filename: Final Project
** Author: Stephen Townsend
** Date: 12/6/16
** Description: This is the Hospital.cpp. This for the constructors
** Input: None
** Output: None
*****************************************************************************/

#include "Hospital.hpp"

/****************************************************************************
** Function: Hospital()
** Description: Default Constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

Hospital::Hospital()
{
	point1 = NULL;
	point2 = NULL;
	point3 = NULL;
	point4 = NULL;
}

/****************************************************************************
** Function: Hospital(string loc)
** Description: 1 parameter constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

Hospital::Hospital(string loc)
{
	position = loc;
	state = ALIVE;
	bag = "Empty";
	action = 0;
}