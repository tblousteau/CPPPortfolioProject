/*****************************************************************************
Project: Final Project: Theme-The Office
Author: Toni Lousteau
Date: 12/7/2019
Description: Header file for the Space class, which contains four space pointers.
it contains member functions space action and
 move space, which are overwritten, it contains 3 int validation functions
 validateChoice for two choices, validateChoice3 for 3 choices, and validateChoice4
 for 4 choices, it has a virtual destructor, a default constructor and a constructor
*******************************************************************************/


#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Space
{
	protected:
		Space* top; //top pointer
		Space* right; //right pointer
		Space* bottom; //bottom pointer
		Space* left; //left pointer
		int assignment; //assingment of space

	public:
		Space(); //default constructor
		Space(Space* to, Space* bo, Space* le, Space* right); //constructor
		virtual ~Space(); //virtual constructor
		int validateChoice(std::string choice); //validate 1 or 2
		int validateChoice3(std::string choice);//validate 1,2, or 3
		int validateChoice4(std::string choice); //validate 1, 2, 3, or 4
		virtual int spaceAction(); //overwritten
		virtual int moveSpace();//overwritten
};

#endif
