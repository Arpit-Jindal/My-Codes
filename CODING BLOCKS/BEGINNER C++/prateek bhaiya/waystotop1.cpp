#include <iostream>
using namespace std;

int waystotop(int n,int k){
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}
	int ans=0;
	for (int i=1;i<=k;i++){
		ans+=waystotop(n-i,k);
	}
	return ans;
}

int main(){
	int n,k;
	cin>>n>>k;
	cout<<waystotop(n,k);
}