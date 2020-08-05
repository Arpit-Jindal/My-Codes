#include<iostream>
using namespace std;

int print(int n, int m){
	if (m==0)return 1;
	return n*print(n,m-1);
}

int main(){
	int n,m;
	cin>>n>>m;
	cout<<print (n,m);	
}