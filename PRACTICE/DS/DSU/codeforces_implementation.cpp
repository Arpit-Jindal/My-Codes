#include<bits/stdc++.h>
using namespace std;
class DSU {
public:
	vector<int> parent;
	DSU(int n): parent(n) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	void join(int a, int b) {
		parent[find(b)] = find(a);
	}
	int find(int a) {
		return a == parent[a] ? a : parent[a] = find(parent[a]);
	}
	bool check(int a, int b) {
		return find(a) == find(b);
	}
};
int main() {

}