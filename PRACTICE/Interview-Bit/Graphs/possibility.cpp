#include<bits/stdc++.h>
using namespace std;
struct disjSet {
	int rank;
	int parent;
};
disjSet* makeSet(int n) {
	disjSet* DJ = new disjSet[n];
	for (int i = 0; i < n; i++) {
		DJ[i].rank = 0;
		DJ[i].parent = i;
	}
	return DJ;
}
int find(disjSet* DJ, int x) {
	if (DJ[x].parent != x) {
		DJ[x].parent = find(DJ, DJ[x].parent);
	}
	return DJ[x].parent;
}
void Union(disjSet* DJ, int x, int y) {
	int xParent = find(DJ, x);
	int yParent = find(DJ, y);
	if (DJ[xParent].rank > DJ[yParent].rank) {
		DJ[yParent].parent = xParent;
	}
	else if (DJ[xParent].rank < DJ[yParent].rank) {
		DJ[xParent].parent = yParent;
	}
	else {
		DJ[yParent].parent = xParent;
		DJ[xParent].rank ++;
	}
}
int solve(int A, vector<int> &B, vector<int> &C) {
	disjSet* DJ = makeSet(A + 1);
	for (int i = 0; i < B.size(); i++) {
		int x = find(DJ, B[i]);
		int y = find(DJ, C[i]);
		if (x == y) return 0;
		Union(DJ, x, y);
	}
	return 1;
}
int main() {
	vector<int> B = {1, 2, 3};
	vector<int> C = {2, 3, 1};
	cout << solve(3, B, C);
}