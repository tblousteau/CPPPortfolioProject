/*****************************************************************************
Project: Final Project: Theme-The Office
Author: Toni Lousteau
Date: 12/7/2019
Description: implemenation file for the Hr class, which is a child
of the Space Class. It has a default constructor and a constructor. It has
member functions spaceAction and moveSpace, which are overwritten functions.
It has a member function giveCheck(), which returns a string "check" and newItem,
which returns a string "badge"
*******************************************************************************/

#include "hr.hpp"


using std::cout;
using std::endl;
using std::cin;
using std::string;

/******************************************************************************
Hr::Hr() default constructor
*******************************************************************************/
Hr::Hr()
{
	top = nullptr;
	bottom = nullptr;
	left = nullptr;
	right = nullptr;
	assignment = 5;
}

/******************************************************************************
Hr::Hr(Space* to, Space* bo, Space* le, Space* ri) constructor
*******************************************************************************/
Hr::Hr(Space* to, Space* bo, Space* le, Space* ri)
{
	top = to;
	bottom = bo;
	left = le;
	right = ri;
	assignment = 5;
}
/******************************************************************************
int Hr::spaceAction() random event of HR class, returns positive or negative
point value depending on user choice
*******************************************************************************/
int Hr::spaceAction()
{
	int event = rand() % 100 + 1;
	std::string choice;
	int uChoice = 0;

	if (event > 33 && event < 66)
	{
		cout << "You've been asked to volunteer for an event.";
		cout << "Do you want to help out? 1. Yes 2. No "<< endl;
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
		cout << "You walk by HR and hear office gossip. Do you " << endl;
		cout << "participate? 1. Yes 2. No";
		cin >> choice;
		uChoice = validateChoice(choice);
		if (uChoice == 2)
		{
			cout << "You've earned 1 additional points." << endl;
			return 1;
		}
		if (uChoice == 1)
		{
			cout << "You lose 3 points for wasting time at work.";
			cout << endl;
			return -3;
		}

	}
	else if (event < 33)
	{
		cout << "You've made it to HR to update your benefits." << endl;
		cout << "You've earned one additional point.";
		return 1;
	}
	return 0;
}
/*******************************************************************************
int Hr:moveSpace()move to a connecting space or stay, returns int assingment of
next space
*******************************************************************************/
int Hr::moveSpace()
{
	string choice;
	int uChoice;
	cout << "where would you like to go next?" << endl;
	cout << " 1. CEO's Office 2. Conference 3. Hang out with HR Team ";
	cout << endl;
	cin >> choice;
	uChoice = validateChoice3(choice);
	if (uChoice == 1)
	{
		cout << "Good luck!" << endl;
		return 6;
	}
	else if (uChoice == 2)
	{
		cout << "So many meetings, how does anyone get any work done?" << endl;
		return 3;
	}
	else if (uChoice == 3)
	{
		cout << "Don't stay here too long." << endl;
		return 5;
	}
	return 0;
}
/*****************************************************************************
std::string newItem() 75% of time give badge, return "badge" or ""
*******************************************************************************/
std::string Hr::newItem()
{
	int badge = rand() % 100 + 1;
	if (badge <= 75)
	{
		cout << "Congrats, you're new badge is ready!";
		return "badge";
	}
	else
	{
		return "";
	}
	return "";
}
/******************************************************************************
std::string Hr::giveCheck(); give check returns "check"
*******************************************************************************/
std::string Hr::giveCheck()
{
	cout << "Congratulations you've earned your bonus. Be sure to ";
	cout << "\n return the paperwork by the end of the day." << endl;
	return "check";
}
