/*****************************************************************************
Project: Final Project: Theme-The Office
Author: Toni Lousteau
Date: 12/7/2019
Description: implemenation file for the lunch class  which is a child of the
Space Class. It has a default constructor and a constructor. It has
member functions spaceAction and moveSpace, which are overwritten functions.
*******************************************************************************/

#include "lunch.hpp"


using std::cout;
using std::endl;
using std::cin;
using std::string;


/******************************************************************************
Lunch::Lunch() default constructor
*******************************************************************************/
Lunch::Lunch()
{
	top = nullptr;
	bottom = nullptr;
	left = nullptr;
	right = nullptr;
	assignment = 4;
}
/******************************************************************************
Lunch::Lunch(Space* to, Space* bo, Space* le, Space* ri) constructor
*******************************************************************************/
Lunch::Lunch(Space* to, Space* bo, Space* le, Space* ri)
{
	top = to;
	bottom = bo;
	left = le;
	right = ri;
	assignment = 4;
}
/******************************************************************************
int Lunch::spaceAction() random event, returns point value for choice
*******************************************************************************/
int Lunch::spaceAction()
{
	int event = rand() % 100 + 1;
	std::string choice;
	int uChoice = 0;

	if (event > 33 && event < 66)
	{
		cout << "You see that someone has taken your lunch today.\n";
		cout << "You've earned 1 point for feeding your coworker.";
		return 1;
	}
	else if (event > 66)
	{
		cout << "You see a coworker sitting alone." << endl;
		cout << "Do you sit down next to them? 1. Yes 2. No";
		cin >> choice;
		uChoice = validateChoice(choice);
		if (uChoice == 1)
		{
			cout << "You've earned 1 additional points for ";
			cout << " getting to know your team." << endl;
			return 1;
		}
		if (uChoice == 2)
		{
			cout << "Eat lunch and get back to work." << endl;
			return 0;
		}

	}
	else if (event < 33)
	{
		cout << "Welcome to the lunch room. Eat your lunch in peace." << endl;
		return 0;
	}
	return 0;
}
/*******************************************************************************
int Lunch::moveSpace() move to connecting space, returns assignment of space
*******************************************************************************/
int Lunch::moveSpace()
{
	string choice;
	int uChoice;
	cout << "Lunch is done. Where would you like to go next?" << endl;
	cout << " 1. Conference Room 2. Cubicle 3. Stay in Lunch Room ";
	cout << endl;
	cin >> choice;
	uChoice = validateChoice3(choice);
	if (uChoice == 1)
	{
		cout << "Great. You can sit in on the open enrollment meeting." << endl;
		return 3;
	}
	else if (uChoice == 2)
	{
		cout << "Back to your desk. You'll earn your bonus in no time." << endl;
		return 2;
	}
	else if (uChoice == 3)
	{
		cout << "Take a long Lunch. You've earned it." << endl;
		return 4;
	}
	return 0;
}
