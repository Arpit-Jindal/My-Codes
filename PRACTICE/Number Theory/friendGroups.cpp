#include<iostream>
#include<cstring>
using namespace std;
int friendGroups(int input)
{
	int n = input + 2;
	bool arr[n];
	memset(arr, true, sizeof arr);
	int count = 0;
	for (int p = 2; p < n; p++)
	{
		int flag = 0;
		for (int i = p; i < n; i += p)
		{
			if (arr[i] == false && flag == 0)
			{
				count--;
				flag = 1;
			}
			arr[i] = false;
		}
		count++;
	}
	return count;
}
int main()
{
	int n; cin >> n;
	cout << friendGroups(n);
}