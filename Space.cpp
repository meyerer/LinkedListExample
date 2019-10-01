/***********************************************************************************
**Author: Eric Meyer
**Date: 11 August 2019
**Description:  This is the implementation for the Space class. If any resources
* are used they are listed below.
***********************************************************************************/

#include "Space.hpp"
#include <iostream>


//set function for top
//receives Space*
void Space::setTop(Space* t)
{
	this->top = t;
}


//get function for top
//returns Space*
Space* Space::getTop()
{
	return top;
}

//set function for bottom
//receives Space*
void Space::setBottom(Space* b)
{
	this->bottom = b;
}

//get function for bottom
//returns Space*
Space* Space::getBottom()
{
	return bottom;
}

//set function for right
//receives Space*
void Space::setRight(Space* r)
{
	this->right = r;
}

//get function for right
//returns Space*
Space* Space::getRight()
{
	return right;
}

//set function for left
//receives Space*
void Space::setLeft(Space* l)
{
	this->left = l;
}

//get function for left
//returns Space*
Space* Space::getLeft()
{
	return left;
}

//get function for the isEnd bool variable
//returns bool variable
bool Space::getIsEnd()
{
	return isEnd;
}


