#include<bits/stdc++.h>
using namespace std;
void subSequences(char* arr, char* ans, int i, int j) {
	if (arr[i] == '\0') {
		ans[j] = '\0';
		cout << ans << endl;
		return;
	}
	ans[j] = arr[i];
	//Include the current char
	subSequences(arr, ans, i + 1, j + 1);
	//Exclude the current char
	subSequences(arr, ans, i + 1, j);
}
int main() {
	char arr[100];
	cin >> arr;
	char ans[100];
	subSequences(arr, ans, 0, 0);
}