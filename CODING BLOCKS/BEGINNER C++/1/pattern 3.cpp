#include <iostream>
using namespace std;
int main() {
	int lines;
	cin >> lines;
	int temp=lines;
	for (int i = 1; i<=lines; i++){
		
		for(int j=1;j<=i;j++){
			cout<<temp;

		}
		temp--;

		cout<<endl;

	}
}