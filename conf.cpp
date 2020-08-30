/*****************************************************************************
Project: Final Project: Theme-The Office
Author: Toni Lousteau
Date: 12/7/2019
Description: implementation file for the conf class which is a child of the Space Class
It has a default constructor and a constructor. It has
member functions spaceAction and moveSpace, which are overwritten functions.
It has a member function givePen(), which returns a string "pen".

*******************************************************************************/

#include "conf.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;
/******************************************************************************
Conf::Conf() default constructor
*******************************************************************************/
Conf::Conf()
{
	top = nullptr;
	bottom = nullptr;
	left = nullptr;
	right = nullptr;
	assignment = 3;
}
/******************************************************************************
Conf(Space* to, Space* bo, Space* le, Space* ri) constructor
*******************************************************************************/
Conf::Conf(Space* to, Space* bo, Space* le, Space* ri)
{
	top = to;
	bottom = bo;
	left = le;
	right = ri;
	assignment = 3;
}
/******************************************************************************
int Conf::spaceAction() random event of the conf class
*******************************************************************************/
int Conf::spaceAction()
{
	int event = rand() % 100 + 1;

	if (event > 33 && event < 66)
	{
		cout << "Congratulations. You've best asked to give a presentation ";
		cout << "in your next meeting!" << endl;
		cout << "You've earned two additional points." << endl;
		return 2;
	}
	else if (event > 66)
	{
		cout << "The CEO has asked to attend your presentation." << endl;
		cout << "You've earned 3 additional points." << endl;
		return 3;
	}
	else if (event < 33)
	{
		cout << "You've made it to your morning meeting." << endl;
		cout << "You've earned 1 additional point." << endl;
		return 1;
	}
	return 0;
}
/*******************************************************************************
int Conf::moveSpace() move to a connecting space
*******************************************************************************/
int Conf::moveSpace()
{
	string choice;
	int uChoice;
	cout << "Your meeting is done. Where would you like to go next?" << endl;
	cout << " 1. HR 2. Lunch Room";
	cout << " 3. Cubicle 4. Stay in conference room" << endl;
	cin >> choice;
	uChoice = validateChoice4(choice);
	if (uChoice == 1)
	{
		cout << "Great.Be sure to get your new badge and name tag from " << endl;
		cout << "HR" << endl;
		return 5;
	}
	else if (uChoice == 2)
	{
		cout << "Enjoy your lunch today." << endl;
		return 4;
	}
	else if (uChoice == 3)
	{
		cout << "Back to your desk. You'll earn your bonus in no time." << endl;
		return 2;
	}
	else if (uChoice == 4)
	{
		cout << "Someone else is waiting to use this room." << endl;
		return 3;
	}
	return 0;
}
/*******************************************************************************
std::string Conf::givePen() return pen 85% of the time
********************************************************************************/
std::string Conf::givePen()
{
	int pen = rand() % 100 + 1;
	if (pen <= 85)
	{
		cout << "It's your lucky day. Someone returned your favorite pen.\n";
		cout << "Put it in your pocket this time." << endl;
		return "pen";
	}
	else
	{
		return "";
	}
}
