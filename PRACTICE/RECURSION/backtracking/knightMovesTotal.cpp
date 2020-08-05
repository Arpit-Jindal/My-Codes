#include <iostream>
#include <iomanip>
using namespace std;
const int D = 8;

bool canPlace(int board[D][D], int n, int r, int c) {
	return
	    r >= 0 && r < n &&
	    c >= 0 && c < n &&
	    board[r][c] == 0;
}

void printBoard(int board[D][D], int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << setw(3) << board[i][j] << " ";
		}
		cout << endl;
	}
}
bool solveKnightMove(int board[D][D], int n, int move_no, int curRow, int curCol) {
	if (move_no == n * n) {
		printBoard(board,n);
		cout<<"============================\n";
		return true;
	}

	static int rowDir[] = { +2, +1, -1, -2, -2, -1, +1, +2};
	static int colDir[] = { +1, +2, +2, +1, -1, -2, -2, -1};
	for (int curDir = 0; curDir < 8; ++curDir)
	{
		int nextRow = curRow + rowDir[curDir];
		int nextCol = curCol + colDir[curDir];
		if (canPlace(board, n, nextRow, nextCol))
		{
			board[nextRow][nextCol] = move_no + 1; // place the knight
			solveKnightMove(board, n, move_no + 1, nextRow, nextCol);
			board[nextRow][nextCol] = 0;    // erase the knight - backtracking 
		}
	}
	return false;
}


int main() {
	int board[D][D] = {0};
	int n; cin >> n;
	board[0][0] = 1;

	solveKnightMove(board, n, 1, 0, 0);
}