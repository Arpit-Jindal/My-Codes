#include<iostream>
using namespace std;
bool ispalindrome(string s)
{
	if (s.length() < 2)
		return true;
	else
	{
		char first = s[0];
		char last = s[s.length() - 1];
		if (first == last)
		{
			string rest = s.substr(1, s.length() - 2);
			return ispalindrome(rest);
		}
		else
			return false;
	}
}
int main(){
	cout << ispalindrome("cacac");
}