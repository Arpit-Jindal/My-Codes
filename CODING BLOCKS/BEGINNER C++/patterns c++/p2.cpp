#include <iostream>
using namespace std;
int main () {
	int N;
	cin>>N;
	int n=N;
	for (int i=1;i<=N;i++)
	{
		int x=i;
		for(int j=1;j<n;j++)
		{
			cout<<"\t";
		} 
		n--;
		int val=i;
		for (;val<=(2*i - 1);val++)
		{
			cout<<val<<"\t";

		}
		val=val-2;
		for(;val>=i;val--)
		    cout<<val<<"\t";
		
		cout<< endl;
	}
}