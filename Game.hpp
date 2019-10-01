/***********************************************************************************
**Author: Eric Meyer
**Date: 11 August 2019
**Description:  This is the interface for the Game Class.  It contains a string to 
* read in user input, an integer to hold the validated input, additionally there 
* is a Troll object to access the Troll questions.
***********************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "Trolls.hpp"
#include <iostream>
#include <string>

class Game
{
	private:
		std::string menuChoice;
		int menuSelection;
		Trolls troll;

	public:
		Game();
		void readMainMenu();
		bool validatePlayChoice();
		void playGame();
		int getMenuSelection();

};

#endif // !GAME_HPP

