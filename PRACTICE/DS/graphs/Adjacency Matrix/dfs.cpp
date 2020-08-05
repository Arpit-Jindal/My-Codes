#include<iostream>
using namespace std;

void printdfs(int **edges, int v, int sv, bool* visited) {
	cout << sv << "->";
	visited[sv] = true;
	for (int i = 0; i < v; i++) {
		if (visited[i] == false && edges[sv][i] == 1) {
			printdfs(edges, v, i, visited);
		}
	}
}
int main() {
	int v, e;
	cin >> v >> e;
	int **edges = new int* [v];

	for (int i = 0; i < v; i++) {
		edges[i] = new int[v];
		for (int j = 0; j < v; j++) {
			edges[i][j] = 0;
		}
	}
	int f, s;
	for (int i = 0; i < e; i++) {
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	bool *visited  = new bool[v];
	for (int i = 0; i < v; i++) {
		visited[i] = false;
	}
	printdfs(edges, v, 0, visited);

	//delete dynamic arrays
	for (int i = 0; i < v; i++) {
		delete[] edges[i];
	}
	delete[] edges;
	delete[] visited;
}