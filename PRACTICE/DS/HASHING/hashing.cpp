#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class node
{
public:
	string key;
	T value;
	node<T> *next;

	node(string k, T v)
	{
		key = k;
		value = v;
	}
	~node()
	{
		if (next != NULL)
			delete next; //recursive destructor call to avoid memory leak
	}
};

template<typename T>
class hashtable
{
	int cs; //current size
	int ts; //total size
	node<T>** buckets;

	int hashfn(string key)
	{
		int L = key.length();
		int ans = 0;
		int p = 1;

		for (int i = 0; i < L; i++)
		{
			ans += key[L - i - 1] * p;
			p = p * 37;

			p = p % ts;
			ans = ans % ts;
		}
		return ans;
	}

	void rehash()
	{
		node<T>** oldBuckets = buckets;
		int oldTs = ts;
		ts = ts * 2;
		cs = 0;
		buckets = new node<T>*[ts]; //new bucket

		for (int i = 0; i < ts; i++)
			buckets[i] = NULL;

		//Read the elements from old table and insert them into new table
		for (int i = 0; i < oldTs; i++)
		{
			node<T>* temp = oldBuckets[i];
			if (temp != NULL)
			{
				while (temp != NULL)
				{
					insert(temp->key, temp->value);
					temp = temp->next;
				}
				//Delete the old table i bucket linked list
				delete oldBuckets[i];
			}
		}
		delete [] oldBuckets;

	}
public:
	hashtable(int ds = 7) //default size
	{
		cs = 0;
		ts = ds;
		buckets = new node<T>*[ts];

		for (int i = 0; i < ts; i++)
			buckets[i] = NULL;
	}
	void insert(string key, T value)
	{
		//Key i need the hash index
		int i = hashfn(key);

		node<T>* n = new node<T> (key, value);
		//chaining by insertion at head
		n->next = buckets[i];
		buckets[i] = n;

		cs++;
		float loadFactor = (float) cs / ts;
		if (loadFactor > 0.7)
		{
			cout << "Load Factor is " << loadFactor << endl;
			rehash();
		}
	}

	void print()
	{
		for (int i = 0; i < ts; i++)
		{
			node<T>* temp = buckets[i];
			cout << "Bucket " << i << "->";
			while (temp != NULL)
			{
				cout << temp->key << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	T* search (string key)
	{
		int i = hashfn(key);
		node<T>* temp = buckets[i];
		while (temp != NULL)
		{
			if (temp->key == key) return &(temp->value);
			temp = temp->next;
		}
		return NULL;
	}

	void erase(string key)
	{
		int i = hashfn(key);
		node<T>* temp = buckets[i];
		node<T>* prev = temp;
		while (temp != NULL)
		{
			if (temp->key == key)
			{
				if (prev == temp) //key at root
					buckets[i] = temp->next;
				else
					prev->next = temp->next;
				temp->next = NULL;
				delete temp;
				return;
			}
			prev = temp;
			temp = temp->next;
		}
	}

	T& operator[] (string key)
	{
		T* temp = search(key);
		if (temp == NULL) //Insertion
		{
			T garbage;
			insert (key, garbage);

			T* value = search(key); //search again to find where the key has been inserted
			return *value; //returns the box of garbage by reference
		}
		//else return the box (update/search functionality)
		return *temp;
	}
};

int main()
{
	hashtable<int> H(7);
	H.insert("Mango", 100);



	H["Apple"] = 120; //Insert
	H["Mango"] = 140; //Update
	H.print();

	cout << H["Mango"] << endl; //Search


	// string f; cin >> f;
	// int* price = H.search(f);
	// if (price) cout << *price;
	// else cout << "NOT FOUND";

	// string f; cin >> f;
	// H.erase(f);
	// H.print();

}