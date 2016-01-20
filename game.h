#pragma once

#include "cell.h"
#include "grid.h"

#include <string>
#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::string;
using std::set;

class Game
{
public:
	Game(string mode);

	void loop();
private:
	Grid grid;

	string getCoordinate();
	Coordinate interpetInput(const string& msg);
	void enterValue();
	unsigned int countEmptySquares();

	void displayOptions() const;
	void displayPossibleValueAtCell() const;
}