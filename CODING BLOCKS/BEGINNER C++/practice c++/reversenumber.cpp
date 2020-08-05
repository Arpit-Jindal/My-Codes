#include<iostream>
#include <cmath>
using namespace std;

int reverse(int n) {
	int ans=0;
	while (n!=0){
		int unitdigit=n%10;
		ans=ans*10;
		ans=ans + unitdigit;
		n=n/10;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	cout<<reverse(n);
}