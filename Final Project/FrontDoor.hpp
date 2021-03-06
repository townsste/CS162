/****************************************************************************
** Program Filename: Final Project
** Author: Stephen Townsend
** Date: 12/6/16
** Description: This is the FrontDoor.hpp. This creates the FrontDoor class
** Input: None
** Output: None
*****************************************************************************/

#ifndef FRONTDOOR_HPP
#define FRONTDOOR_HPP

#include "Hospital.hpp"


class FrontDoor : public Hospital
{
protected:

public:
	virtual void choices();
	virtual void useItem();
	virtual void setItem(string);
	virtual string getItem();
	virtual string getRoom();
	virtual bool somethingHappens(int);
	virtual void setLocation();
	virtual void setDead();
	virtual STATUS getState();
	virtual void story();

	FrontDoor();
	FrontDoor(string);
};
#endif // !FRONTDOOR_HPP
