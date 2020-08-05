#include <iostream>
using namespace std;

void printarr(int n){
	int arr[100];
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
}

int main() {
	int n;
	cin >> n;
	printarr(n);
}