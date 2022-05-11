#include "list.h"

class monom
{
public:
	double k;
	int xyz;
	monom();
	monom(double k, int xyz);
	bool operator==(const monom& m) const;
	bool operator!=(const monom& m) const;
	bool operator>(const monom& m) const;
	monom operator+(const monom& m) const;
	monom operator*(const monom& m) const;
	monom operator*(const double q) const;
	friend ostream& operator<<(ostream& out, const monom& m);
};

class polynom
{
public:
	polynom();
	polynom(const polynom& p);
	polynom operator+(const polynom& p) const;
	polynom operator-(const polynom& p) const;
	polynom operator*(const polynom& p) const;
	polynom operator*(const double q) const;
	bool operator==(const polynom& p) const;
	friend ostream& operator<<(ostream& out, const polynom& p);
	void add(monom& m);
private:
	list<monom> l;
};