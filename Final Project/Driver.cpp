/****************************************************************************
** Program Filename: Final Project
** Author: Stephen Townsend
** Date: 12/6/16
** Description: This is the Driver.cpp. This is where the progrm will loop 
					through the game.
** Input: Integer input from menu
** Output: Backstory
*****************************************************************************/

#include "Hospital.hpp"
#include "ER.hpp"
#include "IP.hpp"
#include "UpperHall.hpp"
#include "LowerHall.hpp"
#include "FrontDoor.hpp"
#include "Lab.hpp"
#include "Library.hpp"

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;


int main()
{
	//Function Prototype
	void backStory();
	int checkIntVal();
	void endStory();
	bool labTesting();

	Hospital *play = NULL;
	Hospital* array[4];
	Hospital *loadZone(string zone);

	string inventory = "EMPTY";
	int choice = 0;
	bool changeRoom = false;
	int front = 1;
	int lab = 1;
	int lib = 1;
	bool next = true;
	srand(time(NULL));
	int deathCounter = 0;

	backStory(); //Output Story
	
	play = loadZone("ER"); //Load the ER Room
	
	while (play->getState() == ALIVE)
	{
			play->choices(); //point to zone class

			cout << "Choice: ";
			choice = checkIntVal(); //Input and Check int input
			cout << "\n----------------------------------------------------------------------------------" << endl;
			cout << "Death Counter " << deathCounter << " / 15";
			cout << "\n----------------------------------------------------------------------------------" << endl << endl;

			changeRoom = play->somethingHappens(choice); //determine if room is done

			//Load from ER to In Paitent
			if (play->getState() == ALIVE && changeRoom == true && play->getRoom() == "ER")
			{
				inventory = play->getItem(); //Hold Inventory from Object
				delete play; //Delete prev dynamic object
				play = loadZone("IP"); //Create New Object
				play->setItem(inventory); //Set current Inventory item
				changeRoom = false; //Do not change room
			}

			//Load from IP to Upper Hall
			else if (play->getState() == ALIVE && changeRoom == true && play->getRoom() == "IP")
			{
				inventory = play->getItem(); //Hold Inventory from Object
				delete play; //Delete prev dynamic object
				play = loadZone("UpperHall"); //Create New Object
				play->setItem(inventory); //Set current Inventory item
				changeRoom = false; //Do not change room
			}

			//Load from Upper Hall to Lower Hall
			else if (play->getState() == ALIVE && changeRoom == true && play->getRoom() == "UpperHall")
			{
				inventory = play->getItem(); //Hold Inventory from Object
				delete play; //Delete prev dynamic object
				play = loadZone("LowerHall"); //Create New Object
				play->setItem(inventory); //Set current Inventory item
				array[0] = play; //Grab stored Object
				changeRoom = false; //Do not change room
			}

			//Load Front Door from Lower Hall
			else if (choice == 1 && play->getRoom() == "LowerHall")
			{
				if (front == 1) //Create counter. All ready ran this once
				{
					play = loadZone("FrontDoor"); //Create New Object
					array[1] = play; //Grab stored Object
					changeRoom = false; //Do not change room
					front++;
				}
				else
				{
					play = array[1]; //Grab stored Object
					play->setItem(inventory); //Set current Inventory item
					changeRoom = false; //Do not change room
				}
			}

			//Load Lab from Lower Hall
			else if (choice == 2 && play->getRoom() == "LowerHall")
			{
				if (lab == 1) //Create counter. All ready ran this once
				{
					play = loadZone("Lab"); //Create New Object
					play->setItem(inventory); //Set current Inventory item
					array[2] = play; //Grab stored Object
					changeRoom = false; //Do not change room
					lab++;
				}
				else
				{
					play = array[2]; //Grab stored Object
					play->setItem(inventory); //Set current Inventory item
					changeRoom = false; //Do not change room
				}
			}

			//Load Library from Lower Hall
			else if (choice == 3 && play->getRoom() == "LowerHall")
			{
				if (lib == 1) //Create counter. All ready ran this once
				{
					play = loadZone("Library"); //Create New Object
					play->setItem(inventory); //Set current Inventory item
					array[3] = play; //Grab stored Object
					changeRoom = false; //Do not change room
					lib++;
				}
				else
				{
					play = array[3]; //Grab stored Object
					play->setItem(inventory); //Set current Inventory item
					changeRoom = false; //Do not change room
				}
			}

			//Load Lower Hall from Front Door, Lab, or Library
			else if (play->getState() == ALIVE && changeRoom == true && play->getRoom() == "FrontDoor")
			{
				inventory = play->getItem(); //Hold Inventory from Object
				play = array[0]; //Grab Lower Hall Object from array
				changeRoom = false; //Do not change room
			}
			else if (play->getState() == ALIVE && changeRoom == true && play->getRoom() == "Lab")
			{
				play = array[0]; //Grab Lower Hall Object from array
				changeRoom = false; //Do not change room
			}
			else if (play->getState() == ALIVE && changeRoom == true && play->getRoom() == "Library")
			{
				inventory = play->getItem(); //Hold Inventory from Object
				play = array[0]; //Grab Lower Hall Object from array
				changeRoom = false; //Do not change room
			}
			deathCounter++;
			
			if (deathCounter == 16)
			{
				cout << "Time ran out and you died from you deadly disease" << endl << endl;
				break;
			}
	} //End While if Dead
	
	
	if (play->getState() == DEAD && play->getRoom() == "Lab") //Cleanup after Lab
	{
		for (int i = 0; i < 4; i++)
			delete array[i]; //Delete stored objects
		play = NULL; //Set pointer to Null

		endStory(); //Congratulations

		
		//Continue and run lab tests?
		do
		{
			cout << "Would you like to go through lab testing and find out your diagnosis?" << endl
				<< "     1. Yes" << endl
				<< "     2. No" << endl
				<< "Choice: ";
			choice = checkIntVal(); //Input and Check int input

			if (choice != 1 && choice != 2)
				cout << "Please enter a valid choice" << endl << endl;

		} while (choice == 1 && choice == 2);

		if (choice == 1)
		{
			do
			{
				next = labTesting(); //run testing
			} while (next != false);
		}
	}

	cout << "THE END" << endl;

	cin.get();
	cin.get();
	return 0;
}

/****************************************************************************
** Function: backStory()
** Description: Starting story for user
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

void backStory()
{
	cout << "Present day OSU, you are running and begin to feel feaverish and sick." << endl << endl
		<< "Your symptoms are:" << endl
		<< "     Sensitivity to light" << endl
		<< "     Headache" << endl
		<< "     Nausea" << endl
		<< "     Stiffness of neck" << endl << endl;

	cout << "All of a sudden your vision starts to close in and" << endl
		<< "You end up losing conciousness." << endl << endl
		<< "As you wake up, you ask, where am I?" << endl;

	cin.get();

	cout << "A nurse comes in and tells you: " << endl
		<< "     You are in the ER.  You were found unconcious at OSU." << endl
		<< "     We will need to admit you into the hospital." << endl
		<< "     This way we can examine you and keep you for observation." << endl;

	cin.get();
}

/****************************************************************************
** Function: endStory()
** Description: Completed the game
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

void endStory()
{
	cout << "Congratulation you made it to the Hospitals Laboratory." << endl << endl
		<< "This is a restricted zone and you should now be safe." << endl
		<< "With the help of the Lab Scientist you can figure out what is wrong with you" << endl << endl;
}

/****************************************************************************
** Function: labTesting()
** Description: The entire Lab Test
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/

bool labTesting()
{
	int checkIntVal();
	int choice = 0;
	
		cout << "\n----------------------------------------------------------------------------------" << endl << endl;

		cout << "\nLab Scientist:" << endl
			<< "     Your test results have come back inconclusive." << endl
			<< "     I ran: " << endl
			<< "          Complete Blood Count (CBC)" << endl
			<< "          Comprehensive Metabolic Panel (CMP)" << endl;

		cout << "You have: " << endl
			<< "     Increased White Blood Cell Count" << endl
			<< "     Increased Prolonged Clotting Time" << endl << endl;

		cout << "What do you have?" << endl
			<< "     1. N. Meningitis" << endl
			<< "     2. Influenza" << endl
			<< "     3. Strep Throat" << endl
			<< "     4. Run more tests" << endl
			<< "Choice: ";
		choice = checkIntVal();
		cout << "\n----------------------------------------------------------------------------------" << endl << endl;

	if (choice == 1)
	{
		cout << "You think you have N. Meningitis? This is the correct diagnosis" << endl << endl;

		cout << "would you like to learn about N. Meningitis?" << endl
			<< "     1. Yes" << endl
			<< "     2. No" << endl
			<< "Choice: ";
		choice = checkIntVal();
		cout << "\n----------------------------------------------------------------------------------" << endl << endl;

		if (choice == 1)
		{
			cout << "Caused by the type of bacteria called Neisseria meningitidis." << endl
				<< "Meningococcal disease is a contagious infection spread by close contact" << endl
				<< "with an infected  person, such as living together or kissing. Quick medical attention" << endl
				<< "is extremely important if meningococcal disease is suspected." << endl
				<< "          Source: http://wwwnc.cdc.gov/travel/diseases/meningococcal-disease" << endl << endl;

			cout << "The treatment is through taking an antibiotic called cephalosporin" << endl << endl;

			cout << "Thank you for playing" << endl  
				<< "Please stop by the pharmacy and grab some cephalosporin to treat your disease" << endl << endl;
		}
		else
			cout << "Thank you for playing" << endl
			<< "Please stop by the pharmacy and grab some cephalosporin to treat your disease" << endl << endl;
		return false;
	}
	else if(choice == 2 || choice == 3 || choice == 4)
	{
		if (choice == 2 || choice == 3)
		{
			cout << "\nLab Scientist:" << endl
				<< "     I do not feel comfortable diagnosing you with that with this information." << endl
				<< "     We need to run more tests" << endl << endl;
		}
		else if (choice == 4)
		{
			cout << "Lab Scientist:" << endl
				<< "     I agrre, we should run more tests." << endl << endl;
		}
	}

	


	//Second Pannel of tests
	cout << "Lab Scientist:" << endl
		<< "     Your second batch of test results have come back." << endl
		<< "          Your Urine has alot of bacteria." << endl
		<< "          Your WBC and protein blood cultures came back positive" << endl << endl;

	cout << "What do you have?" << endl
		<< "     1. Strep Throat" << endl
		<< "     2. Influenza" << endl
		<< "     3. N. Meningitis" << endl
		<< "     4. Run more tests" << endl
		<< "Choice: ";
	choice = checkIntVal();
	cout << "\n----------------------------------------------------------------------------------" << endl << endl;

	if (choice == 3)
	{
		cout << "You think you have N. Meningitis? This is the correct diagnosis" << endl << endl;

		cout << "would you like to learn about N. Meningitis?" << endl
			<< "     1. Yes" << endl
			<< "     2. No" << endl
			<< "Choice: ";
		choice = checkIntVal();
		cout << "\n----------------------------------------------------------------------------------" << endl << endl;

		if (choice == 1)
		{
			cout << "Caused by the type of bacteria called Neisseria meningitidis." << endl
				<< "Meningococcal disease is a contagious infection spread by close contact" << endl
				<< "with an infected  person, such as living together or kissing. Quick medical attention" << endl
				<< "is extremely important if meningococcal disease is suspected." << endl
				<< "          Source: http://wwwnc.cdc.gov/travel/diseases/meningococcal-disease" << endl << endl;

			cout << "The treatment is through taking an antibiotic called cephalosporin" << endl << endl;

			cout << "Thank you for playing" << endl
				<< "Please stop by the pharmacy and grab some cephalosporin to treat your disease" << endl << endl;
		}
		else
			cout << "Thank you for playing" << endl
			<< "Please stop by the pharmacy and grab some cephalosporin to treat your disease" << endl << endl;
		return false;
	}
	else if (choice == 1 || choice == 2 || choice == 4)
	{
		if (choice == 1 || choice == 2)
		{
			cout << "\nLab Scientist:" << endl
				<< "     I still do not feel comfortable diagnosing you yet." << endl
				<< "     We need to run more tests" << endl << endl;
		}
		else if (choice == 4)
		{
			cout << "Lab Scientist:" << endl
				<< "     I agrre, we should run more tests." << endl << endl;
		}
	}



	//Third Pannel of tests
	cout << "Lab Scientist:" << endl
		<< "     Your last batch of test results have come back." << endl
		<< "          Your Spinal tap is positive and shows gram negative diplococci." << endl
		<< "          Your Blood cultures is also positive and shows gram negative diplococci" << endl 
		<< "          Your Throat culture is negative" << endl
		<< endl;

	cout << "What do you have?" << endl
		<< "     1. Strep Throat" << endl
		<< "     2. N. Meningitis" << endl
		<< "     3. Influenza" << endl
		<< "Choice: ";
	choice = checkIntVal();
	cout << "\n----------------------------------------------------------------------------------" << endl << endl;

	if (choice == 2)
	{
		cout << "You think you have N. Meningitis? This is the correct diagnosis" << endl << endl;

		cout << "would you like to learn about N. Meningitis?" << endl
			<< "     1. Yes" << endl
			<< "     2. No" << endl
			<< "Choice: ";
		choice = checkIntVal();
		cout << "\n----------------------------------------------------------------------------------" << endl << endl;

		if (choice == 1)
		{
			cout << "Caused by the type of bacteria called Neisseria meningitidis." << endl
				<< "Meningococcal disease is a contagious infection spread by close contact" << endl
				<< "with an infected  person, such as living together or kissing. Quick medical attention" << endl
				<< "is extremely important if meningococcal disease is suspected." << endl
				<< "          Source: http://wwwnc.cdc.gov/travel/diseases/meningococcal-disease" << endl << endl;

			cout << "The treatment is through taking an antibiotic called cephalosporin" << endl << endl;

			cout << "Thank you for playing" << endl
				<< "Please stop by the pharmacy and grab some cephalosporin to treat your disease" << endl << endl;
		}
		else
			cout << "Thank you for playing" << endl
			<< "Please stop by the pharmacy and grab some cephalosporin to treat your disease" << endl << endl;
		return false;
	}
	else if (choice == 1 || choice == 3)
	{
		cout << "\nLab Scientist:" << endl
			<< "     This is not the correct diagnosis. You actually have N. Meningitis" << endl << endl;
		
		cout << "would you like to learn about N. Meningitis?" << endl
			<< "     1. Yes" << endl
			<< "     2. No" << endl
			<< "Choice: ";
		choice = checkIntVal();
		cout << "\n----------------------------------------------------------------------------------" << endl << endl;

			if (choice == 1)
			{
				cout << "Caused by the type of bacteria called Neisseria meningitidis." << endl
					<< "Meningococcal disease is a contagious infection spread by close contact" << endl
					<< "with an infected  person, such as living together or kissing. Quick medical attention" << endl
					<< "is extremely important if meningococcal disease is suspected." << endl
					<< "          Source: http://wwwnc.cdc.gov/travel/diseases/meningococcal-disease" << endl << endl;

				cout << "The treatment is through taking an antibiotic called cephalosporin" << endl << endl;

				cout << "Thank you for playing" << endl
					<< "Please stop by the pharmacy and grab some cephalosporin to treat your disease" << endl << endl;
			}
			else
				cout << "Thank you for playing" << endl
				<< "Please stop by the pharmacy and grab some cephalosporin to treat your disease" << endl << endl;
			return false;
	}
}

/****************************************************************************
** Function: Hospital *loadZone(string zone)
** Description: Create room objects
** Parameters: String with zone name
** Pre-Conditions: None
** Post-Conditions: None
** Return: pointer to Hospital object
*****************************************************************************/

Hospital *loadZone(string zone)
{
	Hospital *hospital; //Hospital pointer object

	if (zone.compare("ER") == 0) //Emergency Room
	{
		hospital = new ER("ER");
		return hospital;
	}
	else if (zone.compare("IP") == 0) //In Patient
	{
		hospital = new IP("IP");
		return hospital;
	}
	else if (zone.compare("UpperHall") == 0) //Upper Hall
	{
		hospital = new UpperHall("UpperHall");
		return hospital;
	}
	else if (zone.compare("LowerHall") == 0) //Lower Hall
	{
		hospital = new LowerHall("LowerHall");
		return hospital;
	}
	else if (zone.compare("FrontDoor") == 0) //Front Door
	{
		hospital = new FrontDoor("FrontDoor");
		return hospital;
	}
	else if (zone.compare("Lab") == 0) //Lab
	{
		hospital = new Lab("Lab");
		return hospital;
	}
	else if (zone.compare("Library") == 0) //Library
	{
		hospital = new Library("Library");
		return hospital;
	}
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
			cout << "\nPlease enter a valid integer: "; //String not valid
	}
}