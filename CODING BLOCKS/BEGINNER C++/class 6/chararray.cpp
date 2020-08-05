#include <iostream>
using namespace std;

int stringlength(char arr[]) {
	int count = 0;
	while (arr[count] != '\0') {
		++count;
	}
	return count;
}
int main () {
	char arr[100];
	cin >> arr;
	cout << stringlength(arr);
}