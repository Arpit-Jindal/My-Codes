#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v{1, 2, 3, 4};
	int n = v.size();
	for (int i = 0; i < n; i++) {
		for (int j = i; j <n; j++) {

			//Elements of subarray [i,j]
			for (int x = i; x <= j; x++) 
				cout << v[x];
			
			cout << endl;
		}
	}
}
