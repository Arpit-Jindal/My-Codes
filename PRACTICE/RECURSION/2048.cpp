#include<iostream>
using namespace std;
void print(string arr[], int n) {
	if (n > 0)
	{
		print(arr, n / 10);
		cout << arr[n % 10];
	}
}
int main()
{
	string arr[10] = {"zero ", "one " , "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
	print(arr, 20828);
}