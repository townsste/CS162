/*****************************************************************************************

Author: Stephen Townsend
Date: 10/08/2016
Description: This is the AntGrid.cpp.  This is the programs base.  This is where the 
program will dynamically allocate an array based on the users input from menu.  This holds
the movement, the display of the grid, setting the grid, checking the color of the location,
and updating the grid.

*****************************************************************************************/

#include "AntGrid.hpp"

/*****************************************************************************************
**								AntGrid()
**  Default constructor.
*****************************************************************************************/
AntGrid::AntGrid()
{

}


/*****************************************************************************************
**								AntGrid(int, int)
**  Two parameter constructor used to initialize the Dynamic array based on the users
**  inputs from menu.cpp.
*****************************************************************************************/
AntGrid::AntGrid(int r, int c)
{
	//Dynamic array - Pointer of pointer
	char **antGrid;
	grid = new char *[r];
	for (int i = 0; i < r; i++)
		grid[i] = new char[c];
}


/*****************************************************************************************
**								~AntGrid()
**  Deconstructor
*****************************************************************************************/
AntGrid::~AntGrid()
{
	//Delete dynamic array
	for (int i = 0; i < paraX; ++i)
		delete[] grid[i];
	delete[] grid;
}


/*****************************************************************************************
**								displayBorder()
**  This function is used to display a border around the ants grid.
*****************************************************************************************/

void AntGrid::displayBorder()
{

for (int gLeftTC = 0; gLeftTC < 1; gLeftTC++) //Left Top Corner
{
cout << leftTCorner;
}


for (int gTop = 1; gTop <= paraX+1; gTop++) //Top
{
cout << topBottom;
}


for (int gRightTC = paraX + 3; gRightTC <= paraX + 3; gRightTC++) //Right Top Corner
{
cout << rightTCorner << endl;;
}


displayGrid(); //Call the function to display array


for (int gLeftBC = 0; gLeftBC < 1; gLeftBC++) //Left Bottom Corner
{
cout <<  lefBCorner;
}


for (int gBottom = 1; gBottom <= paraX+1; gBottom++) //Bottom
{
cout << topBottom;
}


for (int gRightBC = paraX + 3; gRightBC <= paraX + 3; gRightBC++) //Right BottomCorner
{
cout << rightBCorner; 
}
}


/*****************************************************************************************
**									displayGrid()
**  This function is used to display the ants grid.
*****************************************************************************************/
void AntGrid::displayGrid()
{
	for (int i = 0; i < paraX; i++)
	{
		cout << side;  //This is used to make the right side of a border
		for (int j = 0; j < paraY; j++)
			cout << grid[i][j];
		cout << " " << side << endl;  //This is used to make the left side of a border
	}
}


/*****************************************************************************************
**									setGrid()
**  This functon is used to set the grid to BLACK.  It will fill teh array.
*****************************************************************************************/
void AntGrid::setGrid(int row, int col)
{
	paraX = row;
	paraY = col;
	
	for (int i = 0; i < paraX; i++)
		for (int j = 0; j < paraY; j++)
			grid[i][j] = ' ';
}


/*****************************************************************************************
**									setLocation()
**  This function is used to set the starting location of the ant.
*****************************************************************************************/
void AntGrid::setLocation(int x, int y)
{
	locX = x;

	locY = y;
}


/*****************************************************************************************
**									setSteps()
**  This function is used to set the users desired ants steps.
*****************************************************************************************/
void AntGrid::setSteps(int antSteps)
{
	steps = antSteps;
}


/*****************************************************************************************
**									colorStatus()
**  This function is used to determine if the current location is WHITE or BLACK.
*****************************************************************************************/
Color AntGrid::colorStatus(int x, int y)
{
	if (grid[x][y] == ' ')
		return BLACK;
	else
		return WHITE;
}


/*****************************************************************************************
**										 move()
**  This function is used to call various functions that involve the ants movement.
**  This function casues the ant to  move accross the screen.
*****************************************************************************************/
void AntGrid::move()
{
	char dir = antObj.getDir(); //get the ants starting direction.
	int antSteps = 0;  //curent steps taken counter.


	displayBorder();  //Call the border function


	//While loop that will go through all the ants movements untill the step count is met.
	while (antSteps != steps + 1) // +1 is added to show the final ant step on counter
	{
		squareColor = colorStatus(locX, locY); //Get the color of the swuare at the next location
		
		grid[locX][locY] = antObj.getAnt();  //Get the ant's icon from Ant.cpp

		//system("cls"); //Clear the screen
	//	cout << string(100, '\n');

		//Display a counter of the current steps taken
		cout << setw(paraY/2) << "Step Count: " << antSteps << "/" << steps << endl; 

		displayBorder();

		//If the square is White -- Movment
		if (squareColor == WHITE)
		{
			grid[locX][locY] = ' ';

			if (dir == 'N') //Move right
			{
				locY += 1;
				dir = 'E';
			}
			else if (dir == 'E') //Move down
			{
				locX += 1;
				dir = 'S';
			}
			else if (dir == 'S') //Move left
			{
				locY -= 1;
				dir = 'W';
			}
			else if (dir == 'W') //Move up
			{
				locX -= 1;
				dir = 'N';
			}
		}

		//If the square is Black -- Movment
		else if (squareColor == BLACK) 
		{
			grid[locX][locY] = '#';
			
			if (antSteps == 0) //Starting movement up one
			{
				locX -= 1;
			}

			else if (dir == 'N') //Move right
			{
				locY -= 1;
				dir = 'W';
			}
			else if (dir == 'W') //Move down
			{
				locX += 1;
				dir = 'S';
			}
			else if (dir == 'S') //Move left
			{
				locY += 1;
				dir = 'E';
			}
			else if (dir == 'E') //Move up
			{
				locX -= 1;
				dir = 'N';
			}
		}
	
		antSteps += 1; //Add one to current step

		//Sleep(1000); //Windows version to slow dow the ants movements
		usleep(100000);  
	}
}