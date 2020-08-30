/*****************************************************************************
Project: Final Project: Theme-The Office
Author: Toni Lousteau
Date: 12/7/2019
Description: Header file for the cube class which is a child of the Space Class
*******************************************************************************/

#ifndef CUBE_HPP
#define CUBE_HPP

#include "space.hpp"
#include <iostream>
#include <string>

class Cube:public Space
{

	public:
		Cube();
		Cube(Space* to, Space* bo, Space* le, Space* ri);
		std::string givePen();
		virtual int spaceAction() override;
		virtual int moveSpace() override;
};

#endif //CUBE_HPP
