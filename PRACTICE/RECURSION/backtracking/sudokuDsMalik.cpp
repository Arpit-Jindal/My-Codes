#include<iostream>
using namespace std;

class sudoku
{
	int grid[9][9];
public:
	sudoku()
	{
		grid[9][9] = {0};
	}
	sudoku(int g[9][9])
	{
		grid[9][9] = g[9][9];
	}
	void initializeSudokuGrid()
	{

	}
	void initializeSudokuGrid(int g[][9])
	{

	}
	void printSudokuGrid()
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << grid[i][j] << "  ";
			}
			cout << endl;
		}
	}
	bool solveSudoku()
	{
		int row, col;
		if (findEmptyGridSlot(row, col))
		{
			for (int num = 1; num <= 9; num++)
			{
				if (canPlaceNum(row, col, num))
				{
					grid[row][col] = num;
					if (solveSudoku())return true;
					grid[row][col] = 0;
				}
			}
			return false;
		}
		else return true;
	}
	bool findEmptyGridSlot(int &row, int &col)
	{

	}
	bool canPlaceNum(int row, int col, int num)
	{

	}
	bool numAlreadyInRow(int row, int num)
	{

	}
	bool numAlreadyInCol(int col, int num)
	{

	}
	bool numAlreadyInBox(int smallGridRow, int smallGridCol, int num)
	{

	}
};

int main()
{

}