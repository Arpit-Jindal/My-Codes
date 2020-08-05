#include <iostream>
using namespace std;

int waystotop(int n,int k){
	int sum=0;
	for (int i=1;i<=(n/k);i++){
		sum=sum - k*i;
	}
	cout<< sum + (n+1)*(n/k) + 1;

}

int main(){
	int n,k;
	cin>>n>>k;
	waystotop(n,k);
}