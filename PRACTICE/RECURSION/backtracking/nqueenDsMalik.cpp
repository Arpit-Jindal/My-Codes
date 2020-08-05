#include<iostream>
#include<cmath>
using namespace std;

class nQueensPuzzle
{
	int noOfSolutions;
	int noOfQueens;
	int* queensInRow;
public:
	nQueensPuzzle(int queens = 8)
	{
		noOfQueens = queens;
		queensInRow = new int[noOfQueens];
		noOfSolutions = 0;
	}
	bool canPlaceQueen(int k, int i)
	{
		for (int j = 0; j < k; j++)
		{
			if ((queensInRow[j] == i) || (abs(queensInRow[j] - i) == abs(j - k))) return false;
		} 
		return true;
	}
	void queensConfiguration(int k)
	{
		for (int i = 0; i < noOfQueens; i++)
		{
			if (canPlaceQueen(k, i))
			{
				queensInRow[k] = i;
				if (k == noOfQueens - 1) printConfiguration();
				else queensConfiguration(k + 1);
			}
		}
	}
	void printConfiguration()
	{
		noOfSolutions++;
		cout << "(";
		for (int i = 0; i < noOfQueens - 1; i++)
		{
			cout << queensInRow[i] << ", ";
		}
		cout << queensInRow[noOfQueens - 1] << ")" << endl;
	}
	int solutionsCount()
	{
		return noOfSolutions;
	}
};

int main()
{
	nQueensPuzzle q;
	q.queensConfiguration(0);
}
