#include <iostream>
using namespace std;

void inputarr(int arr[],int n){
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
}

bool check(int arr[],int n,int m){
	if (arr[n]==m){
		return true;
	}
	check(arr,n-1,m);
	
}

int main(){
	int n;
	cin>>n;
	int arr[100];
	inputarr(arr,n);
	int m;
	cin>>m;
	cout<<check(arr,n,m);
}