#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
	unordered_map<string, int> myMap;

	myMap["Mango"] = 100;
	myMap["Banana"] = 20;
	myMap["leechi"] = 250;

	myMap.insert(make_pair("Apple", 120));

	pair<string, int> p("Guava", 130);
	myMap.insert(p);

	for (auto node : myMap) // auto here is pair<string,int>
	{
		cout << node.first << "," << node.second << endl;
	}

	//Buckets iteration
	for (int i = 0; i < myMap.bucket_count(); i++)
	{
		cout << "Bucket " << i << "->";
		//iterate over every linked list
		for (auto it = myMap.begin(i); it != myMap.end(i); it++)
		{
			//it is a pointer to a pair
			cout << it->first << "," << it->second;
		}
		cout << endl;
	}
}