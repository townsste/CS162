/*****************************************************************************************

Author: Stephen Townsend
Date: 09/27/2016
Description: This determinant.cpp is used for the function that will be used to calculate
the determinant and return the result.

*****************************************************************************************/

#include "determinant.hpp"

/*****************************************************************************************
**									determinant 
** This function is used to calculate the determinant from the aray that the user filled 
** in readmatrix.  It has two parameters, one is a double pointer to the matrix array.
** The second is squareSize.  There are no prompts, but the result will be returned back 
** to the call.
**
*****************************************************************************************/
int determinant(int **pMatrix, int squareSize)
{
	int deter = 0;
	int a = 0, b = 0, c = 0, 
		d = 0, e = 0, f = 0, 
		g = 0, h = 0, i = 0;

	if (squareSize == 2) //Calculate determinant based on 2x2
	{		
		a = pMatrix[0][0];
		b = pMatrix[0][1];
		c = pMatrix[1][0];
		d = pMatrix[1][1];

		//Formula: ad-bc
		deter = (a*d) - (b*c);
	}

	if (squareSize == 3) //Calculate determinant based on 3x3
	{
		a = pMatrix[0][0];
		b = pMatrix[0][1];
		c = pMatrix[0][2];
		d = pMatrix[1][0];
		e = pMatrix[1][1];
		f = pMatrix[1][2];
		g = pMatrix[2][0];
		h = pMatrix[2][1];
		i = pMatrix[2][2];

		//Formula: aei+bfg+cdh-ceg-bdi-afh
		deter = (a*e*i) + (b*f*g) + (c*d*h) - (c*e*g) - (b*d*i) - (a*f*h);
	}
	return deter;
}