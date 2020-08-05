#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char a[20];
	cin >> a;
	int len = strlen(a);
	int ans = (1 << len) - 2;//all (len-1)permutations of 4,7 = sum of gp 2^0 + 2^1 + ... + 2^(len-1)
	
	//Iterate over the no. from units place and add the contribution of 7
	int pos = 0;
	for (int i = len - 1; i >= 0; i--, pos++)
		if (a[i] == '7')
			ans += (1 << pos);
	cout << ans + 1 << endl;
}