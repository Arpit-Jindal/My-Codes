
#include <iostream>
using namespace std;

void inputarr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}
void outputarr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
}

int selectionsort(int arr[], int n) {

	for (int i = 0; i < n - 1; i++) {
		int min = arr[i];
		int loc = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < min) {
				min = arr[j];
				loc = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[loc];
		arr[loc] = temp;
	}

}

int main() {
	int n;
	cin >> n;
	int arr[100];
	inputarr(arr, n);
	selectionsort(arr, n);
	outputarr(arr, n);
}