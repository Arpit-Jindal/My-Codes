#include<bits/stdc++.h>
using namespace std;

//we want to pass singleComponent by reference thus we are using its reference (*).
//this is because if we pass by value then after returning from function calls the singleComponent will become empty
//pass by reference ensures once a node is added, its not removed from singleComponent

void dfs(vector<int>* edges, int start, unordered_set<int>* singleComponent, bool* visited) {
	visited[start] = true;
	singleComponent->insert(start);
	for (auto next : edges[start]) {
		if (!visited[next]) {
			dfs(edges, next, singleComponent, visited);
		}
	}
}
unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, int n) {
	bool* visited = new bool[n]();
	unordered_set<unordered_set<int>*>* components = new unordered_set<unordered_set<int>*>;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			unordered_set<int>* singleComponent = new unordered_set<int>;
			dfs(edges, i, singleComponent, visited);
			components->insert(singleComponent);
		}
	}
	delete[] visited;
	return components;
}
int main() {
	int n; cin >> n;
	vector<int>* edges = new vector<int>[n];
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int f, s;
		cin >> f >> s;
		edges[f - 1].push_back(s - 1);
		edges[s - 1].push_back(f - 1);
	}
	unordered_set<unordered_set<int>*>* components = getComponents(edges, n);

	for (auto itr1 = components->begin(); itr1 != components->end(); itr1++) {
		for (auto itr2 = (*itr1)->begin(); itr2 != (*itr1)->end(); itr2++) {
			cout << *itr2 + 1 << " ";
		}
		cout << endl;
	}
	delete components;
	delete[] edges;
}
/* input
6
5
1 2
1 4
2 3
3 4
5 6
*/