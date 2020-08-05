#include<iostream>
using namespace std;

int print(int arr[], int n, int n1) {
	if (n == 0) { return -1;}
	else if (arr[n - 1] == n1) { return n - 1;}
	print (arr, n - 1, n1);
}

int main() {
	int n,n1;
	cin >> n;
	int arr[100];
	for (int i = 0; i < n; i++) { cin >> arr[i]; } 
	cin >> n1;
	int i = print(arr, n, n1);
	cout << i;
}