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
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 0)
				cout << setw(3) << "_";
			else
				cout << setw(3) << "Q" ;
		}
		cout << endl;
	}
}
bool Solve(int board[D][D], int r, int n)
{
	if (r == n)
	{
		//Successfully placed queens in (0....n-1) rows;
		print(board, n);
		return true; // return false to print all the possible solutions
	}
	//Recursive Case
	//Try to place the queen in the current row and call on the remaining part which will be solved by recursion
	for (int c = 0; c < n; c++)
	{
		//Check whether (r,c) th position is safe to place the queen or not
		if (isSafe(board, r, c, n))
		{
			//Place the queen - assuming r,c is the right position
			board[r][c] = 1;
			if (Solve(board, r + 1, n))
				return true; // this will not execute while printing all possible solutions

			//Assumption proven wrong i.e. r,c is incorrect position
			board[r][c] = 0;
		}
	}
	//You have tried for all positions in the current row but are unable to place the queen
	return false;
}
int main()
{
	int n;
	cout << "Enter no of rows: ";
	cin >> n;
	int board[D][D] = {0};
	Solve(board, 0, n);
}
