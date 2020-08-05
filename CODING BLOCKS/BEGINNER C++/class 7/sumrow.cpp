#include <iostream>
using namespace std;

void input(int arr[][100], int n ){
		for (int i=0;i<n;i++){
		
		for (int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
}
void sumrow(int arr[][100],int n){
	int curnum=-1000000;
	int rowno=-1;
	int colsum[100]={};

	for (int i=0;i<n;i++){
		int ans=0;
		for (int j=0;j<n;j++){
			ans=ans + arr[i][j];
			colsum[j]=colsum[j]+ arr[i][j];
		}
		if (ans>curnum){curnum=ans;
			rowno=i;}

	}

	int maxcolsum=-10000000;
	int colno=-1;
	for(int i=0;i<n;i++){
		if(colsum[i]>maxcolsum){
			maxcolsum=colsum[i];
			colno=i;
		}
	}
	cout<<curnum<<" "<<rowno<<endl;
	cout<<maxcolsum<<" "<<colno;
}

int main(){
	int n;
	cin>>n;
	int arr[100][100];
	input(arr,n);
	sumrow(arr,n);
	
}