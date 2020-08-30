/*****************************************************************************
Project: Final Project: Theme-Office Spaces
Author: Toni Lousteau
Date: 12/7/2019
Description: Header file for the Game Class
*******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "ceo.hpp"
#include "conf.hpp"
#include "cube.hpp"
#include "garage.hpp"
#include "hr.hpp"
#include "lunch.hpp"
#include "worker.hpp"

#include <iostream>
#include <string>

class Game
{
	protected:
		Garage *park; //parking garage
		Cube *cubicle; //cubicle or desk
		CeoOffice *cOffice; //ceo office
		Conf *conference; //conference room
		Hr *hR; //HR
		Lunch *lunch; //lunch
		Worker player; //game player

	public:
		//Default Constructor
		Game(); //default constructor
		~Game(); //destructor
		int start(); //start game
		int sEMenu(); //start end menu
		bool checkStatus(); //boolean game over true/false
		int move(); //first move
		int nextSpace(); //go to next space 
};

#endif //GAME_HPP
