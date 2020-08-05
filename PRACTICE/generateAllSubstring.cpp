#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
void subArray(int arr[], int n)
{
	// Pick starting point
	for (int i = 0; i < n; i++)
	{
		// Pick ending point
		for (int j = i; j < n; j++)
		{
			// Print subarray between current starting
			// and ending points
			for (int k = i; k <= j; k++)
				cout << arr[k] << " ";

			cout << endl;
		}
	}
}
int main() {
	string s = "abcd";
	for (int l = 1; l <= s.length(); l++)
		for (int i = 0; i <= s.length() - l; i++)
			cout << s.substr(i, l) << endl;
}