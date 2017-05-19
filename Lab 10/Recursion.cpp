/****************************************************************************
** Program Filename: Lab 10
** Author: Stephen Townsend
** Date: 12/3/16
** Description: This is the Recursion.cpp. This runs Fibonaccis Recursion
** Input: None
** Output: None

Code from: Page 910 in Starting out with C++ Early Objects 8th Edition
*****************************************************************************/

int fibRecurs(int n)
{
	if (n <= 0)	//base case
		return 0;
	else if (n == 1) //base case
		return 1;
	else
		return fibRecurs(n - 1) + fibRecurs(n - 2);
}