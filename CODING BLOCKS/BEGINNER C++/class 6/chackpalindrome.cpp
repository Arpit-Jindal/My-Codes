#include <iostream>
using namespace std;

int stringlength(char arr[]) {
	int count = 0;
	while (arr[count] != '\0') {
		++count;
	}
	return count;
}
bool checkpalindrome(char arr[]) {
	int be = 0;
	int en = stringlength(arr) - 1;

	while (be <= en) {
		if (arr[be] == arr[en]) {
			be++;
			en--;
		}
		else {return false;}
	}
	return true;
}

int main() {
	char arr[100];
	cin >> arr;
	cout << checkpalindrome(arr);
}