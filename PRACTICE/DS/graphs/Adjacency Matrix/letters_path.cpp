#include<bits/stdc++.h>
using namespace std;

bool pathExistsHelper(char** graph, int n, int m, string str, int i, int j, int index) {
	int ans = str.length();
	if (ans == index) {
		return true;
	}
	if (i < 0 || i >= n || j < 0 || j >= m) {
		return false;
	}
	if (graph[i][j] == str[index]) {
		char temp = graph[i][j];
		graph[i][j] = '#';
		bool res = pathExistsHelper(graph, n, m, str, i,     j + 1, index + 1) ||
		           pathExistsHelper(graph, n, m, str, i + 1, j,     index + 1) ||
		           pathExistsHelper(graph, n, m, str, i,     j - 1, index + 1) ||
		           pathExistsHelper(graph, n, m, str, i - 1, j,     index + 1) ||
		           pathExistsHelper(graph, n, m, str, i + 1, j + 1, index + 1) ||
		           pathExistsHelper(graph, n, m, str, i - 1, j - 1, index + 1) ||
		           pathExistsHelper(graph, n, m, str, i + 1, j - 1, index + 1) ||
		           pathExistsHelper(graph, n, m, str, i - 1, j + 1, index + 1);
		graph[i][j] = temp;
		return res;
	} else {
		return false;
	}
}

bool pathExists(char** graph, int n, int m, string str) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == str[0])
				if (pathExistsHelper(graph, n, m, str, i, j, 0))
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
	string str = "CODINGNINJA";
	cout << pathExists(graph, n, m, str);

	for (int i = 0; i < n; i++) {
		delete[] graph[i];
	}
	delete[] graph;
}
/* input
2 11
CXDXNXNXNXA
XOXIXGXIXJX
*/