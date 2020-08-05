//TODO : Correct it, error is coming in codechef submisssion
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
	if (xRoot == yRoot) return;
	if (DJ[xRoot].rank > DJ[yRoot].rank) {
		DJ[yRoot].parent = xRoot;
	} else if (DJ[xRoot].rank < DJ[yRoot].rank) {
		DJ[xRoot].parent = yRoot;
	} else {
		DJ[yRoot].parent = xRoot;
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
bool isBipartite(map<int, vector<int>> edges) {
	if (edges.size() == 0)return true;
	unordered_set<int> sets[2];
	vector<int> pending;
	map<int, vector<int>>::iterator itr = edges.begin();
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
bool makeComponents(map<pair<int, int>, int> matrix, int n, map<int, vector<int>> &graph) {
	disjSet* DJ = makeSet(n + 1);
	for (auto itr = matrix.begin(); itr != matrix.end(); itr++) {
		pair<int, int> i = (*itr).first;
		int j = (*itr).second;
		if (j == 0) {
			Union(DJ, i.first , i.second);
		}
	}
	for (auto itr = matrix.begin(); itr != matrix.end(); itr++) {
		pair<int, int> i = (*itr).first;
		int j = (*itr).second;
		if (j == 1) {
			if (find(DJ, i.first) == find(DJ, i.second)) {
				return false;
			}
			graph[i.first].push_back(i.second);
			graph[i.second].push_back(i.first);
		}
	}
	return true;
}
void printMatrix(map<pair<int, int>, int> m) {
	cout << "Matrix: \n";
	for (auto i = m.begin(); i != m.end(); i++) {
		cout << (*i).first.first << "," << (*i).first.second << "->" << (*i).second << endl;
	}
}
void printGraph(map<int, vector<int>> graph) {
	cout << "Graph: \n";
	for (auto i = graph.begin(); i != graph.end(); i++) {
		cout << (*i).first << "->";
		for (auto x : (*i).second) {
			cout << x << " ";
		}
		cout << endl;
	}
}
int main() {
	int t; cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		int error = false;
		map<pair<int, int>, int> matrix;
		for (int i = 0; i < q; i++) {
			int f, s, val;
			cin >> f >> s >> val;
			if (f == s && val != 0) error = true;
			else if (matrix.find({s, f}) != matrix.end() && matrix[ {s, f}] != val) {
				error = true;
			}
			if (!error) matrix[ {f, s}] = val;
		}
		if (error) {
			cout << "no" << endl;
			continue;
		}
		printMatrix(matrix);
		map<int, vector<int>> graph;
		if (!makeComponents(matrix, n, graph)) {
			cout << "no" << endl;
			continue;
		}
		printGraph(graph);
		if (isBipartite(graph)) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
}
/* input
4
2 2
1 1 0
1 2 1
2 3
1 1 0
1 2 1
2 1 0
3 2
2 2 0
2 3 1
3 3
1 2 1
2 3 1
1 3 1
*/