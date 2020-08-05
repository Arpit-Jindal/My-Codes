#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int hist[] = {6, 2, 5, 4, 5, 1, 6};
	int n = sizeof(hist) / sizeof(hist[0]);
	stack<int> s;
	int maxarea = 0;
	int area = 0;
	int i;
	while (i < n)
	{
		if (s.empty() || hist[i] >= hist[s.top()])
		{
			s.push(i);
			i++; 
		}
		else
		{
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
	cout << maxarea << endl;
}