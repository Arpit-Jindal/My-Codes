#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void printVector(vector<vector<int>> v) {
	cout << endl << "[ ";
	for (int i = 0; i < v.size(); i++) {
		cout << "( ";
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << ",";
		}
		cout << ") , ";
	}
	cout << " ]" << endl;
}
vector<int> findComponentsBFS(int **edges, int v, bool* visited, int sv, vector<int> smallVec) {
	queue<int> q;
	q.push(sv);
	visited[sv] = true;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		smallVec.push_back(current);
		for (int i = 0; i < v; i++) {
			if (!visited[i] && edges[current][i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return smallVec;
}
vector<int> findComponentsDFS(int **edges, int v, bool* visited, int sv, vector<int>& smallVec) {
	visited[sv] = true;
	smallVec.push_back(sv);
	for (int i = 0; i < v; i++) {
		if (!visited[i] && edges[sv][i]) {
			vector<int> tempVec = findComponentsDFS(edges, v, visited, i, smallVec);
		}
	}
	return smallVec;
}
void DFS(int **edges, int v) {
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}
	vector<vector<int>> bigVec;

	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			vector<int> smallVec;
			bigVec.push_back(findComponentsDFS(edges, v, visited, i, smallVec));
		}
	}
	delete[] visited;
	printVector(bigVec);
}
void BFS(int **edges, int v) {
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}
	vector<vector<int>> bigVec;

	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			vector<int> smallVec;
			bigVec.push_back(findComponentsBFS(edges, v, visited, i, smallVec));
		}
	}
	delete[] visited;
	printVector(bigVec);
}
int main() {
	int v, e;
	cin >> v >> e;
	int **edges = new int*[v];
	for (int i = 0; i < v; i++) {
		edges[i] = new int[v];
		for (int j = 0; j < v; j++) {
			edges[i][j] = 0;
		}
	}
	int f, s;
	for (int i = 0; i < e; i++) {
		cin >> f >> s;
		edges[f][s] = edges[s][f] = 1;
	}
	cout << "BFS: ";
	BFS(edges, v);
	cout << "DFS: ";
	DFS(edges, v);
	for (int i = 0; i < v; i++) {
		delete[] edges[i];
	}
	delete[] edges;
}