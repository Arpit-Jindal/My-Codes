#include <iostream>
using namespace std;

int largest(int n) {
	int arr[100];
	int ans = -1000000;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		int curnum = arr[i];
		if (curnum >= ans) {ans = curnum;}
	}
	return ans;
}


void selectionsort(int arr[100],int n){
	for (int i=n-2;i>0;i--){
		int ans=largest(i);
		int temp=ans;
		ans=arr[i];
		arr[i]=ans;

	}
	cout<<arr[n];

}





int main() {
	int arr[100];
	int n;
	cin >> n;
	selectionsort(arr,n);
}