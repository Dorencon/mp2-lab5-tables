#include <algorithm>

using namespace std;

template <typename T>
struct cellO
{
	int key;
	T data;
	cellO<T> *left, *right, *parent;
	int h;
	cellO(T d, int k)
	{
		data = d;
		key = k;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
	cellO(){}
};

template <typename T>
size_t get_h(cellO<T>* t)
{
	if (t == NULL)
	{
		return 0;
	}
	return t->h;
}

template <typename T>
class Ordered
{
public:
	Ordered()
	{
		first = NULL;
	}
	void rotateL(cellO<T>* t)
	{
		if (t->parent != NULL)
		{
			if (t->parent->left == t)
			{
				t->parent->left = t->right;
			}
			else
			{
				t->parent->right = t->right;
			}
		}
		t->right->parent = t->parent;
		t->parent = t->right;
		cellO<T>* temp = t->right->left, *tmp = t->right;
		t->right->left = t;
		t->right = temp;
		t->h = max(get_h(t->left), get_h(t->right)) + 1;
		tmp->h = max(get_h(tmp->left), get_h(tmp->right)) + 1;
	}
	void rotateR(cellO<T>* t)
	{
		if (t->parent != NULL)
		{
			if (t->parent->left == t)
			{
				t->parent->left = t->left;
			}
			else
			{
				t->parent->right = t->left;
			}
		}
		t->left->parent = t->parent;
		t->parent = t->left;
		cellO<T>* temp = t->left->left, *tmp = t->left;
		t->left->left = t;
		t->left = temp;
		t->h = max(get_h(t->left), get_h(t->right)) + 1;
		tmp->h = max(get_h(tmp->left), get_h(tmp->right)) + 1;
	}
	void add(int key, T data)
	{
		if (first == NULL)
		{
			cout << "Ordered add " << 1 << endl;
			cellO<T>* t = new cellO<T>(data, key);
			first = t;
			return;
		}
		size_t ct = 1;
		bool r;
		cellO<T> *t = first, *p = NULL;
		while (t != NULL)
		{
			ct++;
			p = t;
			if (key > t->key)
			{
				r = 1;
				t = t->right;
			}
			else
			{
				r = 0;
				t = t->left;
			}
		}
		ct++;
		t = new cellO<T>(data, key);
		if (p != NULL)
		{
			t->parent = p;
			if (r)
			{
				p->right = t;
			}
			else
			{
				p->left = t;
			}
		}
		ct += this->rebalance(t);
		cout << "Ordered add " << ct << endl;
	}
	size_t rebalance(cellO<T>* t)
	{
		size_t ct = 1;
		while (t != NULL)
		{
			ct++;
			int hh = get_h(t->right) - get_h(t->left);
			if (abs(hh) >= 2)
			{
				if (hh > 0)
				{
					if (get_h(t->right->left) - get_h(t->right->right) == 1)
					{
						this->rotateL(t);
					}
					else
					{
						this->rotateR(t->right);
						this->rotateL(t);
					}
				}
				else
				{
					if (get_h(t->left->right) - get_h(t->left->left) == 1)
					{
						this->rotateR(t);
					}
					else
					{
						this->rotateL(t->left);
						this->rotateR(t);
					}
				}
			}
			t->h = max(get_h(t->right), get_h(t->left)) + 1;
			t = t->parent;
		}
		return ct;
	}
	void del(int key)
	{
		size_t ct = 1;
		cellO<T> *t = first;
		while ((t != NULL) && (t->key != key))
		{
			ct++;
			if (key > t->key)
			{
				t = t->right;
			}
			else
			{
				t = t->left;
			}
		}
		if (t != NULL)
		{
			if (t == first)
			{
				first = NULL;
				cout << "Ordered delete " << 1 << endl;
				return;
			}
			cellO<T> *p = t->parent, *l = t->left;
			t = t->right;
			cellO<T> *temp;
			while (t != NULL)
			{
				ct++;
				temp = t->left;
				t->left = l;
				l->parent = t;
				l = temp;
				t->parent = p;
				p = t;
				if ((t->right == NULL) && (l != NULL))
				{
					t->right = l;
					break;
				}
				t = t->right;
			}
			ct += this->rebalance(p);
		}
		else
		{
			throw exception("Nothing to delete");
		}
		cout << "Ordered delete " << ct << endl;
	}
	T find(int key)
	{
		size_t ct = 1;
		cellO<T>* t = first;
		while ((t != NULL) && (t->key != key))
		{
			ct++;
			if (key > t->key)
			{
				t = t->right;
			}
			else
			{
				t = t->left;
			}
		}
		if (t == NULL)
		{
			throw exception("Cant find key");
		}
		cout << "Ordered find " << ct << endl;
		return t->data;
	}
private:
	cellO<T>* first;
};