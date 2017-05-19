/****************************************************************************
** Program Filename: Final Project
** Author: Stephen Townsend
** Date: 12/6/16
** Description: This is the ER.hpp. This creates the ER class
** Input: None
** Output: None
*****************************************************************************/

#ifndef ER_HPP
#define ER_HPP

#include "Hospital.hpp"


class ER : public Hospital
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

	ER();
	ER(string);
};
#endif // !ER_HPP
