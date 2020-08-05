#include<iostream>
using namespace std;
void printpath(int path[][3], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << path[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
bool possible_path(int maze[][3], int n, int r, int c, int path[][3]) {

	if (r == n - 1 && c == n - 1) {
		path[r][c] = 1;
		printpath(path, n);
		return true;
	}
	if (r < 0 || r >= n || c < 0 || c >= n || maze[r][c] == 0 || path[r][c] == 1)
		//path[r][c]==1 means that we are on a already traversed cell
		return false;

	path[r][c] = 1;//We have considered the current cell on the path
	//Now we are looking for next cell

	if (possible_path(maze, n, r + 1, c, path)) {
		path[r][c] = 0;
		return true;
	}
	if (possible_path(maze, n, r, c + 1, path)) {
		path[r][c] = 0;
		return true;
	}

	path[r][c] = 0;
	return false;
}

void all_possible_path(int maze[][3], int n, int r, int c, int path[][3]) {

	if (r == n - 1 && c == n - 1) {
		path[r][c] = 1;
		printpath(path, n);
		return;
	}
	if (r < 0 || r >= n || c < 0 || c >= n || maze[r][c] == 0 || path[r][c] == 1)
		return ;

	path[r][c] = 1;
	all_possible_path(maze, n, r + 1, c, path); //right
	all_possible_path(maze, n, r, c + 1, path); //down
	path[r][c] = 0;
}
int main()
{
	int maze[3][3] =
	{
		{1, 1, 0},
		{1, 1, 0},
		{0, 1, 1}
	};
	int path[3][3] = {0};
	// cout << possible_path(maze, 3, 0, 0, path);
	all_possible_path(maze, 3, 0, 0, path);
}