#include <iostream>

using namespace std;

template <class T>
class part
{
public:
	T v;
	part* next;
	part();
	part(T& v);
	~part();
};

template <class T>
class list
{
public:
	list();
	list(const list<T>& l);
	void add(T& v);
	bool operator==(const list<T>& l) const;
	bool operator!=(const list<T>& l) const;
	friend ostream& operator<<(ostream& out, const list<T>& l)
	{
		part<T>* p = l.first->next;
		while (p != nullptr)
		{
			out << p->v << " ";
			p = p->next;
		}
		out << endl;
		return out;
	}
	part<T>* first;
};

template <class T>
part<T>::part() : next(nullptr)
{}

template <class T>
part<T>::part(T& v) : next(nullptr), v(v)
{}

template <class T>
part<T>::~part()
{}

template <class T>
list<T>::list()
{
	first = new part<T>;
}

template <class T>
list<T>::list(const list<T>& l) : list<T>()
{
	part<T>* p = l.first->next;
	while (p != nullptr)
	{
		this->add(p->v);
		p = p->next;
	}
}

template <class T>
void list<T>::add(T& v)
{
	part<T>* p = first;
	part<T>* n = new part<T>(v);
	while ((p->next != nullptr) && (p->next->v > v))
	{
		p = p->next;
	}
	n->next = p->next;
	p->next = n;
	return;
}

template <class T>
bool list<T>::operator==(const list& l) const
{
	part<T>* p1 = first->next;
	part<T>* p2 = l.first->next;
	while ((p1 != nullptr) && (p2 != nullptr))
	{
		if (p1->v != p2->v)
		{
			return false;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return ((p1 == nullptr) && (p2 == nullptr));
}

template <class T>
bool list<T>::operator!=(const list& l) const
{
	return !this->operator==(l);
}