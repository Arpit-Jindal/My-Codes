#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int a[5] = {11, 13, 13, 3, 1};
	int ans[5];
	stack<int> s;
	int t;

	s.push(0);
	for (int i = 1; i < 5; i++)
	{
		if (a[s.top()] < a[i])
		{
			while (!s.empty() && a[s.top()] < a[i])
			{
				t = s.top(); s.pop();
				ans[t] = a[i];
			}
		}
		s.push(i);
	}
	while (!s.empty()) {
		t = s.top(); s.pop();
		ans[t] = -1;
	}
	for (int i = 0; i < 5; i++) {
		cout << ans[i] << " ";
	}
}