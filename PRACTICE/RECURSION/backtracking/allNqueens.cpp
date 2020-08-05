#include<iostream>
#include<iomanip>
using namespace std;
const int D = 8;
bool isSafe(int board[D][D], int r, int c, int n) {
	//column (upwards)
	for (int i = 0; i < r; i++)
		if (board[i][c] != 0)
			return false;

	//left diagnol (upwards)
	int x = r;
	int y = c;
	while (x >= 0 && y >= 0){
		if (board[x][y] != 0)
			return false;
		x--;
		y--;
	}
	//right diagnol (upwards)
	x = r;
	y = c;
	while (x >= 0 && y < n) {
		if (board[x][y] != 0)
			return false;
		x--;
		y++;
	}
	return true;

}
void print(int board[D][D], int n)
{
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (board[i][j] == 0)
				cout << setw(3) << "_";
			else
				cout << setw(3) << "Q" ;
		}
		cout << endl;
	}
}
void all_nqueens(int board[][D], int row, int n) {
	if (row == n) {
		print(board, n);
		cout << "\n=========================================\n";
		return;
	}
	for (int col = 0; col < n; col++) {
		if (isSafe(board, row, col, n)) {
			board[row][col] = 1;
			all_nqueens(board, row + 1, n);
			board[row][col] = 0;
		}
	}
}
int main(){
	int n;
	cout << "Enter no of rows: ";
	cin >> n;
	int board[D][D] = {0};
	all_nqueens(board, 0, n);
}
