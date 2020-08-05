//Wrong
#include<iostream>
#include<vector>
using namespace std;
vector<int> ans;
int goldMine(int mat[4][4], int x, int y = 0) {

	if (x < 0 || x >= 4 || y >= 4)return 0;

	int ans1 = (x == 0 || y == 3) ? 0 : mat[x - 1][y + 1]; //up
	int ans2 = (y == 3) ? 0 : mat[x][y + 1]; //right
	int ans3 = (x == 3 || y == 3) ? 0 : mat[x + 1][y + 1]; //down
	int maxans = max(ans1, max(ans2, ans3));
	if (maxans == ans1) 
		return mat[x][y] + goldMine(mat, x - 1, y + 1);
	else if (maxans == ans2) 
		return mat[x][y] + goldMine(mat, x, y + 1);
	else 
		return mat[x][y] + goldMine(mat, x + 1, y + 1);

}
int goldmine(int mat[4][4]) {
	int ans = 0;
	int maxans = 0;
	for (int i = 0; i < 4; i++) {
		ans = goldMine(mat, i);
		if (ans > maxans) maxans = ans;
	}
	return maxans;
}

int main()
{
	int mat[4][4] = 
	{
		{1, 3, 1, 5},
		{2, 2, 4, 1},
		{5, 0, 2, 3},
		{0, 0, 55, 55}
	};
	cout << goldmine(mat);
}