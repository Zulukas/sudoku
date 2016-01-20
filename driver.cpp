#include "grid.h"

#include <iostream>
using namespace std;

int main()
{
	Grid g("medium");

	set<unsigned short> PVs = g.getPVsAtLoc(Coordinate(4,4));

	for (unsigned short val : PVs)
	{
		cout << val << " ";
	}

	cout << endl;
}