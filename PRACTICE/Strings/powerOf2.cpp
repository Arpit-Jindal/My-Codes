#include<bits/stdc++.h>
using namespace std;
int isPowerOf2(string A)
{
	int len = A.length();
	int num = 0;
	if ((A[len - 1] - '0') % 2 != 0) return 0;
	while (A[0] != '1' || len != 1) 
	{
		if ((A[len - 1] - '0') % 2 != 0) return 0;
		int j = 0;
		for (int i = 0; i < len; i++) 
		{
			num = num * 10 + A[i] - '0';
			if (num < 2) 
			{
				if (i != 0) A[j++] = '0';
				continue;
			}
			A[j++] = num / 2 + '0';
			num = num % 2;
		}
		A[j] = '\0';
		len = j;
	}
	return 1;
}
int main()
{

}