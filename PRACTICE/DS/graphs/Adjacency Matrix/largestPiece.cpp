#include<bits/stdc++.h>
using namespace std;
void printGraph(int**graph, int n) {
	cout << "-----------------------------------------------------------\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j] << " " ;
		}
		cout << endl;
	}
	cout << "-----------------------------------------------------------\n";
}
void largestPieceHelper(int **graph, int n, int i, int j, int& count) {
	if (i < 0 || i >= n || j < 0 || j >= n) {
		return;
	}
	if (graph[i][j] == 1) {
		count++;
		graph[i][j] = '#';
		largestPieceHelper(graph, n, i + 1, j, count);
		largestPieceHelper(graph, n, i, j + 1, count);
		largestPieceHelper(graph, n, i - 1, j, count);
		largestPieceHelper(graph, n, i, j - 1, count);
	} else {
		return;
	}
}
int largestPiece(int** graph, int n) {
	int maxPiece = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int count = 0;
			if (graph[i][j] == 1) {
				largestPieceHelper(graph, n, i , j, count);
				printGraph(graph, n);
				if (count > maxPiece) {
					maxPiece = count;
				}
			}
		}
	}
	return maxPiece;
}

int main() {
	int n;
	cin >> n;
	int** graph = new int*[n];
	for (int i = 0; i < n; i++) {
		graph[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	cout << largestPiece(graph, n) << endl;
	// printGraph(graph, n);
	for (int i = 0; i < n; i++) {
		delete[] graph[i];
	}
	delete[] graph;
}
/* input
4
1 1 1 1
0 0 0 0
1 1 1 1
0 0 1 1
*/