/*****************************************************************************
Project: Final Project: Theme-The Office
Author: Toni Lousteau
Date: 12/7/2019
Description: Header file for the Hr class, which is a child
of the Space Class. It has a default constructor and a constructor. It has
member functions spaceAction and moveSpace, which are overwritten functions.
It has a member function giveCheck(), which returns a string "check" and newItem,
which returns a string "badge"
*******************************************************************************/

#ifndef HR_HPP
#define HR_HPP

#include "space.hpp"

class Hr:public Space
{

	public:
		Hr(); //default constructor
		Hr(Space* to, Space* bo, Space* le, Space* ri); //constructor
		virtual int spaceAction() override; //random event
		virtual int moveSpace() override; //move
		std::string newItem(); //return "badge"
		std::string giveCheck(); //return "check"
};

#endif //HR_HPP
