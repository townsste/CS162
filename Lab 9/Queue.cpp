/****************************************************************************
** Program Filename: Lab 9
** Author: Stephen Townsend
** Date: 11/27/16
** Description: This is the Queue.cpp. It is a simulator that is used to add 
					or remove a random number to a queue
** Input: None
** Output: Each round and what was added, or removed, and the average queue 
				length
*****************************************************************************/

#include "Queue.hpp"

/****************************************************************************
** Function: randomNum()
** Description: Generates a random number
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: random
*****************************************************************************/
int randomNum()
{
	int random = rand() % 1000 + 1; //Random int from 1 to 1000

	return random; //Return int to call
}

/****************************************************************************
** Function: queueSimulator()
** Description: Runs the queue simulator.  Gets a random number and adds to or 
					removes from queue.
** Parameters: int &sim, int add, int remove
** Pre-Conditions: User inputs the percentage to add and remve and the run 
						amount.
** Post-Conditions: None
** Return: random
*****************************************************************************/
void queueSimulator(int &sim, int add, int remove)
{
	queue<int> buffQueue; //STL Queue
	int random = 0; //Holds random int from call
	double avgQueueLength = 0; //Keep track of average length
	int rounds = 1;
	bool somethingHappened = false; //If queue added or removed flagg

	cout << "\n\n::After each round press enter to continue::" << endl;
	cin.get();

	while (sim != 0)
	{
		cout << "\nRound " << rounds << endl << endl;

		random = randomNum(); //Call to get random number
		
		if (rand() % 100 < add) //Add if rand is less than percentage by user
		{
			cout << "Added " << random << " to the queue" << endl << endl; //Display adding to queue
			buffQueue.push(random); //Add to queue
			avgQueueLength += buffQueue.size(); //Add to calculate average length
			somethingHappened = true; //Flag

		}

		if (rand() % 100 < remove) //Remove if rand is less than percentage by user
		{
			somethingHappened = true; //Flag

			if (!buffQueue.empty())
			{
				cout << "Removed " << buffQueue.front() << " from the queue" << endl << endl; //Display removal from queue
				buffQueue.pop(); //Remove from queue
				avgQueueLength -= buffQueue.size(); //Remove from calculate average length
			}
			else
				cout << "Queue is empty. Cannot remove" << endl << endl;
		}

		if (somethingHappened == false) //Test flag
			cout << "Nothing happened this round" << endl << endl; //Neither added or removed display
		else
		{
			somethingHappened = true; //Something Happened previously - Reset flag
			somethingHappened = false;
		}

		cout << "Current queue length: " << buffQueue.size() << endl; //Current queue length display
		cout << "Average queue length: " << setprecision(2) << (avgQueueLength / rounds) << endl; //Average queue length display

		sim--; //Decrease simulator count
		rounds++; //Increase round count

		cin.get(); //Pause for user to process data
		cout << "--------------------------------------------\n"; //Output line

	}

	cout << "::End of queue simulation::" << endl; //Finished
	cout << "--------------------------------------------\n" << endl; //Output line
	cin.get(); //Pause for user to process
}

/****************************************************************************
** Function: checkIntVal()
** Description: Validates the user int input from main
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Input is valid
** Return: Valid input
*****************************************************************************/
int checkIntVal()
{
	string check;
	int val;

	while (getline(cin, check))
	{
		stringstream test(check); //Stream string object to test
		test >> val; //Push string object into int

		if (test.eof()) //if end of string and valid then
			return val; //return int
		else
			cout << "Please enter an integer: "; //String not valid
	}
}