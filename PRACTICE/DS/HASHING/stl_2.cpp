#include<iostream>
#include<unordered_map>
using namespace std;
class Fruit
{
public:
	int price;
	string name;
	string city;
	Fruit() {}
	Fruit(string n, int p, string c)
	{
		name = n;
		price = p;
		city = c;
	}
};

int main()
{
	unordered_map<string, Fruit> myMap;
	Fruit F("Mango", 100, "Delhi");

	myMap[F.name] = F;
	Fruit fs = myMap["Mango"];
	cout << fs.city << endl;
	cout << fs.price << endl;
	cout << fs.name << endl;

	cout << "Apple " << myMap.count("Apple") << endl;
	cout << "Mango " << myMap.count("Mango") << endl;
	myMap.erase("Mango");
	cout << "Mango " << myMap.count("Mango") << endl;

	cout << "Enter a fruit to search : "; string fruit; cin >> fruit;

	if (myMap.count(fruit) != 0) cout << "Price: " << myMap[fruit].price << endl;
	else cout << "NOT PRESENT" << endl;

}