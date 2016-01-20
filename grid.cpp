#include "grid.h"

Grid::Grid(string mode)
{
	if (mode == "easy")
	{
		generatePuzzle(40);
	}
	else if (mode == "medium")
	{
		generatePuzzle(25);
	}
	else if (mode == "hard")
	{
		generatePuzzle(10);
	}
	else
	{
		generatePuzzle(40);
	}

}

void Grid::setCellAtLoc(const Coordinate& c, const Cell& cell) throw (const char*)
{
	grid[c.getY()][c.getX()] = cell;
}

Cell Grid::getCellAtLoc(const Coordinate& c) const
{
	return grid[c.getY()][c.getX()];
}

set<unsigned short> Grid::getPVsAtLoc(const Coordinate& c) const
{
	set<unsigned short> PVs;

	if (grid[c.getY()][c.getX()] != 0)
		return PVs;

	for (int i = 1; i < 10; i++)
	{
		PVs.insert(i);
	}

	//Check rows
	for (unsigned short row = 0; row < 9; row++)
	{
		unsigned short val = grid[row][c.getX()].getValue();

		if (row == c.getY()) //Don't bother checking this cell
			continue;

		//If the value is already in the list, continue, else add it.
		if (PVs.find(val) == PVs.end() || val == 0)
			continue;
		else
			PVs.erase(PVs.find(val));
	}

	//Check cols
	for (unsigned short col = 0; col < 9; col++)
	{
		unsigned short val = grid[c.getY()][col].getValue();

		if (col == c.getX()) //Don't bother checking this cell
			continue;

		//If the value is already in the list, continue, else add it.
		if (PVs.find(val) == PVs.end() || val == 0)
			continue;
		else
			PVs.erase(PVs.find(val));
	}

	//Check the "box"
	for (unsigned short row = (c.getY() / 3) * 3; row < ((c.getY() / 3) * 3) + 3; row++)
	{
		for (unsigned short col = (c.getX() / 3) * 3; col < ((c.getX() / 3) * 3) + 3; col++)
		{
			unsigned short val = grid[row][col].getValue();

			if (row == c.getY() && col == c.getX()) //Don't bother checking this cell
				continue;

			//If the value is already in the list, continue, else add it.
			set<unsigned short>::iterator it = PVs.find(val);
			if (it == PVs.end() || val == 0)
				continue;
			else
				PVs.erase(it);
		}
	}
}

bool Grid::cellIsValid(const Coordinate& c, const Cell& cell) const
{
	if (cell.getValue() == 0)
		return true;

	//Check rows
	for (unsigned short row = 0; row < 9; row++)
	{
		if (row == c.getY())
			continue;

		if (cell.getValue() == grid[row][c.getX()].getValue())
			return false;
	}

	//Check cols
	for (unsigned short col = 0; col < 9; col++)
	{
		if (col == c.getX())
			continue;

		if (cell.getValue() == grid[c.getY()][col].getValue())
			return false;
	}

	//Check the "box"
	for (unsigned short row = (c.getY() / 3) * 3; row < ((c.getY() / 3) * 3) + 3; row++)
	{
		for (unsigned short col = (c.getX() / 3) * 3; col < ((c.getX() / 3) * 3) + 3; col++)
		{
			if (row == c.getY() && col == c.getX())
				continue;

			if (grid[row][col] == cell.getValue())
				return false;
		}
	}

	return true;
}

void Grid::display() const
{
	cout << "   A B C | D E F | G H I\n";
	cout << endl;

	for (int row = 0; row < 9; row++)
	{
		cout << row + 1 << "  ";

		for (int col = 0; col < 9; col++)
		{
			cout << grid[row][col] << " ";

			if (col == 2 || col == 5)
			{
				cout << "| ";
			}
		}

		if (row == 2 || row == 5)
		{
			cout << "\n-  ------+-------+------\n";
		}
		else
		{
			cout << endl;
		}
	}
}

Cell& Grid::operator [] (const Coordinate& c)
{
	return grid[c.getY()][c.getX()];
}

void Grid::generatePuzzle(unsigned short cells)
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			if (row == 7)
			{
				row = 7;
			}
			grid[row][col] = Cell();
		}
	}

	// display();

	srand(time(NULL)); //set the time for srand to NULL.

	int col, row, val;

	for (int i = 0; i < cells; i++)
	{
		bool invalid = true; //To signal a good value has been found
		set<unsigned short> triedVals; //To not repeat ourselves.

		bool RESET = false; //Helps us get out of ruts

		while (invalid)
		{
			RESET = false;
			col = (rand() % 9);
			row = (rand() % 9);	

			//If it's empty, start trying to put new values in
			if (grid[row][col].isEmpty())
			{
				if (RESET)
					break;

				val = (rand() % 9) + 1;

				Cell newCell(val, true);
		
				Coordinate c(col, row);

				//While it's not valid, generate new values and try again.
				while (!cellIsValid(c, newCell))
				{			
					if (RESET)
						break;

					triedVals.insert(val); //Put it in the set

					//Generate a new value until we get one we haven't tried.
					while (triedVals.find(val) != triedVals.end())					
					{	
						if (RESET)
							break;

						if (triedVals.size() == 9)
						{
							RESET = true;
							break;
						}

						val = (rand() % 9) + 1;						
					}

					newCell = Cell(val, true);					
				}

				//After a valid cell has been found, set it and set the invalid flag to false
				grid[row][col] = newCell;
				invalid = false;
			}
		}
	}

	display();
}