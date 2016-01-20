#include "cell.h"

Cell::Cell()
{
	value = 0;
	readOnly = false;
}

Cell::Cell(int value, bool readOnly = false) throw (const char*)
{
	if (value > 9)
	{
		throw OOBE;
	}
	
	this->value = value;
	this->readOnly = readOnly;
}

void Cell::setValue(int value) throw (const char*)
{
	if (value > 9)
	{
		throw OOBE;
	}
	if (readOnly)
	{
		throw ROE;
	}
	
	this->value = value;
}

int Cell::getValue() const
{
	return value;
}

bool Cell::isReadOnly() const
{
	return readOnly;
}

bool Cell::isEmpty() const
{
	return value == 0;
}

bool Cell::operator == (const int value) const
{
	return this->value == value;
}

bool Cell::operator != (const int value) const
{
	return this->value != value;
}

ostream& operator << (ostream& out, const Cell& c)
{
	out << c.getValue();

	return out;
}