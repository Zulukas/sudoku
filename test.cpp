#include <iostream>
using namespace std;

int main()
{
	int x, y;

	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;

	cout << "Computing box...\n";
	cout << (x / 3) * 3 << " to " << (x / 3) * 3 + 2 << " for x.\n";
	cout << (y / 3) * 3 << " to " << (y / 3) * 3 + 2 << " for y.\n";
}