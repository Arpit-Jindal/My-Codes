#include<bits/stdc++.h>
using namespace std;
map<char, string> keypad;
void phoneKeypad(string input, vector<string> &output) {
	if (input.size() == 0) {
		output.push_back("");
		return;
	}
	string smallString = input.substr(1);
	phoneKeypad(smallString, output);

	int s = output.size();

	//prepend each c in each output
	for (int i = 0; i < s; i++)
		for (auto c : keypad[input[0]])
			output.push_back(c + output[i]);

	//erase first s entries from output
	output.erase(output.begin(), output.begin() + s);
}
void print_keypad(string input, string output) {
	if (input.empty()) {
		cout << output << endl;
		return;
	}
	for (auto c : keypad[input[0]])
		print_keypad(input.substr(1), output + c);
}
int main() {
	keypad['2'] = "abc";
	keypad['3'] = "def";
	keypad['4'] = "ghi";
	keypad['5'] = "jkl";
	keypad['6'] = "mno";
	keypad['7'] = "pqrs";
	keypad['8'] = "tuv";
	keypad['9'] = "wxyz";
	string input; cin >> input;
	// vector<string> output;
	// phoneKeypad(input, output);
	// for (auto i : output) {
	// 	cout << i << endl;
	// }
	print_keypad(input, "");
}