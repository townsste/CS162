/*****************************************************************************************

Author: Stephen Townsend
Date: 10/08/2016
Description: This is the AntGrid header.  This is used used to create the class AntGrid.
It has one Ant object variable and many private variables.  
There are three public functions (makeMove, gameState, and print).  There is one constructor 
that is the default constructor. It is used to initialize the array to being empty.
*****************************************************************************************/

#ifndef ANTGRID_HPP
#define ANTGRID_HPP


#include "Ant.hpp"
#include "Menu.hpp"
//#include <windows.h>  //Used for sleep for windows
#include <unistd.h> //Used for usleep on linux
#include <iomanip>

enum Color {WHITE, BLACK};

class AntGrid
{
private:
	Ant antObj;
	int paraX;
	int paraY;
	int locX;
	int locY;
	int steps;
	char **grid;
	Color squareColor;

	//Border Char
	char side = 186;
	char topBottom = 205;
	char leftTCorner = 201;
	char rightTCorner = 187;
	char lefBCorner = 200;
	char rightBCorner = 188;

public:
//Mutators
	void setGrid(int row, int col);  //set the grid array to BLACK

	void setLocation(int, int);  //Set the ants strating location

	void setSteps(int);  //Sets the ants steps from user

//Accessors
	void displayGrid();  //Outputsthe grid

	void displayBorder();  //Outputs a border areound the grid

	void move();  //Ants movement directions

	Color colorStatus(int, int);  //Dertermines if the square color

	AntGrid();

	AntGrid(int, int);

	~AntGrid();
};
#endif // !ANTGRID_HPP
