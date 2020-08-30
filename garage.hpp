/*****************************************************************************
Project: Final Project: Theme-The Office
Author: Toni Lousteau
Date: 12/7/2019
Description: Header file for the garage class which is a child of the Space Class,
It has a default constructor and a constructor. It has
member functions spaceAction and moveSpace, which are overwritten functions.
*******************************************************************************/

#ifndef GARAGE_HPP
#define GARAGE_HPP

#include "space.hpp"

class Garage:public Space
{

	public:
		Garage();
		Garage(Space* to, Space* bo, Space* le, Space* ri);
		virtual int spaceAction() override;
		virtual int moveSpace() override;
};

#endif //GARAGE_HPP
