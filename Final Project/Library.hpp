/****************************************************************************
** Program Filename: Final Project
** Author: Stephen Townsend
** Date: 12/6/16
** Description: This is the Library.hpp. This creates the Library class
** Input: None
** Output: None
*****************************************************************************/

#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Hospital.hpp"


class Library : public Hospital
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

	Library();
	Library(string);
};
#endif // !LIBRARY_HPP
