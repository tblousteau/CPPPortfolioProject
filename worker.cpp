/*****************************************************************************
Project: Final Project: Theme-The Office
Author: Toni Lousteau
Date: 12/7/2019
Description: Implementation file for the worker class, which has data members name,
points, space, Item, and pocket, it has a default constructor and member functions
void addPoints(int bPoints); void losePoints(int bPoints);
std::string getName(), void setName(std::string user), int getPoints();
void setSpace(int spaceNum), int getSpace(), Item getBadge(), Item getPen();
Item getCheck(), bool hasItems();
*******************************************************************************/

#include "worker.hpp"

using std::cout;
using std::endl;
/******************************************************************************
Worker::Worker() default constructor
******************************************************************************/
Worker::Worker()
{
	name = "";
	points = 10;

}
/******************************************************************************
void Worker::setName(std::string user) //set user name
******************************************************************************/
void Worker::setName(std::string user)
{
	name = user;

}
/******************************************************************************
void Worker::addPoints(int bPoints) add points to player's points
******************************************************************************/

void Worker::addPoints(int bPoints)
{
	points = points + bPoints;
}
/******************************************************************************
void Worker::losePoints(int bPoints) subtract points
******************************************************************************/

void Worker::losePoints(int bPoints)
{
	points = points - bPoints;
}
/******************************************************************************
std::string Worker::getName() return name
******************************************************************************/

std::string Worker::getName()
{
	return name;
}
/******************************************************************************
int Worker::getPoints() return points
******************************************************************************/

int Worker::getPoints()
{
	return points;
}
/******************************************************************************
void Worker::setSpace(int space) sets user space assignment
*******************************************************************************/
void Worker::setSpace(int spaceNum)
{
	space = spaceNum;
}
/******************************************************************************
int Worker::getSpace() returns user space
*******************************************************************************/
int Worker::getSpace()
{
	return space;
}
/******************************************************************************
item Worker::getBadge() return pocket[0] "badge"
*******************************************************************************/
Worker::Item Worker::getBadge()
{
	pocket[0].addItem("badge");
	return pocket[0];
}
/******************************************************************************
item Worker::getPen() returns pocket[1] "pen"
*******************************************************************************/
Worker::Item Worker::getPen()
{
	pocket[1].addItem("pen");
	return pocket[1];
}
/******************************************************************************
item Worker::getBadge() returns pocket[2] "check"
*******************************************************************************/
Worker::Item Worker::getCheck()
{
	pocket[2].addItem("check");
	return pocket[2];
}
/******************************************************************************
bool Worker::hasItems() if player has pen and badge return true else return false
*******************************************************************************/
bool Worker::hasItems()
{
	if (pocket[0].numOfItems > 0 && pocket[1].numOfItems > 0)
	{
		return true;
	}
	return false;
}
