/****************************************************************************
** Program Filename: Final Project
** Author: Stephen Townsend
** Date: 12/6/16
** Description: This is the IP.hpp. This creates the IP class
** Input: None
** Output: None
*****************************************************************************/

#ifndef IP_HPP
#define IP_HPP

#include "Hospital.hpp"


class IP : public Hospital
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

	IP();
	IP(string);
};
#endif // !IP_HPP
