#include<iostream>
using namespace std;

int RC(int n, int p[], int i = 0)
{
	if (n == 0) 
		return 0;
	if (i + 1 <= n)
		return max(p[i] + RC(n - (i + 1), p, i), RC(n, p, i + 1));
	return 0;
}

// Bottom-Up
int RC(int n, int p[])
{
	int M[n + 1][n + 1];

	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0) 
				M[i][j] = 0;
			else if (i > j) 
				M[i][j] = M[i - 1][j];
			else
				M[i][j] = max(M[i - 1][j] , M[i][j - i] + p[i - 1]);
		}
	}
	return M[n][n];
}

int main()
{
	/*	int n=8;
		int p[] = {3, 5, 8, 9, 10, 17, 17, 20};  */

	int n = 5;
	int p[] = {2, 5, 7, 8, 0};
	cout << RC(n, p);
}