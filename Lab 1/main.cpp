/*****************************************************************************************

Author: Stephen Townsend
Date: 09/27/2016
Description: This program is used to determine the determinant of a matrix.  There will be
a dynamic array that will be determined by the users input.  The user will be prompted for
the amount of values they would like to enter.  This choice willbe used to determine the
matrix size.  The user will then be prompted to enter their values from the readMatrix 
function.  Once the values are inputed the determinant will be calculatedand displayed
to the user along with the matrix.  Finnally the dynamic matrix will be deleted.

*****************************************************************************************/

#include "readmatrix.hpp"
#include "determinant.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int squareSize = 0;
	int deter = 0;
	int choice = 0;
	
	while (choice != 4 && choice != 9)
	{
		cout << "How many values are in your matrix? " 
			 << "4 or 9?" << endl;
		cin >> choice;

		//Determine the size of matrix based on value total
		if (choice == 4)
			squareSize = 2;
		else if (choice == 9)
			squareSize = 3;
		else
			cout << "Invlaid Choice\n" << endl;
	}

	//Dynamic array - Pointer of pointer
	int **pMatrix;
	pMatrix = new int *[squareSize];
	for (int i = 0; i < squareSize; i++)
		pMatrix[i] = new int[squareSize];

	readMatrix(pMatrix, squareSize); //readMatrix call

	deter = determinant(pMatrix, squareSize); //determinant call

	cout << "\nMatrix:"; //Display matrix
	
	for (int i = 0; i < squareSize; i++)
	{
		cout << endl;
		for (int j = 0; j < squareSize; j++)
			cout << setw(4) << pMatrix[i][j] << setw(2);
	}

	cout << "\nThe determinant is: " << deter << endl; //Display calculated determinant
	
	for (int i = 0; i < squareSize; ++i) //Delete dynamic array
		delete[] pMatrix[i];
	delete [] pMatrix;

	return 0;
}