#include<bits/stdc++.h>
using namespace std;
//my approach
string countAndSay(int n) {
	if (n == 0) return "";
	if (n == 1) return "1";
	string prev = "";
	string ans = "1";
	for (int i = 2; i <= n; i++) {
		int count = 0;
		string currNo;
		int index = 0;
		prev = ans;
		ans = "";
		for (int j = 0; j < prev.length(); j++)
		{
			if (prev[j] == prev[index])
				count++;
			else
			{
				index = j;
				ans += to_string(count) + prev[j - 1];
				count = 1;
			}
		}
		ans += to_string(count) + prev[prev.length() - 1];
	}
	return ans;
}
//better one
string countAndSay(int n) {
	if (n == 0) return "";
	if (n == 1) return "1";
	string prev = "1";
	string ans = "";
	for (int i = 2; i <= n; i++) {
		ans.clear();
		for (int j = 0; j < prev.length(); j++) {
			int count = 1;
			while (j + 1 < prev.length() && prev[j] == prev[j + 1]) {
				count++; j++;
			}
			ans += to_string(count) + prev[j];
		}
		prev = ans;
	}
	return ans;
}

int main()
{

}