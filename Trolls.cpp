/****************************************************************************************
**Author: Eric Meyer
**Date: 11 August 2019
**Description:  This is the implementation of the Trolls class.  Any resources used are
* listed below.
*****************************************************************************************/



#include "Trolls.hpp"
#include "Space.hpp"
#include "Quest1.hpp"
#include "Quest2.hpp"
#include "Quest3.hpp"
#include "Quest4.hpp"
#include "Quest5.hpp"
#include "Quest6.hpp"
#include <sstream>
#include <iostream>


//Constructor to initialize lives to 3
Trolls::Trolls()
{
	lives = 3;
}

/******************************************************************************
* This function creates the linked list. I treated it as I was adding 
* a node to the tail of a list, as a resouce I used my code from Lab 6
* LinkedList.cpp. The funciton loops through the six questions and links
* them to my specifications.  I wanted to have a non-linear game board
* and this was the best way to acheive this. No return/No parameters
******************************************************************************/

void Trolls::createBoard()
{
	for (int i = 0; i < 6; i++)
	{
		//first question
		if (i == 0)
		{
			n = new Quest1;
			head = n;
			tail = n;
		}
		//Second question
		else if (i == 1)
		{
			n = new Quest2;
			n->setLeft(tail);
			tail->setRight(n);
			tail = n;
		}
		//Third question
		else if (i == 2)
		{
			n = new Quest3;
			n->setBottom(tail);
			tail->setTop(n);
			tail = n;
		}
		//Fourth question
		else if (i == 3)
		{
			n = new Quest4;
			n->setLeft(tail);
			tail->setRight(n);
			tail = n;
		}
		//Fifth question
		else if (i == 4)
		{
			n = new Quest5;
			n->setLeft(tail);
			tail->setRight(n);
			tail = n;
		}
		//Sixth question
		else
		{
			n = new Quest6;
			n->setTop(tail);
			tail->setBottom(n);
			tail = n;
		}
	}
}

/********************************************************************
* This function utilizes a while loop to loop through the list
* asking each question.  The loop will exit at the 6th question or 
* when there are no lives left.  I took this as a printing function
* and used the functions I created in Lab6 as a reference.
*********************************************************************/

void Trolls::askQuestions()
{
	int question = 0;
	Space* temp = head;

	//Continues until last question or no lives left
	while (question != 6 && lives > 0)
	{
		if (question == 0)
		{
			//lets user know where they are
			printBoard(question);
			//asks the question for that node
			lives = temp->askQuestion(lives);
			//moves on
			temp = temp->getRight();
			question++;
		}
		else if (question == 1)
		{
			printBoard(question);
			lives = temp->askQuestion(lives);
			temp = temp->getTop();
			question++;
		}
		else if (question == 2)
		{
			printBoard(question);
			lives = temp->askQuestion(lives);
			temp = temp->getRight();
			question++;
		}
		else if (question == 3)
		{
			printBoard(question);
			lives = temp->askQuestion(lives);
			temp = temp->getRight();
			question++;
		}
		else if (question == 4)
		{
			printBoard(question);
			lives = temp->askQuestion(lives);
			temp = temp->getBottom();
			question++;
		}
		else
		{
			printBoard(question);
			lives = temp->askQuestion(lives);
			question++;
		}
	}

	//If the user made it through with lives
	//Create key and display final message
	if (lives > 0)
	{
		generateKey();
		displayResults();
	}
	//user lost
	else
	{
		std::cout << std::endl;
		std::cout << "You ran out of attempts! You will stay in CS162 FOREVER! HAHAHAHAHAHAHA" << std::endl;
		std::cout << "-The Trolls" << std::endl;
	}

	//sets lives back to three if user wants to play again
	lives = 3;
}

/*********************************************************************************
* This user prints the board for each question.  I though it would be better to 
* visualize where the user is in the game.  It recieves the number of question as
* a parameter.
*********************************************************************************/
void Trolls::printBoard(int q)
{
	if (q == 0)
	{	
		std::cout << std::endl;
		std::cout << "**************************************************" << std::endl;
		std::cout << "*                  You are Here = #              *" << std::endl;
		std::cout << "*                                                *" << std::endl;
		std::cout << "*                                  ___________   *" << std::endl;
		std::cout << "*                                 |T3 |T4 |T5 |  *" << std::endl;
		std::cout << "*                                 |   |   |   |  *" << std::endl;
		std::cout << "*                              ___|___|___|___|  *" << std::endl;
		std::cout << "*                             |T1 |T2 |   |T6 |  *" << std::endl;
		std::cout << "*                      Start: | # |   |   |   |  *" << std::endl;
		std::cout << "*                             |___|___|   |___|  *" << std::endl;
		std::cout << "*                                        Finish! *" << std::endl;
		std::cout << "**************************************************" << std::endl;
		std::cout << std::endl;
	}
	else if (q == 1)
	{
		std::cout << std::endl;
		std::cout << "**************************************************" << std::endl;
		std::cout << "*                  You are Here = #              *" << std::endl;
		std::cout << "*                                                *" << std::endl;
		std::cout << "*                                  ___________   *" << std::endl;
		std::cout << "*                                 |T3 |T4 |T5 |  *" << std::endl;
		std::cout << "*                                 |   |   |   |  *" << std::endl;
		std::cout << "*                              ___|___|___|___|  *" << std::endl;
		std::cout << "*                             |T1 |T2 |   |T6 |  *" << std::endl;
		std::cout << "*                      Start: |   | # |   |   |  *" << std::endl;
		std::cout << "*                             |___|___|   |___|  *" << std::endl;
		std::cout << "*                                        Finish! *" << std::endl;
		std::cout << "**************************************************" << std::endl;
		std::cout << std::endl;
	}
	else if (q == 2)
	{
		std::cout << std::endl;
		std::cout << "**************************************************" << std::endl;
		std::cout << "*                  You are Here = #              *" << std::endl;
		std::cout << "*                                                *" << std::endl;
		std::cout << "*                                  ___________   *" << std::endl;
		std::cout << "*                                 |T3 |T4 |T5 |  *" << std::endl;
		std::cout << "*                                 | # |   |   |  *" << std::endl;
		std::cout << "*                              ___|___|___|___|  *" << std::endl;
		std::cout << "*                             |T1 |T2 |   |T6 |  *" << std::endl;
		std::cout << "*                      Start: |   |   |   |   |  *" << std::endl;
		std::cout << "*                             |___|___|   |___|  *" << std::endl;
		std::cout << "*                                        Finish! *" << std::endl;
		std::cout << "**************************************************" << std::endl;
		std::cout << std::endl;
	}
	else if (q == 3)
	{
		std::cout << std::endl;
		std::cout << "**************************************************" << std::endl;
		std::cout << "*                  You are Here = #              *" << std::endl;
		std::cout << "*                                                *" << std::endl;
		std::cout << "*                                  ___________   *" << std::endl;
		std::cout << "*                                 |T3 |T4 |T5 |  *" << std::endl;
		std::cout << "*                                 |   | # |   |  *" << std::endl;
		std::cout << "*                              ___|___|___|___|  *" << std::endl;
		std::cout << "*                             |T1 |T2 |   |T6 |  *" << std::endl;
		std::cout << "*                      Start: |   |   |   |   |  *" << std::endl;
		std::cout << "*                             |___|___|   |___|  *" << std::endl;
		std::cout << "*                                        Finish! *" << std::endl;
		std::cout << "**************************************************" << std::endl;
		std::cout << std::endl;
	}
	else if (q == 4)
	{
		std::cout << std::endl;
		std::cout << "**************************************************" << std::endl;
		std::cout << "*                  You are Here = #              *" << std::endl;
		std::cout << "*                                                *" << std::endl;
		std::cout << "*                                  ___________   *" << std::endl;
		std::cout << "*                                 |T3 |T4 |T5 |  *" << std::endl;
		std::cout << "*                                 |   |   | # |  *" << std::endl;
		std::cout << "*                              ___|___|___|___|  *" << std::endl;
		std::cout << "*                             |T1 |T2 |   |T6 |  *" << std::endl;
		std::cout << "*                      Start: |   |   |   |   |  *" << std::endl;
		std::cout << "*                             |___|___|   |___|  *" << std::endl;
		std::cout << "*                                        Finish! *" << std::endl;
		std::cout << "**************************************************" << std::endl;
		std::cout << std::endl;
	}
	else if (q == 5)
	{
		std::cout << std::endl;
		std::cout << "**************************************************" << std::endl;
		std::cout << "*                  You are Here = #              *" << std::endl;
		std::cout << "*                                                *" << std::endl;
		std::cout << "*                                  ___________   *" << std::endl;
		std::cout << "*                                 |T3 |T4 |T5 |  *" << std::endl;
		std::cout << "*                                 |   |   |   |  *" << std::endl;
		std::cout << "*                              ___|___|___|___|  *" << std::endl;
		std::cout << "*                             |T1 |T2 |   |T6 |  *" << std::endl;
		std::cout << "*                      Start: |   |   |   | # |  *" << std::endl;
		std::cout << "*                             |___|___|   |___|  *" << std::endl;
		std::cout << "*                                        Finish! *" << std::endl;
		std::cout << "**************************************************" << std::endl;
		std::cout << std::endl;
	}

}
/**************************************************************************************************
* This function generates a random 15 character key to serve as a "encrypted" message
* from the trolls. I used the below reference to help me implement this functionality.
* https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
* No parameters/No return
***************************************************************************************************/

void Trolls::generateKey()
{
	//creates a character array with all the possible values
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	//generates 15 random characters from alphanum and places them in key
	for (int i = 0; i < 15; i++)
	{
		key[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	//adds each index of key to randKey stack
	for (int i = 0; i < 15; i++)
	{
		randKey.push(key[i]);
	}
}

/*******************************************************************************************
*This function outputs a final message if the user wins.  No parameters/No return value.
* I took the functionality of printing what was in the stack from Lab 7 palidrome function.
********************************************************************************************/

void Trolls::displayResults()
{
	std::cout << std::endl;
	std::cout << "Congrats! You have passed the Programming Trolls' test.  They have provided you with an encrypted key!" << std::endl;
	std::cout << "Key:";

	//While there are still values
	//Print the top value and remove the top value
	while (!randKey.empty())
	{
		std::cout << randKey.top();
		randKey.pop();
	}

	std::cout << std::endl;
	std::cout << "Decrypting...." << std::endl;

	std::cout << "Decrypted Message: Good luck in CS261!" << std::endl;
	std::cout << std::endl;
}

/**************************************************************************
* This function loops through and deletes the allocated memory. I also
* took this from lab6. No parameter/No return.
***************************************************************************/
void Trolls::unallocMem()
{
	int question = 0;
	Space* temp = head;
	Space* next;

	while (question != 6)
	{
		if (question == 0)
		{
			next = temp->getRight();
			delete temp;
			temp = next;
			question++;
		}
		else if (question == 1)
		{
			next = temp->getTop();
			delete temp;
			temp = next;
			question++;
		}
		else if (question == 2)
		{
			next = temp->getRight();
			delete temp;
			temp = next;
			question++;

		}
		else if (question == 3)
		{
			next = temp->getRight();
			delete temp;
			temp = next;
			question++;
		}
		else if (question == 4)
		{
			next = temp->getBottom();
			delete temp;
			temp = next;
			question++;
		}
		else
		{
			delete temp;
			question++;
		}
	}
}