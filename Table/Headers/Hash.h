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
		table = new cellH<T>*[size];
		for (size_t i = 0; i < size; i++)
		{
			table[i] = NULL;
		}
	}
	void add(T data, int key)
	{
		if (size == Msize)
		{
			throw exception("Low memory");
		}
		cellH<T>* t = new cellH<T>(data, key);
		if (table[key % Msize] == NULL)
		{
			table[key % Msize] = t;
			size++;
			cout << "Hash add " << 1 << endl;
		}
		else
		{
			size_t ct = 0;
			int hs = key % Msize;
			while (true)
			{
				ct++;
				hs = (hs + (key / 2) % Msize) % Msize;
				if (table[hs] == NULL)
				{
					table[hs] = t;
					size++;
					cout << "Hash add " << ct << endl;
					return;
				}
			}
		}
	}
	T find(int key)
	{
		size_t ct = 0;
		int hs = key % Msize;
		while (ct < Msize)
		{
			ct++;
			if ((table[hs] != NULL) && (table[hs]->key == key))
			{
				break;
			}
			hs = (hs + (key / 2) % Msize) % Msize;
		}
		if (ct == Msize)
		{
			throw exception("Cant find key");
		}
		cout << "Hash find " << ct << endl;
		return table[hs]->data;
	}
	void del(int key)
	{
		size_t ct = 0;
		if (size == 0)
		{
			throw exception("Nothing to delete");
		}
		int hs = key % Msize;
		while (ct < Msize)
		{
			ct++;
			if ((table[hs] != NULL) && (table[hs]->key == key))
			{
				table[hs] = NULL;
				size--;
				cout << "Hash delete " << ct << endl;
				return;
			}
		}
		throw exception("Nothing to delete");
	}
	size_t get_size()
	{
		return size;
	}
private:
	cellH<T>** table;
	size_t Msize, size;
};