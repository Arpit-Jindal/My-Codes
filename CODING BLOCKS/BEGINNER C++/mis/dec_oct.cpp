#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;

	int octeq=0;
	int q=n;
	int m=1;

	while(q>0){
		int rem=q%8;
		octeq=octeq+m*rem;
		q=q/8;
		m=m*10;
	}
	cout<<octeq;
}