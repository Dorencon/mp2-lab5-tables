#include "gtest.h"
#include "noms.h"

TEST(Lists, can_create_list_of_monoms)
{
	ASSERT_NO_THROW(list<monom> l);
}

TEST(Lists, can_add_to_list)
{
	monom m(2, 123);
	list<monom> l;
	ASSERT_NO_THROW(l.add(m));
}

TEST(Lists, can_copy_list)
{
	list<monom> l1;
	monom m(2, 123);
	l1.add(m);
	m = monom(3, 111);
	l1.add(m);
	list<monom> l2(l1);
	ASSERT_EQ(l1, l2);
}