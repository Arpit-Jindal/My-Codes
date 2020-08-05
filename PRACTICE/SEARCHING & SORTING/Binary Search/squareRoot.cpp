#include<iostream>
using namespace std;
float sqroot(int n, int p)
{
	int s = 0;
	int e = n - 1;
	int mid;
	float ans;
	while (s <= e)
	{
		mid = (s + e) / 2;
		if (mid * mid == n) {
			ans = mid;
			return ans;
		}
		if (mid * mid < n)
		{
			ans = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	float inc = 0.1;
	for (int i = 0; i < p; i++)
	{
		while (ans * ans < n)
			ans += inc;
		ans -= inc;
		inc /= 10;
	}
	return ans;
}
int main()
{
	cout << sqroot(10, 3) << endl;
	cout << sqroot(49, 3);
}