/****************************************************************************
** Program Filename: Lab 10
** Author: Stephen Townsend
** Date: 12/3/16
** Description: This is the Iteration.cpp. This runs Fibonaccis Iteration
** Input: None
** Output: None

Code from: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
*****************************************************************************/

#include "Iteration.hpp"
#include <iostream>
FibonacciNR::FibonacciNR() {


}

FibonacciNR::FibonacciNR(const int &n) :n_(&n) {


}

  FibonacciNR::~FibonacciNR() {

}

 int FibonacciNR::Fibonacci(const int &n)
  {
     int first = 0;
     int second = 1;
   int counter = 2;
     while (counter < n)
     {
	         int temp = second;
	        second = first + second;
	         first = temp;
	         ++counter;
	    }
     if (n == 0)
	       return 0;
     else
	        return first + second;
  }
  void FibonacciNR::PrintFibonacci() {
	     const int result = Fibonacci(*n_);
}