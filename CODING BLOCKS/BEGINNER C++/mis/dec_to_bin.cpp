#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;

	int bineq=0;
	int q=n;
	int m=1;

	while(q>0){
		int rem=q%2;
		bineq=bineq+m*rem;
		q=q/2;
		m=m*10;
	}
	cout<<bineq;
}