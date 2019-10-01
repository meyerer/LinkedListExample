/****************************************************************************************
**Author: Eric Meyer
**Date: 11 August 2019
**Description:  This is the implementation of the Quest4 Class.  Resources if any are listed
* below.
*****************************************************************************************/

#include "Quest4.hpp"
#include "Space.hpp"
#include <sstream>
#include <iostream>

/*******************************************************************
* The constructor sets unused Space pointers to null and intializes
* a string to read in user input.
*******************************************************************/

Quest4::Quest4()
{
	top = NULL;
	bottom = NULL;
	isEnd = false;
	choice = "";
	//tries = 3;


}


/*****************************************************************
* This function prompts the user for input while valid input is
* not present and lives > 0.  Additionally it receieves lives from
* the Troll class so it can decrement lives based on incorrect answers.
* Finally it returns the lives so Trolls can pass lives to the
* next question.
*******************************************************************/
int Quest4::askQuestion(int lives)
{
	int* ptrLives = &lives;
	do
	{
		std::cout << std::endl;
		std::cout << "Lives: " << lives << std::endl;
		std::cout << std::endl;
		std::cout << "Question 4:" << std::endl;
		std::cout << "A ___________ function is a function that calls itself." << std::endl;
		std::cout << "Please enter the number corresponding with your answer!" << std::endl;
		std::cout << "1. Recursive" << std::endl;
		std::cout << "2. Member" << std::endl;
		std::cout << "3. Constant" << std::endl;
		std::cout << "4. Virtual" << std::endl;
		std::cout << "Choice: ";
		std::cin >> choice;
		std::cout << std::endl;
	} while (!validateAnswer(ptrLives) && lives > 0);

	return lives;
}

bool Quest4::validateAnswer(int* ptrLives)
{
	//valid choice flag
	bool validChoice = false;
	//Integer variable to hold the converted string choice to integer
	int convertedInt;
	//accumulation variable for whether string values are integers
	int isInt = 0;

	//Step through values in string to determine whether values are integers
	//uses isdigit() function from cctype
	for (int i = 0; i < choice.size(); i++)
	{
		if (isdigit(choice[i]))
		{
			isInt++;
		}
	}

	//If choice is all ints
	if (isInt == choice.size())
	{
		//use stringstream object to convert choice to integer
		std::stringstream str_stream_object(choice);
		str_stream_object >> convertedInt;

		choice = "";


		//checks range
		if (convertedInt < 1 || convertedInt > 4)
		{
			std::cout << "Please enter a valid answer!" << std::endl;
		}
		//if add to head
		else if (convertedInt == 1)
		{
			validChoice = true;
		}
		else
		{
			std::cout << std::endl;
			std::cout << "WRONG!" << std::endl;
			(*ptrLives)--;
		}
	}
	//if input isn't valid
	else
	{
		std::cout << std::endl;
		std::cout << "Please enter a valid integer!" << std::endl;
	}

	return validChoice;
}