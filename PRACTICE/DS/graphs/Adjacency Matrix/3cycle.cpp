#include<bits/stdc++.h>
using namespace std;
int distinct3Cycle(int** graph, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (graph[i][j]) {
				for (int k = j + 1; k < n; k++) {
					if (graph[j][k] && graph[k][i]) {
						count++;
					}
				}
			}
		}
	}
	return count;
}
int main() {
	int n, m;
	cin >> n >> m;
	int *u = new int[m];
	int *v = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> u[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}
	int **graph = new int* [n];
	for (int i = 0; i < n; i++) {
		graph[i] = new int[n];
		for (int j = 0; j < n; j++) {
			graph[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		graph[u[i] - 1][v[i] - 1] = 1;
		graph[v[i] - 1][u[i] - 1] = 1;
	}
	cout << distinct3Cycle(graph, n);
	for (int i = 0; i < n; i++) {
		delete[] graph[i];
	}
	delete[] graph;
	delete[] u;
	delete[] v;
}
/* input
5 7
1 1 1 2 2 2 4
2 3 4 4 5 3 5
*/