#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for (int f = 0; f <= t; f++)
	{
		string s;
		getline(cin,s);
		int i;
		for (i = 0; i < s.length(); i++)
		{
			if (s[i] == 'n')
				if (s[i + 1] == 'o')
					if (s[i + 2] == 't')
					{
						cout << "Real Fancy" << endl;
						break;
					}
			if (i == s.length() - 1)
				cout << "regularly fancy" << endl;
		}
	}
}