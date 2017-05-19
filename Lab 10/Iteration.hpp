/****************************************************************************
** Program Filename: Lab 10
** Author: Stephen Townsend
** Date: 12/3/16
** Description: This is the Iteration.hpp. This is used to create the 
					Iteration class
** Input: None
** Output: None

Code from: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
	with minor modification to header title
*****************************************************************************/

#ifndef ITERATION_HPP
#define ITERATION_HPP

class FibonacciNR {
public:
	FibonacciNR(const int &n);
	virtual ~FibonacciNR();
	void PrintFibonacci();

private:
	FibonacciNR();
	int Fibonacci(const int &n);
	const int* n_;
};
#endif //ITERATION_HPP