#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	bool isprime=true;
	if (n % 2 == 0)	{cout << "composite"; isprime=false;}
	else
	{
		for (int i = 3; i < sqrt(n); i += 2)
		{
			if (n % i == 0)
			{
				cout<<"composite";
				isprime=false;
				break;
			}
		}
	}
	if(isprime)	cout<<"Prime";

}