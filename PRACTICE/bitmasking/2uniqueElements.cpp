#include<iostream>
using namespace std;
void findUnique2Numbers(int* a, int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
		res = (res ^ a[i]);

	//find the rightmost setbit (i) in result
	int i = 0;
	int temp = res;
	while (temp)
	{
		if (temp & 1)
			break;
		i++;
		temp >>= 1;
	}
	//Create a mask
	int mask = (1 << i);

	int firstNo = 0;
	for (int i = 0; i < n; i++)
		if (mask & a[i])
			firstNo ^= a[i];

	int secondNo = firstNo ^ res;
	cout << firstNo << " " << secondNo;
}
int main()
{
	int a[] = {1, 2, 3, 4, 3, 5, 2, 1};
	int  n = sizeof(a) / sizeof(a[0]);
	findUnique2Numbers(a, n);
}