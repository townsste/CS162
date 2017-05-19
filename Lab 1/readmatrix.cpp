/*****************************************************************************************

Author: Stephen Townsend
Date: 09/27/2016
Description: This readmatrix.cpp is used for the function that will be used to fill the
dynamic array by usig a double pointer that points to a pointer of arrays.

*****************************************************************************************/

#include "readmatrix.hpp"
#include <iostream>

using namespace std;

/*****************************************************************************************
**										readMatrix 
** This function is used to fill an array that is being pointed to in main by using two 
** for loops.  This function is will promp the user to enter the values for the matrix.
**
*****************************************************************************************/
void readMatrix(int **pMatrix, int squareSize)
{
	cout << "Please enter your values." << endl;

	for (int row = 0; row < squareSize; row++)
	{
		for (int col = 0; col < squareSize; col++)
			cin >> pMatrix[row][col];
	}
}