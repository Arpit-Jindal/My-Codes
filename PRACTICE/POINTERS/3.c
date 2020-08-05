#include<stdio.h>
using namespace std;
int main() {
	int a = 6;
	int* p = &a;
	int** q = &p;
	int*** r = &q;
	printf("%d\n", p ); //add of a
	printf("%d\n", *p );//6
	printf("%d\n", q );//add of p
	printf("%d\n", *q );//add of a
	printf("%d\n", **q );//6
	printf("%d\n", r );//add of q
	printf("%d\n", *r );//add of p
	printf("%d\n", **r );//add of a
	printf("%d\n", ***r );//6
}