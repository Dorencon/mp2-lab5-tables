using namespace std;

template <typename T>
struct cellU
{
	int key;
	T data;
	cellU(T d, int k)
	{
		data = d;
		key = k;
	}
	cellU(){}
};

template <typename T>
class Unordered
{
public:
	Unordered(size_t size = 50)
	{
		Msize = size;
		this->size = 0;
		table = new cellU<T>*[size];
		for (size_t i = 0; i < size; i++)
		{
			table[i] = NULL;
		}
	}
	void add(T data, int key)
	{
		if (size > Msize)
		{
			throw exception("Low memory");
		}
		table[size] = new cellU<T>(data, key);
		size++;
		cout << "Unordered add " << 1 << endl;
	}
	void del(int key)
	{
		size_t ct = 1;
		if (size == 0)
		{
			throw exception("Nothing to delete");
		}
		size_t t;
		for (size_t i = 0; i < size; i++)
		{
			if (table[i]->key == key)
			{
				t = i;
			}
			ct++;
		}
		for (size_t i = t + 1; i < size; i++)
		{
			ct++;
			table[i - 1] = table[i];
		}
		table[size - 1] = NULL;
		size--;
		cout << "Unordered delete " << ct << endl;
	}
	T find(int key)
	{
		size_t ct = 1;
		for (size_t i = 0; i < size; i++)
		{
			ct++;
			if (table[i]->key == key)
			{
				cout << "Unordered find " << ct << endl;
				return table[i]->data;
			}
		}
		throw exception("Cant find key");
	}
private:
	cellU<T>** table;
	size_t Msize, size;
};