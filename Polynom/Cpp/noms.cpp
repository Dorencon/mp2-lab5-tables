#include "noms.h"

#include <iostream>

monom::monom()
{}

monom::monom(double k, int xyz) : k(k), xyz(xyz)
{}

bool monom::operator==(const monom& m) const
{
	return (xyz == m.xyz);
}

bool monom::operator!=(const monom& m) const
{
	return !((k == m.k) && (xyz == m.xyz));
}

bool monom::operator>(const monom& m) const
{
	return (xyz > m.xyz);
}

monom monom::operator+(const monom& m) const
{
	return monom(k + m.k, xyz);
}

monom monom::operator-(const monom& p) const
{
	return this->operator+(p * -1);
}

monom monom::operator*(const monom& m) const
{
	if ((xyz / 100 + m.xyz / 100 > 9) || (xyz / 10 % 10 + m.xyz / 10 % 10 > 9) || (xyz % 10 + m.xyz % 10 > 9))
	{
		throw runtime_error("Power more than 9");
	}
	return monom(k * m.k, xyz + m.xyz);
}

monom monom::operator*(const double q) const
{
	return monom(q * k, xyz);
}

ostream& operator<<(ostream& out, const monom& m)
{
	out << m.k << "x^" << m.xyz / 100 << "y^" << m.xyz / 10 % 10 << "z^" << m.xyz % 10;
	return out;
}

polynom::polynom() : l()
{}

polynom::polynom(const polynom& p) : l(p.l)
{}

polynom polynom::operator+(const polynom& p) const
{
	part<monom>* f1 = l.first->next;
	part<monom>* f2 = p.l.first->next;
	polynom pr;
	while ((f1 != nullptr) || (f2 != nullptr))
	{
		if ((f2 == nullptr) || ((f1 != nullptr) && (f1->v > f2->v)))
		{
			pr.add(f1->v);
			f1 = f1->next;
		}
		else if ((f1 == nullptr) || ((f2 != nullptr) && (f2->v > f1->v)))
		{
			pr.add(f2->v);
			f2 = f2->next;
		}
		else
		{
			pr.add(f1->v + f2->v);
			f1 = f1->next;
			f2 = f2->next;
		}
	}
	return pr;
}

polynom polynom::operator*(const polynom& p) const
{
	part<monom>* f1 = l.first->next;
	polynom pr;
	while (f1 != nullptr)
	{
		part<monom>* f2 = p.l.first->next;
		while (f2 != nullptr)
		{
			try
			{
				f1->v * f2->v;
			}
			catch (runtime_error* e)
			{
				cerr << e;
			}
			pr.add(f1->v * f2->v);
			f2 = f2->next;
		}
		f1 = f1->next;
	}
	return pr;
}

polynom polynom::operator-(const polynom& p) const
{
	return this->operator+(p * -1);
}

polynom polynom::operator*(const double q) const
{
	part<monom>* f = l.first->next;
	polynom pr;
	while (f != nullptr)
	{
		pr.add(f->v * q);
		f = f->next;
	}
	return pr;
}

bool polynom::operator==(const polynom& p) const
{
	return (l == p.l);
}

ostream& operator<<(ostream& out, const polynom& p)
{
	out << p.l;
	return out;
}

void polynom::add(monom& m)
{
	l.add(m);
}