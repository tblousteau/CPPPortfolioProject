/*****************************************************************************
Project: Final Project: Theme-The Office
Author: Toni Lousteau
Date: 12/7/2019
Description: Header file for the CeoOffice class, which is a child
of the Space Class. It has a default constructor and a constructor. It has
member functions spaceAction and moveSpace, which are overriden functions.
It has a member function giveCheck(), which returns a string "check".
*******************************************************************************/

#ifndef CEO_HPP
#define CEO_HPP

#include "space.hpp"
#include <iostream>
#include <cstdlib>

class CeoOffice:public Space
{

	public:
		CeoOffice(); //default constructor
		CeoOffice(Space* to, Space* bo, Space* le, Space* ri); //constructor
		virtual int spaceAction() override; //spaceAction returns a random event
		virtual int moveSpace() override; // move to a connecting space
		std::string giveCheck();//return "check"
};

#endif //CEO_HPP
