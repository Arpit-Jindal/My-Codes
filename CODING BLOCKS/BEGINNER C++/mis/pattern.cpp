#include <iostream>
using namespace std;

int factorial(int n){
	int ans=1;
	for (int i=1;i<=n;i++){
		ans=ans*i;
	}
	return ans;
}


int main(){
	int n;
	cin>>n;
	int nfact=factorial(n); 
	cout<<nfact;
}