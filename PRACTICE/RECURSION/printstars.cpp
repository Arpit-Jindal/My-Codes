#include<iostream>
using namespace std;

void printstars(int n)
{

	if (n == 1)
	{
		cout << "*";
	}
	else
	{
		cout << "*";
		printstars(n - 1);
	}
	// cout << "*";

	// if (n > 1)
	// {
	// 	printstars(n - 1);
	// }
}
int main()
{
	printstars(5);
}