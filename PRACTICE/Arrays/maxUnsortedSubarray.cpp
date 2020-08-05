#include<bits/stdc++.h>
using namespace std;
vector<int> subUnsort(vector<int> &A) {

	int lef = -1, rig = -1;
	int temp = A[0];
	for ( int i = 1; i < A.size(); i++ ) {
		if ( A[i] < temp ) rig = i;
		temp = max(temp, A[i]);
	}
	temp = A[A.size() - 1];
	for ( int i = A.size() - 1; i >= 0; i-- ) {
		if ( temp < A[i] ) lef = i;
		temp = min(temp, A[i]);
	}
	if ( lef == -1 ) return { -1};
	else return {lef, rig};
}
int main()
{

}