//Assuming a connected graph
#include<bits/stdc++.h>
using namespace std;
bool isBipartite(unordered_map<int, vector<int>> edges) {
	unordered_set<int> sets[2];
	vector<int> pending;
	unordered_map<int, vector<int>>::iterator itr = edges.begin();
	int any_node = (*itr).first;
	sets[0].insert(any_node); //first insert element in the set
	pending.push_back(any_node); // then push it in queue(here vector)
	while (pending.size() > 0) {
		int current = pending.back();
		pending.pop_back();
		int currentSet = sets[0].count(current) > 0 ? 0 : 1; //either in 0 or 1
		for (auto neighbor : edges[current]) {
			if (sets[0].count(neighbor) == 0 && sets[1].count(neighbor) == 0) { //present in none of the two sets
				//insert to the opposite set
				sets[1 - currentSet].insert(neighbor);
				pending.push_back(neighbor);
			} else if (sets[currentSet].count(neighbor) != 0 ) { //already present in the current set
				return false;
			}
		}
	}
	return true;
}
int main() {
	while (1) {
		int v; cin >> v;
		if (v == 0) break;
		int e; cin >> e;
		unordered_map<int, vector<int>> edges;
		for (int i = 0; i < e; i++) {
			int f, s;
			cin >> f >> s;
			edges[f].push_back(s);
			edges[s].push_back(f);
		}
		if (isBipartite(edges)) {
			cout << "YES";
		} else {
			cout << "NO";
		}
	}
}
/* input
5
5
0 1
1 2
2 3
3 4
4 0

4
4
0 1
1 3
2 3
0 2

*/