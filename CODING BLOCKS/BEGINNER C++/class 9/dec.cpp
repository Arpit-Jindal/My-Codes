#include<iostream>
using namespace std;

int print(int n){
	cout<<n<<" ";
	if(n>1){
	print(n-1);
	}
}

int main(){
	int n;
	cin>>n;
	print (n);	
}