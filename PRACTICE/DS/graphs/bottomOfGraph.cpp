#include<bits/stdc++.h>
using namespace std;
void dfs1(map<int, vector<int>> g, int node, map<int, bool> &visited, stack<int> &finishedVertices) {
	visited[node] = true;
	for (int neighbour : g[node])
		if (!visited[neighbour])
			dfs1(g, neighbour, visited, finishedVertices);
	finishedVertices.push(node);
}
void dfs2(map<int, vector<int>> gT, int node, map<int, bool> &visited, set<int> &component) {
	visited[node] = true;
	component.insert(node);
	for (int neighbour : gT[node])
		if (!visited[neighbour])
			dfs2(gT, neighbour, visited, component);
}
set<set<int>> getSCC(map<int, vector<int>> g, map<int, vector<int>> gT) {
	stack<int> finishedVertices;
	map<int, bool> visited;
	for (auto i : g) {
		int node = i.first;
		if (!visited[node]) {
			dfs1(g, node, visited, finishedVertices);
		}
	}
	//We have our stack filled now
	visited.clear();
	set<set<int>> allComponents;

	while (!finishedVertices.empty()) {
		int node = finishedVertices.top();
		finishedVertices.pop();
		if (!visited[node]) {
			set<int> component;
			dfs2(gT, node, visited, component);
			allComponents.insert(component);
		}
	}
	return allComponents;
}
bool isValidBottom(int node, set<int> component, unordered_map<int, bool> &visited, map<int, vector<int>> g) {
	if (component.find(node) == component.end()) {
		return false;
	}
	visited[node] = true;
	for (auto neighbour : g[node]) {
		if (!visited[neighbour]) {
			bool a = isValidBottom(neighbour, component, visited, g);
			if (!a) return false;
		}
	}
	return true;
}
void printBottom(set<set<int>> allComponents, map<int, vector<int>> g) {
	set<set<int>> bottom;

	for (auto component : allComponents) {
		unordered_map<int, bool> visited;
		set<int>::iterator itr = component.begin(); //checking for only 1 element
		int node = *itr;
		if (isValidBottom(node, component, visited, g)) {
			bottom.insert(component);
		}
	}
	for (auto i = bottom.begin(); i != bottom.end(); i++) {
		for (auto j = (*i).begin(); j != (*i).end(); j++) {
			cout << *j + 1 << " ";
		}
		cout << endl;
	}
}
int main() {
	while (1) {
		int v; cin >> v;
		if (v == 0) break;
		int e; cin >> e;
		map<int, vector<int>> g;
		map<int, vector<int>> gT;
		for (int i = 0; i < e; i++) {
			int f, s;
			cin >> f >> s;
			g[f - 1].push_back(s - 1);
			gT[s - 1].push_back(f - 1);
		}
		set<set<int>> allComponents = getSCC(g, gT);
		printBottom(allComponents, g);
	}
}

/*
3 3
1 3 2 3 3 1
2 1
1 2
0
*/