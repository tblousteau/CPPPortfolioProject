/*****************************************************************************
Project: Final Project: Theme-The Office
Author: Toni Lousteau
Date: 12/7/2019
Description: Header file for the worker class, which has data members name,
points, space, Item, and pocket, it has a default constructor and member functions
void addPoints(int bPoints); void losePoints(int bPoints);
std::string getName(), void setName(std::string user), int getPoints();
void setSpace(int spaceNum), int getSpace(), Item getBadge(), Item getPen();
Item getCheck(), bool hasItems();
*******************************************************************************/

#include <iostream>
#include <string>

#ifndef WORKER_HPP
#define WORKER_HPP

class Worker
{
	protected:
		std::string name; //name
		int points; //number of points
		int space; //space assignment
		struct Item //item from game
		{
			std::string itemName;
			int numOfItems;
			void addItem(std::string itemNme)
			{
				itemName = itemNme;
				numOfItems += 1;
			}
		};
		Item pocket[3] = {{"", 1}}; //container of items

	public:
		//Default Contructor
		Worker();

		void addPoints(int bPoints); //adds to worker points
		void losePoints(int bPoints); //subtracts from worker points
		std::string getName(); //returns name
		void setName(std::string user); //sets name
		int getPoints(); //returns points
		void setSpace(int spaceNum); //sets space
		int getSpace(); //returns space assignment
		Item getBadge(); //gets pocket[0]
		Item getPen(); //gets pocket[1]
		Item getCheck(); //gets pocket[2]
		bool hasItems(); //has first two items or not
	};

#endif //WORKER_HPP
