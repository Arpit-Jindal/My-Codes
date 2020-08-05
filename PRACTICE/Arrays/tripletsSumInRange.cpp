#include<bits/stdc++.h>
using namespace std;
//First Approach
//O(nlogn)
int solve(vector<string> &A) {
	vector<double> v(A.size());
	for (int i = 0; i < A.size(); i++) {
		v[i] = atof(A[i].c_str());
	}
	sort(v.begin(), v.end());
	int r = A.size() - 1, l = 0, m = 1;
	while (r > m) {
		if (v[l] + v[m] + v[r] > 1 && v[l] + v[m] + v[r] < 2)
			return 1;
		else if (v[l] + v[m] + v[r] >= 2)
			r--;
		else if (v[l] + v[m] + v[r] <= 1){
			l++; m++; //l++ therefore this while loop takes O(n) only
		}
	}
	return 0;
}
//2nd approach
// Time complexity =O(logn)+O(n) = O(n)
double min_element(vector<double> A)  //return minimum element
{	double min = A[0];
	for (int i = 0; i < A.size(); i++)
		if (A[i] < min)
			min = A[i];
	return min;
}
int Solution::solve(vector<string> &input) {
	vector<double> A, B, C;
	double x = 2.0 / 3.0;
	for (int i = 0; i < input.size(); i++) {
		char a[20];
		for (int j = 0; j < input[i].length(); j++)
			a[j] = input[i][j];
		double af = atof(a);
		if (0.0 < af && af < x)
			A.push_back(af);
		else if (x <= af && af <= 1.0)
			B.push_back(af);
		else if (1.0 < af && af < 2.0)
			C.push_back(af);
	}
//1 - A A A
	if (A.size() >= 3)
	{
		//priority queue used to get max 3 elements in O(logn) time
		priority_queue<double> q(A.begin(), A.end());
		double m = 0;
		for (int i = 0; i <= 2; i++) {
			m += q.top(); q.pop();
		}
		if (m > 1.0)
			return 1;
	}
//2 - A A B
	if (A.size() >= 2 && B.size() >= 1)
	{
		//priority queue used to get max 2 elements in O(logn) time
		priority_queue<double> q1(A.begin(), A.end());

		double m1 = 0;
		for (int i = 0; i <= 1; i++) {
			m1 += q1.top(); q1.pop();
		}
		for (int i = 0; i < B.size(); i++)
			if (1 - m1 < B[i] && B[i] < 2 - m1)
				return 1;
	}
//3 - A A C
	if (A.size() >= 2 && C.size() >= 1)
	{
		//priority queue used to get min 2 elements in O(logn) time
		priority_queue<double, std::vector<double>, std::greater<double> > q2(A.begin(), A.end());
		double m2 = 0;
		for (int i = 0; i <= 1; i++) {
			m2 += q2.top(); q2.pop();
		}
		double min = min_element(C);
		if (m2 + min < 2.0)
			return 1;
	}
//4 - A B B
	if (B.size() >= 2 && A.size() >= 1)
	{
		//priority queue used to get min 2 elements in O(logn) time
		priority_queue<double, std::vector<double>, std::greater<double> > q3(B.begin(), B.end());

		double m3 = 0;
		for (int i = 0; i <= 1; i++) {
			m3 += q3.top(); q3.pop();
		}
		for (int i = 0; i < A.size(); i++)
			if (A[i] < 2 - m3)
				return 1;
	}
//5 - A B C
	if (A.size() >= 1 && B.size() >= 1 && C.size() >= 1)
	{
		double min1 = min_element(A), min2 = min_element(B), min3 = min_element(C);
		if (min1 + min2 + min3 < 2 && min1 + min2 + min3 > 1)
			return 1;
	}
	return 0;
}
int main()
{

}