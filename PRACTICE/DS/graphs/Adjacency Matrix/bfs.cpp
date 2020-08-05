#include<iostream>
#include<queue>
using namespace std;
void printbfs(int **edges, int v, int sv = 0) {
	queue<int> q;
	q.push(sv);
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}
	visited[sv] = true;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		cout << current << "->";
		for (int i = 0; i < v; i++) {
			if (!visited[i] && edges[current][i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
	delete[] visited;
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
	printbfs(edges, v);
	for (int i = 0; i < v; i++) {
		delete[] edges[i];
	}
	delete[] edges;
}