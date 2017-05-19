/*****************************************************************************************

Author: Stephen Townsend
Date: 10/08/2016
Description: This is the Ant.hpp.  This is used to hold the ant and the ants starting 
direction.

*****************************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP


class Ant
{
private:
	char ant = 219; //Ants icon
	char dir = 'N'; //Ants starting direction


public:
	char getAnt(); //Gets the ants icon

	char getDir(); //Gets the ants direction

	Ant();
};
#endif