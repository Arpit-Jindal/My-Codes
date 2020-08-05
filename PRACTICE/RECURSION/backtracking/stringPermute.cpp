#include<iostream>
#include<cstring>
#include<set>
using namespace std;
void indent(int n) {
	for (int i = 0; i < n; i++) {
		cout << "    ";
	}
}
void permuteHelper(string s, string chosen, set<string>& alreadyprinted) {
	// indent(chosen.length());
	// cout << "permuteHelper(\"" << s << "\",\"" << chosen << "\")" << endl;
	if (s.empty()) {
		if((alreadyprinted.find(chosen) == alreadyprinted.end())){
			cout << chosen << endl;
			alreadyprinted.insert(chosen);
		}
	}
	else {
		//choose/explore/unchoose
		// 1 letter
		for (int i = 0; i < s.length(); i++) {
			//choose
			char c = s[i];
			chosen += c;
			s.erase(i, 1);

			//explore
			permuteHelper(s, chosen,alreadyprinted);

			//unchoose
			s.insert(i, 1, c);
			chosen.erase(chosen.length() - 1, 1);
		}
	}
}

void permute(string s) {
	set<string> alreadyprinted;
	permuteHelper(s, "",alreadyprinted);
}

int main()
{
	permute("aa");
}