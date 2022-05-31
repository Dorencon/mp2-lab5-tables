#include "gtest.h"
#include "noms.h"

TEST(Monoms, can_create_monom)
{
	ASSERT_NO_THROW(monom(2, 123));
}

TEST(Monoms, can_sum_monoms)
{
	monom m1(2, 123), m2(3, 123), m3(5, 123);
	ASSERT_EQ(m1 + m2, m3);
}

TEST(Monoms, can_mult_monoms)
{
	monom m1(2, 123), m2(3, 123), m3(6, 246);
	ASSERT_EQ(m1 * m2, m3);
}

TEST(Monoms, cant_mult_power_more_than_9)
{
	monom m1(2, 555), m2(3, 555);
	ASSERT_ANY_THROW(m1 * m2);
}

TEST(Monoms, can_mult_on_const)
{
	monom m1(2, 123), m2(6, 123);
	double d = 3;
	ASSERT_EQ(m1 * d, m2);
}

TEST(Polynoms, can_sum_polynoms)
{
	polynom p1, p2;
	p1.add(monom(2, 123));
	p1.add(monom(3, 111));
	p2.add(monom(3, 123));
	p2.add(monom(4, 222));
	polynom p3;
	p3.add(monom(5, 123));
	p3.add(monom(3, 111));
	p3.add(monom(4, 222));
	ASSERT_EQ(p1 + p2, p3);
}

TEST(Polynoms, can_subtract_polynoms)
{
	polynom p1, p2;
	p1.add(monom(2, 123));
	p1.add(monom(3, 222));
	p2.add(monom(3, 123));
	p2.add(monom(4, 222));
	polynom p3;
	p3.add(monom(-1, 123));
	p3.add(monom(-1, 222));
	ASSERT_EQ(p1 - p2, p3);
}

TEST(Polynoms, can_mult_polynoms)
{
	polynom p1, p2;
	p1.add(monom(2, 123));
	p1.add(monom(3, 111));
	p2.add(monom(3, 123));
	p2.add(monom(4, 222));
	polynom p3;
	p3.add(monom(6, 246));
	p3.add(monom(9, 234));
	p3.add(monom(8, 345));
	p3.add(monom(12, 333));
	ASSERT_EQ(p1 * p2, p3);
}

TEST(Polynoms, can_mult_on_const)
{
	polynom p1;
	p1.add(monom(2, 123));
	p1.add(monom(3, 111));
	double d = 3;
	polynom p2;
	p2.add(monom(6, 123));
	p2.add(monom(9, 111));
	ASSERT_EQ(p1 * d, p2);
}