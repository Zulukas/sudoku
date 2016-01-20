#include "game.h"

Game::Game(string mode) : grid(mode);
{}

void Game::loop()
{
	while (true)
	{
		displayOptions();

		int choice;
		cin >> choice;

		switch (choice)
		{
			case 1:
				enterValue();
				break;
			case 2:
				displayPossibleValueAtLoc();
				break;
			case 3:
				return;
			default:
				grid.display();
				cout << endl;
				displayOptions();

		}
	}
}

string Game::getCoordinate()
{
	cout << "Enter coordinate: ";
	string input;
	cin >> input;

	return input;
}

void Game::displayOptions() const
{
	cout << "Options:\n"
		     << "\t1. Enter value at square\n"
		     << "\t2. Get possible values at square\n"
		     << "\t3. Exit\n\n";
}

void Game::displayPossibleValueAtLoc() const
{

}