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
			table[i] = nullptr;
		}
	}
	void add(T data, int key)
	{
		if (Msize == size)
		{
			throw exception("Low memory");
		}
		cellH<T>* t = new cellH<T>(data, key);
		table[key % Msize] = t;
		size++;
		cout << "Hash add " << 1 << endl;
	}
	T find(int key)
	{
		if (table[key % Msize] == nullptr)
		{
			throw exception("Cant find key");
		}
		cout << "Hash find " << 1 << endl;
		return table[key % Msize]->data;
	}
	void del(int key)
	{
		if ((size == 0) || (table[key % Msize] == nullptr))
		{
			throw exception("Nothing to delete");
		}
		table[key % Msize] = nullptr;
		size--;
		cout << "Hash delete " << 1 << endl;
	}
	size_t get_size()
	{
		return size;
	}
private:
	cellH<T>** table;
	size_t Msize, size;
};