/*****************************************************************************
Project: Final Project: Theme-The Office
Author: Toni Lousteau
Date: 12/7/2019
Description: implementation file for the garage class which is a child of the Space Class,
It has a default constructor and a constructor. It has
member functions spaceAction and moveSpace, which are overwritten functions.
*******************************************************************************/

#include "garage.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;


/******************************************************************************
Garage::Garage() default constructor
*******************************************************************************/
Garage::Garage()
{
	top = nullptr;
	bottom = nullptr;
	left = nullptr;
	right = nullptr;
	assignment = 1;
}
/******************************************************************************
Garage::Garage(Space* to, Space* bo, Space* le, Space* ri) constructor
*******************************************************************************/
Garage::Garage(Space* to, Space* bo, Space* le, Space* ri)
{
	top = to;
	bottom = bo;
	left = le;
	right = ri;
	assignment = 1;

}
/******************************************************************************
int Garage::spaceAction() random event in parking garage space
*******************************************************************************/
int Garage::spaceAction()
{
	int event = rand() % 100 + 1;
	std::string choice;
	int uChoice = 0;

	if (event > 33 && event < 66)
	{
		cout << "You see that your boss is behind you and there is a\n";
		cout << "good parking spot available.\n";
		cout << "Do you want to let them take it? 1. Yes 2. No "<< endl;
		cin >> choice;
		uChoice = validateChoice(choice);
		if (uChoice == 1)
		{
			cout << "You've earned two additional brownie points." << endl;
			return 2;
		}
		else if (uChoice == 2)
		{
			cout << "You've earned no brownie points\n";
			return 0;
		}
	}
	else if (event > 66)
	{
		cout << "You're late and see a reserved spot available right" << endl;
		cout << " next to the entrace. ";
		cout << "\nDo you take it? 1. Yes 2. No" << endl;
		cin >> choice;
		uChoice = validateChoice(choice);
		if (uChoice == 2)
		{
			cout << "You've earned 1 additional points." << endl;
			return 1;
		}
		if (uChoice == 1)
		{
			cout << "You lose 2 points for inconveniencing your";
			cout << " coworker." << endl;
			return -2;
		}

	}
	else if (event < 33)
	{
		cout << "Welcome to the parking garage. Find a spot and " << endl;
		cout << " get to work." << endl;
		return 0;
	}
	return 0;
}
/*****************************************************************************
int Garage::moveSpace() move or stay returns assignment of space
*******************************************************************************/
int Garage::moveSpace()
{
	string choice;
	int uChoice = 0;
	cout << "Where would you like to go next? 1. Your desk ";
	cout << "2. Stay in Garage and skip work" << endl;
	cin >> choice;
	uChoice = validateChoice(choice);
	if (uChoice == 1)
	{
		cout << "You are going to the cube farm." << endl;
		return 2;
	}
	if (uChoice == 2)
	{
		cout << "You are staying in the garage, but you will lose ";
		cout << "2 bonus points for delaying your projects." << endl;
		return 1;
	}
	return 0;
}
