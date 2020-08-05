#include<iostream>
using namespace std;

int nraisedm(int n, int m){
	int ans=1;
	for (int i=1;i<=m;i++){
		ans=ans*n;
	}
	return ans;
}


int main(){
	int n,m;
	cin>>n>>m;
	cout<<nraisedm(n,m);
}