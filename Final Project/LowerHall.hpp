/****************************************************************************
** Program Filename: Final Project
** Author: Stephen Townsend
** Date: 12/6/16
** Description: This is the LowerHall.hpp. This creates the LowerHall class
** Input: None
** Output: None
*****************************************************************************/

#ifndef LOWERHALL_HPP
#define LOWERHALL_HPP

#include "Hospital.hpp"


class LowerHall : public Hospital
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

	LowerHall();
	LowerHall(string);
};
#endif // !LOWERHALL_HPP
