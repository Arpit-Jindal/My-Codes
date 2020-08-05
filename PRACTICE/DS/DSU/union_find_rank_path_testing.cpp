#include<bits/stdc++.h>
using namespace std;
class disjSet {
public:
	int parent;
	int rank;
};
int find(disjSet* DJ, int i) {
	if (DJ[i].parent != i) {
		DJ[i].parent = find(DJ, DJ[i].parent);
	}
	return DJ[i].parent;
}
void Union(disjSet* DJ, int x, int y) {
	int xRoot = find(DJ, x);
	int yRoot = find(DJ, y);
	if (DJ[xRoot].rank > DJ[yRoot].rank) {
		DJ[yRoot].parent = DJ[xRoot].parent;
	} else if (DJ[xRoot].rank < DJ[yRoot].rank) {
		DJ[xRoot].parent = DJ[yRoot].parent;
	} else {
		DJ[yRoot].parent = DJ[xRoot].parent;
		DJ[xRoot].rank++;
	}
}
disjSet* makeSet (int n) {
	disjSet* DJ = new disjSet[n];
	for (int i = 0; i < n; i++) {
		DJ[i].parent = i;
		DJ[i].rank = 0;
	}
	return DJ;
}
int main() {
	disjSet* DJ = makeSet(10);
	Union(DJ, 0, 1);
	Union(DJ, 2, 3);
	Union(DJ, 1, 2);
	Union(DJ, 5, 6);
	Union(DJ, 3, 5);
	Union(DJ, 4, 6);
	Union(DJ, 0, 2);
	DJ[7].rank = 4;
	Union(DJ, 0, 7);
	DJ[8].rank = 5;
	DJ[9].rank = 6;
	Union(DJ, 7, 8);
	Union(DJ, 8, 9);

	cout << DJ[3].parent << endl;
	cout << DJ[0].parent << endl;
	cout << DJ[7].parent << endl;
	int x = find(DJ, 3);
	cout << DJ[3].parent << endl;
	cout << DJ[0].parent << endl;
	cout << DJ[7].parent << endl;
}