#include <iostream>
using namespace std;

void input(int arr[][100], int n ){
		for (int i=0;i<n;i++){
		
		for (int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
}
void output	(int arr[][100], int n ){
	for (int i=0;i<n;i++){
		cout<<arr[i][i];
		cout<<endl;
	}
}
int main(){
	int n;
	cin>>n;
	int arr[100][100];
	input(arr,n);
	output(arr,n);
}