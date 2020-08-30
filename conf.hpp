/*****************************************************************************
Project: Final Project: Theme-The Office
Author: Toni Lousteau
Date: 12/7/2019
Description: Header file for the conf class which is a child of the Space Class
It has a default constructor and a constructor. It has
member functions spaceAction and moveSpace, which are overwritten functions.
It has a member function givePen(), which returns a string "pen".
*******************************************************************************/

#ifndef CONF_HPP
#define CONF_HPP

#include "space.hpp"

class Conf:public Space
{

	public:
		Conf(); //default constructor
		Conf(Space* to, Space* bo, Space* le, Space* ri);//constructor
		virtual int spaceAction() override; //random event
		virtual int moveSpace() override; //move to connecting space
		std::string givePen(); //return pen
};

#endif //CONF_HPP
