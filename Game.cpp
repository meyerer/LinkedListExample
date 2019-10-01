/***********************************************************************************
**Author: Eric Meyer
**Date: 11 August 2019
**Description:  This is the implementation of the Game class. Resources used are 
* listed below.
***********************************************************************************/

#include "Game.hpp"
#include <sstream>
#include <iostream>


/****************************************************************************
* This function is a constructor to initialize the string variable that holds
* user input.
*****************************************************************************/
Game::Game()
{
	menuChoice = "";
}

/******************************************************************************
* This function prompts the user for input while proper input is not available.
* No parameter and no return value.
******************************************************************************/

void Game::readMainMenu()
{

	do {
		std::cout << "************************************************************" << std::endl;
		std::cout << "*                                                          *" << std::endl;
		std::cout << "*                                                          *" << std::endl;
		std::cout << "*     *************************     .:|:|:|:|:.            *" << std::endl;
		std::cout << "*     *     CS 261 this way   *    :.:|:|:|:|:.:           *" << std::endl;
		std::cout << "*     *       --------->      *   :=.' -   - '.=:          *" << std::endl;
		std::cout << "*     *      -The TROLLS      *   '=(' 9   9 ')='          *" << std::endl;
		std::cout << "*     *************************      (  (_)  )             *" << std::endl;
		std::cout << "*                |   |               /`-vvv-'\\             *" << std::endl;
		std::cout << "*                |   |              /         \\            *" << std::endl;
		std::cout << "*                |   |             / /|,,,,,|\\ \\           *" << std::endl;
		std::cout << "*                |   |            /_/   /^\\   \\ \\          *" << std::endl;
		std::cout << "*                |   |            WW(  (   )  )WW         *" << std::endl;
		std::cout << "*                |   |            ___\\,,\\ /,,,/__          *" << std::endl;
		std::cout << "*                |   |           (_______Y_______)         *" << std::endl;
		std::cout << "************************************************************" << std::endl;
		std::cout << std::endl;
		std::cout << "Welcome to Escape from CS162!" << std::endl;
		std::cout << std::endl;
		std::cout << "The Programming Trolls have 6 questions that you MUST answer correctly";
		std::cout << " in order to escape from CS162." << std::endl;
		std::cout << std::endl;
		std::cout << "The questions will range from topics covered in CS162." << std::endl;
		std::cout << std::endl;
		std::cout << "If you provide 3 incorrect answers you will remain in CS162 forever!" << std::endl;
		std::cout << std::endl;
		std::cout << "Enter at your own risk.  Do you wish to proceed?" << std::endl;
		std::cout << "1) Yes" << std::endl;
		std::cout << "2) No" << std::endl;
		std::cout << "Choice:";
		std::cin >> menuChoice;
		std::cout << std::endl;
	} while (!validatePlayChoice());

}



/********************************************************************************
* This function converts the string input variables to integers using the sstream
* library. It checks if the input is all ints if so it calls the correct function.
* This function returns a bool so the read functions know when to exit the do-while
* loops.
*********************************************************************************/

bool Game::validatePlayChoice()
{

	//valid choice flag
	bool validChoice = false;
	//Integer variable to hold the converted string choice to integer
	int convertedInt;
	//accumulation variable for whether string values are integers
	int isInt = 0;

	//Step through values in string to determine whether values are integers
	//uses isdigit() function from cctype
	for (int i = 0; i < menuChoice.size(); i++)
	{
		if (isdigit(menuChoice[i]))
		{
			isInt++;
		}
	}

	//If choice is all ints
	if (isInt == menuChoice.size())
	{
		//use stringstream object to convert choice to integer
		std::stringstream str_stream_object(menuChoice);
		str_stream_object >> convertedInt;

		menuChoice = "";


		//checks range
		if (convertedInt < 1 || convertedInt > 2)
		{
			std::cout << "Please enter a valid menu option!" << std::endl;
		}
		else
		{
			menuSelection = convertedInt;
			validChoice = true;
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

/*********************************************************************************
* This function combines the Troll functions to carry out the game.  No return
* value and no parameters.
*********************************************************************************/

void Game::playGame()
{
	troll.createBoard();

	troll.askQuestions();

	troll.unallocMem();
}


//Returns menuSelection for main.cpp
//This is what exits the while loop
int Game::getMenuSelection()
{
	return menuSelection;
}

