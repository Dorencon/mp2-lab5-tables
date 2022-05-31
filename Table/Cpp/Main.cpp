#include "Hash.h"
#include "noms.h"
#include "Ordered.h"
#include "Unordered.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

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
	string s, sp;
	Unordered<polynom> u;
	Ordered<polynom> o;
	Hash<polynom> h;
	vector<polynom> pv;
	int key;
	while (true)
	{
		cout << "Waiting for operation" << endl;
		getline(cin, s);
		if (!s.size())
		{
			break;
		}
		if (s == "add")
		{
			cout << "From console?" << endl;
			string c;
			getline(cin, c);
			if (c == "N")
			{
				cin >> key;
				getline(cin, sp);
				u.add(pv[pv.size() - 1], key);
				o.add(key, pv[pv.size() - 1]);
				h.add(pv[pv.size() - 1], key);
				pv.pop_back();
			}
			else
			{
				polynom pol;
				cin >> key;
				getline(cin, sp);
				get_polynom(pol);
				u.add(pol, key);
				o.add(key, pol);
				h.add(pol, key);
			}
		}
		else if (s == "del")
		{
			cin >> key;
			getline(cin, sp);
			u.del(key);
			o.del(key);
			h.del(key);
		}
		else if (s == "find")
		{
			cin >> key;
			getline(cin, sp);
			pv.push_back(h.find(key));
			o.find(key);
			cout << u.find(key);
		}
		else if (s == "noms")
		{
			cout << "Write operation" << endl;
			string c;
			getline(cin, c);
			if (c == "+")
			{
				pv[pv.size() - 2] = pv[pv.size() - 1] + pv[pv.size() - 2];
				pv.pop_back();
				cout << pv[pv.size() - 1];
			}
			else if (c == "*")
			{
				cout << "Multiply by a polynomial?" << endl;
				getline(cin, c);
				if (c == "Y")
				{
					pv[pv.size() - 2] = pv[pv.size() - 1] + pv[pv.size() - 2];
					pv.pop_back();
					cout << pv[pv.size() - 1];
				}
				else
				{
					double q;
					cin >> q;
					getline(cin, sp);
					pv[pv.size() - 1] = pv[pv.size() - 1] * q;
					cout << pv[pv.size() - 1];
				}
			}
		}
	}
}