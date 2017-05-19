/****************************************************************************
** Program Filename: Final Project
** Author: Stephen Townsend
** Date: 12/6/16
** Description: This is the Hospital.hpp. This is a pure abstract base class
** Input: None
** Output: None
*****************************************************************************/

#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

//#include <string>
#include <iostream>
using namespace std;

enum STATUS { ALIVE, DEAD };

class Hospital
{
protected:
	string position;
	STATUS state;
	Hospital *point1;
	Hospital *point2;
	Hospital *point3;
	Hospital *point4;
	string bag;
	int action;
	int itemResult;

public:
	virtual void choices() = 0;
	virtual void useItem() = 0;
	virtual void setItem(string) = 0;
	virtual string getItem() = 0;
	virtual string getRoom() = 0;
	virtual bool somethingHappens(int) = 0;
	virtual void setLocation() = 0;
	virtual void setDead() = 0; //strength check
	virtual STATUS getState() = 0; //Alive or Dead
	virtual void story() = 0;


	Hospital();
	Hospital(string);
};
#endif // !HOSPITAL_HPP
