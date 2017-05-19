/****************************************************************************
** Program Filename: Final Project
** Author: Stephen Townsend
** Date: 12/6/16
** Description: This is the Lab.hpp. This creates the Lab class
** Input: None
** Output: None
*****************************************************************************/

#ifndef LAB_HPP
#define LAB_HPP

#include "Hospital.hpp"


class Lab : public Hospital
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

	Lab();
	Lab(string);
};
#endif // !LAB_HPP
