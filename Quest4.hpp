/****************************************************************************************
**Author: Eric Meyer
**Date: 11 August 2019
**Description:  This is the interface for the Quest4 Class. The purpose of this class
* is to provide definitions for the pure virtual functions askQuestion and validateAnswer.
* Quest4 is a child class of Space.  Additionally, the constructor sets Space pointers to
* null if they aren't going to be used.
*****************************************************************************************/

#ifndef QUEST4_HPP
#define QUEST4_HPP
#include <iostream>
#include <string>
#include "Space.hpp"

class Quest4 : public Space
{
public:
	Quest4();
	virtual int askQuestion(int);
	virtual bool validateAnswer(int*);
};

#endif // !QUEST4_HPP

