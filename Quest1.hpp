/****************************************************************************************
**Author: Eric Meyer
**Date: 11 August 2019
**Description:  This is the interface for the Quest1 Class. The purpose of this class
* is to provide definitions for the pure virtual functions askQuestion and validateAnswer.
* Quest1 is a child class of Space.  Additionally, the constructor sets Space pointers to
* null if they aren't going to be used.
*****************************************************************************************/

#ifndef QUEST1_HPP
#define QUEST1_HPP
#include <iostream>
#include <string>
#include "Space.hpp"

class Quest1 : public Space
{
	public:
		Quest1();
		virtual int askQuestion(int);
		virtual bool validateAnswer(int*);
};

#endif // !QUEST1_HPP

