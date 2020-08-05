#include <iostream>
using namespace std;

int inc(int n){
	if(n==0){
		return 1;
	}
	inc(n-1);
	cout<<n<<" ";
}

int main(){
	int n;
	cin>>n;
	inc(n);
}