#include "noms.h"

#include <string>
#include <sstream>

void get_polynom(polynom& p)
{
	string s;
	getline(cin, s);
	while (s.size() > 0)
	{
		stringstream ss;
		ss << s;
		double k;
		ss >> k;
		int xyz;
		ss >> xyz;
		p.add(monom(k, xyz));
		getline(cin, s);
	}
}

int main()
{
	cout << "To enter monom, first write the coefficient\nAfter the coefficient write one three-digit number\nFirst digit is power of x\nSecond is power of y\nThird is power of z\nAfter that press enter\nIf you want to stop writing polynom than press enter than string is empty" << endl;
	cout << "Write polynom" << endl;
	polynom p1;
	get_polynom(p1);
	cout << "Write the operation" << endl;
	string c;
	getline(cin, c);
	if (c == "+")
	{
		polynom p2;
		cout << "Write second polynom" << endl;
		get_polynom(p2);
		cout << p1 + p2;
	}
	else if (c == "*")
	{
		cout << "Multiply by a polynomial?" << endl;
		getline(cin, c);
		if (c == "Y")
		{
			polynom p2;
			get_polynom(p2);
			cout << p1 * p2;
		}
		else
		{
			double q;
			cin >> q;
			cout << p1 * q;
		}
	}
	cin >> c;
	return 0;
}