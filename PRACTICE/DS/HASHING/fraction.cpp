#include<bits/stdc++.h>
using namespace std;
string fractionToDecimal(int A, int B) {
	if (A == 0) return "0";
	long long int num = A, den = B;
	int sign = (num < 0) ^ (den < 0) ? -1 : 1;
	num = abs(num);
	den = abs(den);
	string ans = "";
	if (sign == -1) ans += '-';
	ans += to_string(num / den);
	num = num % den;
	if (num == 0) return ans;
	ans += '.';

	unordered_map<int, int> m;
	int repeat = false;
	int count = 0;
	while (num > 0 && repeat == false) {
		if (m.find(num) == m.end()) m.insert({num, ans.length()});
		else {
			repeat = true;
			count = m[num];
			break;
		}
		num = num * 10;
		ans += to_string(num / den);
		num = num % den;
	}
	if (repeat) {
		ans.insert(count, "(");
		ans += ")";
	}
	return ans;
}
int main()
{

}