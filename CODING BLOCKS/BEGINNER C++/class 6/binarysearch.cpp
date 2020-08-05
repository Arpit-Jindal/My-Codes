#include <iostream>
using namespace std;

void input(int arr[], int n) {
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

int nthelement(int arr[], int n, int x) { 
	int be=0;
	int en=n-1;
	while (true){
		int mid = (be+en)/2;
		if (arr[mid]==x){return mid;}
		else if(arr[mid]>x){
			en=mid-1;
		} 
		else {
			be=mid+1;
		}
	}
	
	return -1;
}
int main() {
	int n;
	cin >> n;
	int arr[100];
	input(arr, n);
	int x;
	cin >> x;
	cout << nthelement(arr, n, x);
}