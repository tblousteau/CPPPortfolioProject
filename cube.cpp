/*****************************************************************************
Project: Final Project: Theme-The Office
Author: Toni Lousteau
Date: 12/7/2019
Description: implementation file for the cube class which is a child of the Space Class,
It has a default constructor and a constructor. It has
member functions spaceAction and moveSpace, which are overwritten functions.
It has a member function givePen(), which returns a string "pen".
*******************************************************************************/

#include "cube.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;

/******************************************************************************
Cube::Cube() default construtor
*******************************************************************************/
Cube::Cube()
{
	top = nullptr;
	bottom = nullptr;
	left = nullptr;
	right = nullptr;
	assignment = 2;
}

/******************************************************************************
Cube::Cube(Space* to, Space* bo, Space* le, Space* ri) constructor
*******************************************************************************/
Cube::Cube(Space* to, Space* bo, Space* le, Space* ri)
{
	top = to;
	bottom = bo;
	left = le;
	right = ri;
	assignment = 2;
}
/******************************************************************************
int Cube::spaceAction() random event of the cube class
*******************************************************************************/
int Cube::spaceAction()
{
	int event = rand() % 100 + 1;
	std::string choice;
	int uChoice;

	if (event > 33 && event < 66)
	{
		cout << "Your coworker needs help with a simple task.\n";
		cout << "Do you have time to help them? 1. Yes 2. No"<< endl;
		cin >> choice;
		uChoice = validateChoice(choice);
		if (uChoice == 1)
		{
			cout << "You've earned two additional points." << endl;
			return 2;
		}
		else if (uChoice == 2)
		{
			cout << "You've lost one point for not helping your team.\n";
			return (-1);
		}
	}
	else if (event > 66)
	{
		cout << "You've been asked to complete a project, but you " << endl;
		cout << "will have to work through lunch to get it done in time.\n";
		cout << "Do you want to accept it? 1. Yes 2. No";
		cin >> choice;
		uChoice = validateChoice(choice);
		if (uChoice == 1)
		{
			cout << "You've earned 2 additional points." << endl;
			return 2;
		}
		if (uChoice == 2)
		{
			cout << "No extra points today." << endl;
			return 0;
		}

	}
	else if (event < 33)
	{
		cout << "Welcome to the cubicle farm. You've made it " << endl;
		cout << " to your cube. You've earned 1 additional point." << endl;
		return 1;
	}
	return 0;
}

/*******************************************************************************
int Cube::moveSpace() move to connectiong space or stay
*******************************************************************************/
int Cube::moveSpace()
{
	string choice;
	int uChoice;
	cout << "Where would you like to go next? \n1. Conference Room 2. Lunch Room";
	cout << "\n3. Parking Garage 4. Stay at your desk and keep working" << endl;
	cin >> choice;
	uChoice = validateChoice4(choice);
	if (uChoice == 1)
	{
		cout << "Great. Your boss just booked a team meeting in the " << endl;
		cout << "conference room." << endl;
		return 3;
	}
	else if (uChoice == 2)
	{
		cout << "Enjoy your lunch today." << endl;
		return 4;
	}
	else if (uChoice == 3)
	{
		cout << "Leaving so soon? See you tommorrow." << endl;
		return 1;
	}
	else if (uChoice == 4)
	{
		cout << "Great job. You'll earn your bonus in no time." << endl;
		return 2;
	}
	return 0;
}
/*******************************************************************************
std::string Cube::givePen() return pen 85% of time
********************************************************************************/
std::string Cube::givePen()
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
