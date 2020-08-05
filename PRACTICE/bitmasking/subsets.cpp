#include<iostream>
#include<cstring>
using namespace std;
void filterChars(char*a, int no)
{
	int i = 0;
	while (no > 0)
	{
		if (no & 1)
			cout << a[i];
		i++;
		no >>= 1;
	}
	cout << endl;
}
void generateSubsets(char* a)
{
	int n = strlen(a);
	int range = (1 << n) - 1; //2^n - 1
	for (int i = 1; i <= range; i++)
		filterChars(a, i);
}
int main()
{
	char a[100];
	cin >> a;
	generateSubsets(a);
}