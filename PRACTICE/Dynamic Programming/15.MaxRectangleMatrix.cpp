//Max sub rectangle of all 1s in binary matrix
#include<bits/stdc++.h>
using namespace std;
int largestHistogramArea(vector<int> hist, int n) {
	stack<int> s;
	int maxarea = 0, area = 0;
	int i = 0;
	while (i < n) {
		if (s.empty() || hist[i] >= hist[s.top()]) {
			s.push(i);
			i++;
		}
		else {
			int top = s.top(); s.pop();
			area = hist[top] * (s.empty() ? i : (i - s.top() - 1));
			if (maxarea < area)
				maxarea = area;
		}
	}
	while (!s.empty())
	{
		int top = s.top(); s.pop();
		area = hist[top] * (s.empty() ? i : (i - s.top() - 1));
		if (maxarea < area)
			maxarea = area;
	}
	return maxarea;
}
int maxSubRectangle(vector<vector<int>> &input, int r, int c) {
	vector<int> hist(c, 0);
	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (input[i][j]) hist[j] += 1;
			else hist[j] = 0;
		}
		ans = max(ans, largestHistogramArea(hist, c));
	}
	return ans;
}
int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> input (n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> input[i][j];

	cout << maxSubRectangle(input, n, m);
}