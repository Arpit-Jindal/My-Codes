//https://ide.codingblocks.com/s/198844
//We have to minimize the transactions
//O(nlogn)
#include<bits/stdc++.h>
using namespace std;
class person_compare {
public:
	bool operator()(pair<string, int> p1, pair<string, int> p2) {
		return p1.second < p2.second;
	}
};
int main() {
	int noOfTransactions, friends;
	cin >> noOfTransactions >> friends;

	string x, y;
	int amount;

	//map to store the net amount for each friend
	map<string, int> net;

	while (noOfTransactions--) {
		//"x" has to pay "y" amount "amount"
		cin >> x >> y >> amount;
		if (net.count(x) == 0)
			net[x] = 0;
		if (net.count(y) == 0)
			net[y] = 0;
		net[x] -= amount;
		net[y] += amount;
	}
	//we use multiset bcz we compare using pair.second and it can be same among many friends
	//If we use set and compare by pair.second, only one unique value of pair.second will be allowed
	multiset<pair<string, int>, person_compare> m;

	//Iterate over the persons, add those person in the multiset who have non zero net
	for (auto p : net) {
		string person = p.first;
		int amount = p.second;
		if (amount != 0) m.insert({person, amount});
	}

	//Now we have our multiset with all the net amount which is sorted
	//settlements (start & end)
	int count = 0;
	while (!m.empty()) {
		auto low = m.begin();
		auto high = prev(m.end());

		string person_debit = low->first;
		string person_credit = high->first;
		int debit = low->second;
		int credit = high->second;

		//Pop them out
		m.erase(low);
		m.erase(high);

		int settlement_amount = min(-debit, credit);
		count++;

		debit += settlement_amount;
		credit -= settlement_amount;

		//Print the transaction
		cout << person_debit << " pays " << person_credit << " " << settlement_amount << endl;

		//New data (if any) to be inserted in multiset
		if (debit != 0) {
			m.insert({person_debit, debit});
		}
		if (credit != 0) {
			m.insert({person_credit, credit});
		}
	}
	cout << "No Of Transactions = " << count << endl;
}

/* input
3 3
rahul ajay 100
ajay neha 50
neha rahul 40
*/