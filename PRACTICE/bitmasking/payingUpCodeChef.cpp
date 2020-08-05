#include<iostream>
using namespace std;
bool generateSubsets(int* a, int n, int m)
{
	int range = (1 << n) - 1;
	for (int i = 0; i <= range; i++)
	{
		int sum = 0;
		int index = 0;
		int no = i;
		while (no > 0)
		{
			if (no & 1)
				sum += a[index];
			index++;
			no >>= 1;
		}
		if (sum == m)
			return true;
	}
	return false;
}
int main()
{
	int t, n, m;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		if (generateSubsets(a, n, m))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}