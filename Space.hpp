/***********************************************************************************
**Author: Eric Meyer
**Date: 11 August 2019
**Description:  This is the interface for the Space class.  It is the abstract base 
* class for the Question classes used by the Troll class.  It has 4 Space pointers
* used to link the questions together in a non-linear fashion.  It also has get/set 
* functions for those pointers.  Lastly, there are 2 pure, virtual functions defined
* for asking questions and validating answers.  These functions are defined in each
* of the subsequent Question classes.
***********************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <iostream>
#include <string>

class Space
{
	protected:
		Space* top;
		Space* bottom;
		Space* right;
		Space* left;
		int lives;
		std::string choice;
		bool isEnd;
	
	public:
		void setTop(Space*);
		Space* getTop();
		void setBottom(Space*);
		Space* getBottom();
		void setRight(Space*);
		Space* getRight();
		void setLeft(Space*);
		Space* getLeft();
		bool getIsEnd();
		virtual int askQuestion(int) = 0;
		virtual bool validateAnswer(int*) = 0;
};

#endif
