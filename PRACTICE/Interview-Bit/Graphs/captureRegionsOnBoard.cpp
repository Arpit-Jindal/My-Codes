#include<bits/stdc++.h>
using namespace std;
int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};
void dfs(vector<vector<char>> &A, vector<vector<bool>> &visited, int n, int m, int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || A[i][j] != 'O' ) return;
	visited[i][j] = true;
	for (int k = 0; k < 4; k++)
		dfs(A, visited, n, m, i + X[k], j + Y[k]);
}
void Solution::solve(vector<vector<char>> &A) {
	int n = A.size();
	int m = A[0].size();
	vector<vector<bool>> visited (n, vector<bool>(m, 0));
	int i = 0;
	int k = 0;
	int count = 0;
	while (count < 2) {
		count++;
		//for top and bottom boundary
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && A[i][j] == 'O')
				dfs(A, visited, n, m, i, j);
		}
		//for left and right boundary
		for (int j = 0; j < n; j++) {
			if (!visited[j][k] && A[j][k] == 'O')
				dfs(A, visited, n, m, j, k);
		}
		i += n - 1;
		k += m - 1;
	}
	for (int x = 0; x < n; x++) {
		for (int j = 0; j < m; j++) {
			if (!visited[x][j] && A[x][j] == 'O')
				A[x][j] = 'X';
		}
	}
}
int main() {
	vector<vector<char>> A = {
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X'}
	};
	solve(A);
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}