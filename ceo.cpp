/*****************************************************************************
Project: Final Project: Theme-The Office
Author: Toni Lousteau
Date: 12/7/2019
Description: implemenation file for the CeoOffice class, which is a child
of the Space Class. It has a default constructor and a constructor. It has
member functions spaceAction and moveSpace, which are overwritten functions.
It has a member function giveCheck(), which returns a string "check".

*******************************************************************************/

#include "ceo.hpp"
using std::cout;
using std::endl;
using std::string;
using std::cin;
/******************************************************************************
CeoOffice::CeoOffice() default constructor
*******************************************************************************/
CeoOffice::CeoOffice()
{
 	top = nullptr;
	right = nullptr;
	bottom = nullptr;
	left = nullptr;
	assignment = 6;
}
/******************************************************************************
CeoOffice(Space* to, Space* bo, Space* le, Space* ri) constructor
*******************************************************************************/
CeoOffice::CeoOffice(Space* to, Space* bo, Space* le, Space* ri)
{
	top = to;
	bottom = bo;
	left = le;
	right = ri;
	assignment = 6;
}
/******************************************************************************
int CeoOffice::spaceAction() random event of the class
*******************************************************************************/
int CeoOffice::spaceAction()
{
	int event = rand() % 50 + 1;

	if (event > 25)
	{
		cout << "Congratulations. You've earned 2 bonus points in\n ";
		cout << "your meeting with the CEO!" << endl;
		return 2;
	}
	else
	{
		cout << "The CEO is out today. Your meeting was rescheduled." << endl;
		return 0;
	}
	return 0;
}
/*****************************************************************************
int CeoOffice::moveSpace() move to a connecting space
*******************************************************************************/
int CeoOffice::moveSpace()
{
	string choice;
	int uChoice = 0;
	cout << "Where would you like to go next? The CEO would prefer you\n";
	cout << " leave their office. You can go to 1. HR or 2. Stay in CEO's Office ";
	cout << endl;
	cin >> choice;
	uChoice = validateChoice(choice);
	if (uChoice == 1)
	{
		cout << "Great you can discuss ordering new supplies" << endl;
		return 5;
	}
	if (uChoice == 2)
	{
		cout << "You are staying in the CEO's Office "<< endl;
		cout << " You've lost 4 bonus points for delaying your projects." << endl;
		return 6;
	}
	return 0;
}
/******************************************************************************
std::string CeoOffice::giveCheck(); returns check
*******************************************************************************/
std::string CeoOffice::giveCheck()
{
	cout << "Congratulations you've earned your bonus. Be sure to ";
	cout << "\n return the paperwork by the end of the day." << endl;
	return "check";
}
