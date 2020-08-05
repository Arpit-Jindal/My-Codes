#include<bits/stdc++.h>
using namespace std;
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
bool permutationPossible(unordered_set<unordered_set<int>*>* components, vector<int> P, vector<int> Q) {
	for (auto itr1 = components->begin(); itr1 != components->end(); itr1++) {
		unordered_set<int> s1;
		unordered_set<int> s2;
		for (auto itr2 = (*itr1)->begin(); itr2 != (*itr1)->end(); itr2++) {
			s1.insert(P[*itr2]);
			s2.insert(Q[*itr2]);
		}
		if (s1 != s2) return false;
	}
	return true;
}
int main() {

	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> P(n);
		vector<int> Q(n);
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			P[i] = a - 1;
		}
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			Q[i] = a - 1;
		}
		vector<int>* edges = new vector<int>[n];
		for (int i = 0; i < m; i++) {
			int f, s;
			cin >> f >> s;
			edges[f - 1].push_back(s - 1);
			edges[s - 1].push_back(f - 1);
		}
		unordered_set<unordered_set<int>*>* components = getComponents(edges, n);
		if (permutationPossible(components, P, Q)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		delete components;
		delete[] edges;
	}
}

/*
SAMPLE INPUT
2
4 1
1 3 2 4
1 4 2 3
3 4
4 1
1 3 2 4
1 4 2 3
2 4
SAMPLE OUTPUT
NO
YES

*/