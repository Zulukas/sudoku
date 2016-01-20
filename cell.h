#pragma once

#include <iostream>
using std::ostream;

#define OOBE "ERROR: Out of bounds; value must be 0-9.";
#define ROE  "ERROR: Cell is read-only.";

class Cell
{
public:
	Cell();
	Cell(int value, bool readOnly) throw (const char*);

	void setValue(int value) throw (const char*);

	int getValue() const;
	bool isReadOnly() const;
	bool isEmpty() const;

	bool operator == (const int value) const;
	bool operator != (const int value) const;

private:
	unsigned short value;
	bool readOnly;	
};

ostream& operator << (ostream& out, const Cell& c);
