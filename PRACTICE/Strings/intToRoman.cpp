#include<bits/stdc++.h>
using namespace std;
string intToRoman(int a) {
	vector<int> num{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
	vector<string> sym{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
	int i = 12;
	string ans;
	while (a > 0)
	{
		int q = a / num[i];
		a = a % num[i];
		while (q--)
			ans += sym[i];
		i--;
	}
	return ans;
}
int main()
{

}