#include <iostream>
using namespace std;

void input(int arr[], int n) {
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
void outputArr(int arr[100], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}

int insertionsort(int arr[], int n){
	for (int i=1;i<n;i++){
		int temp=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>temp){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}

int main() {
	int n;
	cin >> n;
	int arr[100];
	input(arr, n);
	insertionsort(arr,n);
	outputArr(arr,n);
}