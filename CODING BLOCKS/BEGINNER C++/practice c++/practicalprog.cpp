#include <iostream>
using namespace std;

bool Isdigit(char a) {
	return (a >= '0' && a <= '9');
}
bool Isalpha(char a) {
	return (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z');
}
bool Iswhitespace(char a) {
	return (a == ' ' || a == '\n' || a == '\t');
}
bool Isspace(char a) {
	return (a == ' ');
}
bool Isline(char a) {
	return (a == '\n');
}

void printcount() {
	char c;
	int num_char = 0;
	int num_digits = 0;
	int num_alpha = 0;
	int num_words = 0;
	int num_lines = 0;
	int num_whitespaces = 0;
	int num_spaces = 0;
	int num_others = 0;
	bool startword = false;


	while (true) {
		c = cin.get();
		if (c == '$') {break;}
		++num_char;

		if (Isdigit(c)) {
			++num_digits;
			startword = true;
		}
		else if (Isalpha(c)) {
			++num_alpha;
			startword = true;
		}
		else if (Iswhitespace(c)) {
			++num_whitespaces;
			if (startword) {
				++num_words;
			}
			startword = false;

			if (Isspace(c)) {++num_spaces;}
			else if (Isline(c)) {++num_lines;}
		}

		else {++num_others;}
		}

	cout << "characters  =  " << num_char << endl;
	cout << "digits  =  " << num_digits << endl;
	cout << "alphabets  =  " << num_alpha << endl;
	cout << "words  =  " << num_words << endl;
	cout << "lines  =  " << num_lines << endl;
	cout << "whitespaces  =  " << num_whitespaces << endl;
	cout << "spaces  =  " << num_spaces << endl;
	cout << "others  =  " << num_others << endl;

}


int main() {
	printcount();
}
