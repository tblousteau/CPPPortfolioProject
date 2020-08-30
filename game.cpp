/*****************************************************************************
Project: Final Project: Theme-The Office
Author: Toni Lousteau
Date: 12/7/2019
Description: Implementation file for the game class, which has pointers to 6 Spaces
and a worker. It also has a default constructor. It has
member functions int start(), int sEMenu(); bool checkStatus(); int move();
int space(); and int nextSpace();
*******************************************************************************/

#include "game.hpp"

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::cin;
using std::getline;

/*******************************************************************************
Game::Game() default constructor (define spaces)
*******************************************************************************/
Game::Game()
{
	park = new Garage(cubicle, nullptr, nullptr, nullptr);
	cubicle =  new Cube(conference, park, nullptr,lunch);
	cOffice = new CeoOffice(nullptr, hR, nullptr, nullptr);
	conference = new Conf(hR, cubicle, lunch, nullptr);
	hR = new Hr(cOffice, conference, nullptr, nullptr);
	lunch = new Lunch(nullptr, nullptr, cubicle, conference);
}
/******************************************************************************
int Game::start() start game if Play Game Selected exit if exit, if play
gets user name and calls move function
*******************************************************************************/
int Game::start()
{
	string name;
	int userChoice;
	cout << "Welcome to Office Spaces. You work for a corporate technology \n";
	cout << "company. You are halfway to earning a yearly bonus. You need \n";
	cout << "10 additional brownie/bonus points to earn your bonus and win ";
	cout << "the game.\n If you lose the points you have, you lose the game.\n";
	userChoice = sEMenu();
	if (userChoice == 1)
	{
		cout << "Your company has issued name tags. Please type the name\n";
		cout << " you would like to appear on your tag." << endl;
		cin.ignore();
		getline(cin, name);
		player.setName(name);
		move();
	}
	return 0;
}
/******************************************************************************
int Game::sEMenu() re-used from the recursive function lab, play game or Quit
*******************************************************************************/
int Game::sEMenu()
{
	string choice; //stores user choice
	bool choiceTrue = false; //boolean which is set to true if choice == (1-4)
	string choices[2] =
	{
		"1. Play Game",
		"2. Quit Game"
	}; //menu, which is an array of strings

	cout << "Please choose an option." << endl;
	//print menu
	for (int n = 0; n < 2; n++)
	{
		cout << choices[n] << endl;
	}
	cin >> choice;
	//test user input to be an int 1 - 2
	for (int o = 1; o <= 2; o++)
	{
		string intString = to_string(o);
		if (choice == intString)
		{
			return stoi(choice);
			choiceTrue = true;
		}
	}
	//if not any int 1-4
	if (!choiceTrue)
	{
		cout<< "You chose " << choice << "." << endl;
		cout << "The valid choices are 1 or 2." << endl;
		return sEMenu();
	}
	return 0;

}
/******************************************************************************
int Game::move() starts game at parking garage, calls random event from Garage
and adds points and calls next space function
******************************************************************************/
int Game::move()
{
	int newPoints;
	cout << "Hi, " << player.getName() << "!" << endl;
	cout << "You are on your way to work!" << endl;
	cout << "You are now arriving at the parking garage.\n";
	cout << endl;
	player.setSpace(1);
	newPoints = park->spaceAction();
	player.addPoints(newPoints);
	cout << endl;
	nextSpace();
	return 0;
}
/******************************************************************************
int Game::nextSpace() determines where place is and calls random events from
the spaces and other functions from the spaces returns next space after space
specifc functions
******************************************************************************/
int Game::nextSpace()
{
	int current = player.getSpace();
	int next = 0;
	int newPoints = 0;
	string itemString;
	cout << endl;

	if (current == 1)
	{
		if (checkStatus())
		{
			sEMenu();
		}
		else
		{
			next = park->moveSpace();
			if (next == 2)
			{
				player.setSpace(2);
				newPoints = cubicle->spaceAction();
				cout << endl;
				itemString = cubicle -> givePen();
				if (itemString == "pen")
				{
					player.getPen();
				}
				player.addPoints(newPoints);
				return nextSpace();
			}
			else if (next == 1)
			{
				player.losePoints(2);
				cout << endl;
				cout << "Welcome to a new day." << endl;
				newPoints = park->spaceAction();
				player.addPoints(newPoints);
				return nextSpace();
		}

		}
	}
	if (current == 2)
	{
		if (checkStatus())
		{
			sEMenu();
		}
		else
		{
			next = cubicle->moveSpace();
			if (next == 1)
			{
				player.setSpace(1);
				cout << "You lost 2 points for cutting out early." << endl;
				player.losePoints(2);
				cout << endl;
				cout << "Welcome to the new day." << endl;
				newPoints = park->spaceAction();
				return nextSpace();
			}
			else if (next == 2)
			{
				cout << "You earned an extra point for your hard work." << endl;
				player.addPoints(1);
				newPoints = cubicle->spaceAction();
				cout << endl;
				itemString = cubicle -> givePen();
				if (itemString == "pen")
				{
					player.getPen();
				}
				player.addPoints(newPoints);
				return nextSpace();
			}
			else if (next == 3)
			{
				player.setSpace(3);
				cout << "Get ready for your meeting." << endl;
				newPoints = conference->spaceAction();
				cout << endl;
				player.addPoints(newPoints);
				itemString = cubicle -> givePen();
				if (itemString == "pen")
				{
					player.getPen();
				}
				return nextSpace();
			}
			else if (next == 4)
			{
				player.setSpace(4);
				newPoints = lunch->spaceAction();
				player.addPoints(newPoints);
				return nextSpace();
			}
		}
	}
	if (current == 3)
	{
		if (checkStatus())
		{
			sEMenu();
		}
		else
		{
			next = conference->moveSpace();
			if (next == 3)
			{
				cout << "You lost two points because the CEO needed that room.\n";
				player.losePoints(2);
				newPoints = conference->spaceAction();
				player.addPoints(newPoints);
				return nextSpace();
			}
			else if (next == 2)
			{
				player.setSpace(2);
				cout << "Great job. 1 additional point earned." << endl;
				player.addPoints(1);
				newPoints = cubicle->spaceAction();
				player.addPoints(newPoints);
				return nextSpace();
			}
			else if (next == 4)
			{
				player.setSpace(4);
				newPoints = lunch->spaceAction();
				player.addPoints(newPoints);
				return nextSpace();
			}
			else if (next == 5)
			{
				player.setSpace(5);
				newPoints = hR->spaceAction();
				itemString = hR->newItem();
				if (itemString == "badge")
				{
					player.getBadge();
				}
				player.addPoints(newPoints);
				return nextSpace();
			}
		}

	}
	if (current == 4)
	{
		if (checkStatus())
		{
			sEMenu();
		}
		else
		{
			next = lunch->moveSpace();
			if (next == 2)
			{
				player.setSpace(2);
				cout << "Great job. 1 additional point earned." << endl;
				player.addPoints(1);
				newPoints = cubicle->spaceAction();
				player.addPoints(newPoints);
				return nextSpace();
			}
			else if (next == 3)
			{
				player.setSpace(3);
				cout << "Open Enrollment is done.";
				return nextSpace();
			}
			else if (next == 4)
			{
				cout << "You better get back to work. People are starting \nto ";
				cout << "ask what it is you do around here.";
				return nextSpace();
			}
		}

	}
	if (current == 5)
	{
		if (checkStatus())
		{
			sEMenu();
		}
		else
		{
			next = hR->moveSpace();
			if (next == 3)
			{
				player.setSpace(3);
				newPoints = conference->spaceAction();
				player.addPoints(newPoints);
				return nextSpace();
			}
			else if (next == 5)
			{
				cout << "You've lost 1 point for wasting time on the clock.";
				cout << endl;
				player.losePoints(1);
				return nextSpace();
			}
			else if (next == 6)
			{
				player.setSpace(6);
				int currentPoints = player.getPoints();
				if (currentPoints >= 20)
				{
					if (player.hasItems())
					{
						cout << "Grab your pen. It's time to sign your bonus\n";
						cout << " paperwork. You've earned your bonus!\n";
						player.getCheck();
						return sEMenu();

					}
					else
					{
						cout << "Go back and get your pen and badge to ";
						cout << "receive your bonus" << endl;

					}

				}
				return nextSpace();
			}
		}
	}
	if (current == 6)
	{
		if (checkStatus())
		{
			sEMenu();
		}
		else
		{
			next = cOffice->moveSpace();
			if (next == 5)
			{
				player.setSpace(5);
				newPoints = hR->spaceAction();
				player.addPoints(newPoints);
				return nextSpace();
			}
			else if (next == 6)
			{
				player.losePoints(4);
				return nextSpace();
			}
		}

	}
	return 0;
}

/*******************************************************************************
Game::~Game()
*******************************************************************************/
Game::~Game()
{
	delete park;
	delete cubicle;
	delete conference;
	delete hR;
	delete cOffice;
	delete lunch;
}
/*******************************************************************************
bool Game::checkStatus() //true if game over, false otherwise
*******************************************************************************/
bool Game::checkStatus()
{
	int currentPoints = player.getPoints();
	if (currentPoints <= 0)
	{
		cout << "You have lost all of your points. You have \nlost your job at";
		cout << " Office Spaces ";
		return true;
	}
	if (currentPoints >= 20)
	{
		if (player.hasItems() && player.getSpace() > 4)
		{
			cout << "You have earned the rest of the points for you bonus.\n";
			cout << " Grab your pen and head to HR or the CEO's Office.";
			if (player.getSpace() == 5)
			{
				hR->giveCheck();
				player.getCheck();
			}
			if (player.getSpace() == 6)
			{
				cOffice->giveCheck();
				player.getCheck();
			}
			return true;
		}
		else
		{
			cout << "You will need to find a pen and your badge to receive ";
			cout << "your bonus check." << endl;
		}

	}
	return false;
}
