#pragma once

#include "cell.h"

#include <algorithm>
#include <coordinate.h>
#include <cstdlib>
#include <iostream>
#include <list>
#include <set>
#include <string>

using std::cout;
using std::endl;
using std::list;
using std::set;
using std::string;

class Grid
{
public:
	Grid() { generatePuzzle(40); }
	Grid(string mode);

	void setCellAtLoc(const Coordinate& c, const Cell& cell) throw (const char*);
	Cell getCellAtLoc(const Coordinate& c) const;
	set<unsigned short> getPVsAtLoc(const Coordinate& c) const;

	bool cellIsValid(const Coordinate& c, const Cell& cell) const;

	void display() const;

	Cell& operator [] (const Coordinate& c);

private:
	Cell grid[9][9];


	void generatePuzzle(unsigned short cells);
};