#include<bits/stdc++.h>
using namespace std;
bool isCycleHelper(char** graph, int n, int m, int i, int j, int origin_i, int origin_j, char dot, int count) {
	if (i < 0 || i >= n || j < 0 || j >= m) {
		return false;
	}
	if (origin_j == j - 1 && origin_i == i && graph[i][j] == dot && count >= 4) return true;
	if (graph[i][j] == dot) {
		char temp = graph[i][j];
		graph[i][j] = '#';
		bool res = isCycleHelper(graph, n, m, i + 1, j, origin_i, origin_j, dot, count + 1) ||
		           isCycleHelper(graph, n, m, i, j + 1, origin_i, origin_j, dot, count + 1) ||
		           isCycleHelper(graph, n, m, i - 1, j, origin_i, origin_j, dot, count + 1) ||
		           isCycleHelper(graph, n, m, i, j - 1, origin_i, origin_j, dot, count + 1) ;
		graph[i][j] = temp;
		return res;
	} else {
		return false;
	}
}
bool isCycle(char** graph, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (isCycleHelper(graph, n, m, i, j, i, j, graph[i][j], 1))
				return true;
			}
	}
	return false;
}
int main() {
	int n, m;
	cin >> n >> m;
	char** graph = new char*[n];
	for (int i = 0; i < m; i++) {
		graph[i] = new char[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	cout << isCycle(graph, n, m);
	for (int i = 0; i < n; i++) {
		delete[] graph[i];
	}
	delete[] graph;
}
/* input
3 4
AAAA
ABCA
AAAA
*/