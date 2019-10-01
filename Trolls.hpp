/****************************************************************************************
**Author: Eric Meyer
**Date: 11 August 2019
**Description:  This is the interface for the Trolls class.  It creates the board 
* (essentially links the list of questions). Iterates through the questions.  Prints where
* the user is in the game. Generates a random key if user answers all the questions correctly.
* Displays the final results and unallocates memory.  The class has Space pointers for
* the head of the linked list, the tail of the linked list, and a pointer to create a new
* question.  Trolls also tracks the lives the user has.  Additionally, there is a character
* array to hold a randomly generated key that is then placed in a stack.
*****************************************************************************************/


#ifndef TROLLS_HPP
#define TROLLS_HPP
#include "Space.hpp"
#include <iostream>
#include <stack>
#include <string>

class Trolls
{
	private:
		Space* n;
		Space* head;
		Space* tail;
		int lives;
		std::stack<char> randKey;
		char key[15];

	public:
		Trolls();
		void createBoard();
		void askQuestions();
		void printBoard(int);
		void generateKey();
		void displayResults();
		void unallocMem();
};

#endif


