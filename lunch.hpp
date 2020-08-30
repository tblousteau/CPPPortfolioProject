/*****************************************************************************
Project: Final Project: Theme-The Office
Author: Toni Lousteau
Date: 12/7/2019
Description: Header file for the lunch class  which is a child of the
Space Class. It has a default constructor and a constructor. It has
member functions spaceAction and moveSpace, which are overwritten functions.
*******************************************************************************/

#ifndef LUNCH_HPP
#define LUNCH_HPP

#include "space.hpp"

class Lunch:public Space
{

	public:
		Lunch();//default constructor
		Lunch(Space* to, Space* bo, Space* le, Space* ri); //constructor
		virtual int spaceAction() override; //random event of the lunch
		virtual int moveSpace() override; //move or stay
};

#endif //LUNCH_HPP
