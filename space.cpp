/*****************************************************************************
Project: Final Project: Theme-The Office
Author: Toni Lousteau
Date: 12/7/2019
Description: implementation file for the Space class which
 contains four space pointers, it contains member functions space action and
 move space, which are overwritten, it contains 3 int validation functions
 validateChoice for two choices, validateChoice3 for 3 choices, and validateChoice4
 for 4 choices, it has a virtual destructor, a default constructor and a constructor
*******************************************************************************/

#include "space.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::to_string;
using std::string;

/*****************************************************************************
Space::Space() default constructor
******************************************************************************/
Space::Space()
{
	top = nullptr;
	bottom = nullptr;
	right = nullptr;
	left = nullptr;
	assignment = 0;

}
/*****************************************************************************
Space(Space* to, Space* bo, Space* le, Space* ri) constructor
******************************************************************************/
Space::Space(Space* to, Space* bo, Space* le, Space* ri)
{
	top = to;
	bottom = bo;
	right = ri;
	left = le;
	assignment = 0;
}
/*****************************************************************************
int Space::spaceAction() return 0
******************************************************************************/

int Space::spaceAction()
{
	return 0;
}
/*****************************************************************************
int Space::validateChoice(std::string choice) validates 1 or 2
******************************************************************************/
int Space::validateChoice(std::string choice)
{
	bool choiceTrue = false;
	std::string newChoice;

	for (int o = 1; o <= 2; o++)
	{
		string intString = to_string(o);
		if (choice == intString)
		{
			return stoi(choice);
			choiceTrue = true;
		}
	}
	if (!choiceTrue)
	{
		cout<< "You chose " << choice << "." << endl;
		cout << "The valid choices are 1 or 2." << endl;
		cin >> newChoice;
		return validateChoice(newChoice);
	}
	return 0;
}
/*****************************************************************************
int Space::validateChoice3(std::string choice) validates 1, 2, or 3
******************************************************************************/
int Space::validateChoice3(std::string choice)
{
	bool choiceTrue = false;
	std::string newChoice;

	for (int o = 1; o <= 3; o++)
	{
		string intString = to_string(o);
		if (choice == intString)
		{
			return stoi(choice);
			choiceTrue = true;
		}
	}
	if (!choiceTrue)
	{
		cout<< "You chose " << choice << "." << endl;
		cout << "The valid choices are 1, 2, or 3." << endl;
		cin >> newChoice;
		return validateChoice3(newChoice);
	}
	return 0;
}
/*****************************************************************************
int Space::validateChoice4(std::string choice) validates 1, 2, 3, or 4
******************************************************************************/
int Space::validateChoice4(std::string choice)
{
	bool choiceTrue = false;
	std::string newChoice;

	for (int o = 1; o <= 4; o++)
	{
		string intString = to_string(o);
		if (choice == intString)
		{
			return stoi(choice);
			choiceTrue = true;
		}
	}
	if (!choiceTrue)
	{
		cout<< "You chose " << choice << "." << endl;
		cout << "The valid choices are 1, 2, 3, or 4." << endl;
		cin >> newChoice;
		return validateChoice4(newChoice);
	}
	return 0;
}
/*******************************************************************************
int Space::moveSpace() return 0
*******************************************************************************/
int Space::moveSpace()
{
	return 0;
}
/******************************************************************************
Space::~Space() virtual destructor
*******************************************************************************/
Space::~Space(){}
