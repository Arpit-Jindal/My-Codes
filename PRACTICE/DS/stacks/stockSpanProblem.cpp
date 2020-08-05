#include<iostream>
#include<stack>
using namespace std;
void printarray(int* ans, int n)
{
	cout << "[" ;
	for (int i = 0; i < n - 1; i++)
		cout << ans[i] << " , ";
	cout << ans[n - 1] << "]";
}
int main()
{
	int a[] = {50, 100, 80, 60, 70, 160, 75, 85};
	int n = sizeof(a) / sizeof(a[0]);
	stack <int> s;
	int ans[n];
	for (int i = 0; i < n; i++)
	{
		while (!s.empty() && a[i] > a[s.top()])
			s.pop();
		ans[i] = (s.empty()) ? (i + 1) : (i - s.top());
		s.push(i);
	}
	printarray(ans, n);
}