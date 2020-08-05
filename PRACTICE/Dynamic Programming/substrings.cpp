#include<bits/stdc++.h>
using namespace std;
int subs(string input, string output[]) {
	if (input.empty()) {
		output[0] = "";
		return 1;
	}
	string smallString = input.substr(1);
	int smallOutputSize = subs(smallString, output);
	for (int i = 0; i < smallOutputSize; i++) {
		output[i + smallOutputSize] = input[0] + output[i];
	}
	return 2 * smallOutputSize;
}
// vector<string> v;
void print_subs(string input, string output) {
	if (input.empty()) {
		cout << output << endl;
		// v.push_back(output);
		return;
	}
	print_subs(input.substr(1), output);
	print_subs(input.substr(1), output + input[0]);
}
int main() {
	string input;
	cin >> input;
	// int input_n = input.size();
	// int output_n = pow(2, input_n);
	// string* output = new string[output_n];
	// int size = subs(input, output);
	// for (int i = 0; i < size; i++) {
	// 	cout << output[i] << endl;
	// }
	print_subs(input, "");
	// for (auto i : v) {
	// 	cout << i << endl;
	// }
}