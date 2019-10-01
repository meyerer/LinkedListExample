/****************************************************************************************
**Author: Eric Meyer
**Date: 11 August 2019
**Description:  This is the main function for the escapeFromCS162 game.  It instantiates
* a object, prompts the user for input, then continues until the user doesn't want to play
* anymore.
*****************************************************************************************/

#include "Game.hpp"
#include <iostream>
#include <ctime>


int main()
{

	//seed random number generator
	srand(time(NULL));

	//Instantiates the object
	Game escapeFromCS162;

	//prompts user for input
	escapeFromCS162.readMainMenu();

	//Plays the game and prompts user again until 
	//The user wants to quit
	while (escapeFromCS162.getMenuSelection() != 2)
	{
		escapeFromCS162.playGame();

		escapeFromCS162.readMainMenu();
	}
}