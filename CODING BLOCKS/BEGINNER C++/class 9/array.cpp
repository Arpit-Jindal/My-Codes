#include<iostream>
using namespace std;

void array(int arr[],int be,int en){
	if(be<=en){
		cout<<arr[be]<<" ";
		array(arr,be+1,en);
	}

}
int main(){
	int n;
	cin>>n;
	int arr[100];
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
	array (arr,n);	
}