#include <vector>

using namespace std;

template <typename T>
struct cellH
{
	int key;
	T data;
	cellH(T d, int k)
	{
		data = d;
		key = k;
	}
	cellH(){}
};

template <typename T>
class Hash
{
public:
	Hash(size_t size = 50)
	{
		Msize = size;
		this->size = 0;
		table = new vector<cellH<T>*>[size];
	}
	void add(T data, int key)
	{
		cellH<T>* t = new cellH<T>(data, key);
		if (table[key % Msize].size() == 0)
		{
			size++;
		}
		table[key % Msize].push_back(t);
		cout << "Hash add " << 1 << endl;
	}
	T find(int key)
	{
		size_t ct = 0;
		if (table[key % Msize].size() == 0)
		{
			throw exception("Cant find key");
		}
		for (size_t i = 0; i < table[key % Msize].size(); i++)
		{
			ct++;
			if (table[key % Msize][i]->key == key)
			{
				cout << "Hash find " << ct << endl;
				return table[key % Msize][i]->data;
			}
		}
		throw exception("Cant find key");
	}
	void del(int key)
	{
		size_t ct = 0;
		if ((size == 0) || (table[key % Msize].size() == 0))
		{
			throw exception("Nothing to delete");
		}
		size_t t = table[key % Msize].size();
		for (size_t i = 0; i < table[key % Msize].size(); i++)
		{
			ct++;
			if (table[key % Msize][i]->key == key)
			{
				t = i;
				break;
			}
		}
		if (t == table[key % Msize].size())
		{
			throw exception("Nothing to delete");
		}
		ct++;
		table[key % Msize][t] = table[key % Msize][table[key % Msize].size() - 1];
		table[key % Msize].pop_back();
		if (!table[key % Msize].size())
		{
			size--;
		}
		cout << "Hash delete " << ct << endl;
	}
	size_t get_size()
	{
		return size;
	}
private:
	vector<cellH<T>*>* table;
	size_t Msize, size;
};