#include<iostream>
#include<queue>
using namespace std;
int hasPathBFS(int **edges, int v, int sv, int ev) {
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
		for (int i = 0; i < v; i++) {
			if (!visited[i] && edges[current][i]) {
				if (i == ev) return 1;
				q.push(i);
				visited[i] = true;
			}
		}
	}
	delete[] visited;
	return 0;
}
int hasPathDFSHelper(int **edges, int v, bool* visited, int sv, int ev) {
	visited[sv] = true;
	for (int i = 0; i < v; i++) {
		if (!visited[i] && edges[sv][i]) {
			if (i == ev) return 1;
			int ans = hasPathDFSHelper(edges, v, visited, i, ev);
			if (ans) return 1;
		}
	}
	return 0;
}
int hasPathDFS(int **edges, int v, int sv, int ev) {
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}
	int ans = hasPathDFSHelper(edges, v, visited, sv, ev);
	return ans;
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
	int sv, ev;
	cin >> sv >> ev;
	cout << endl << "BFS: " << hasPathBFS(edges, v, sv, ev) ;
	cout << endl << "DFS: " << hasPathDFS(edges, v, sv, ev) ;
	for (int i = 0; i < v; i++) {
		delete[] edges[i];
	}
	delete[] edges;
}