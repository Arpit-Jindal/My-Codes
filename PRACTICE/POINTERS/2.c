#include<stdio.h>
using namespace std;
int main() {
	int a = 1025;
	int* p = &a;
	printf("p = %d\n", p);
	printf("p+1 = %d\n", p + 1);
	printf("value at p = %d\n", *p);
	char* p0;
	p0 = (char*)p;
	printf("p0 = %d\n", p0);
	printf("p0+1 = %d\n", p0 + 1);
	printf("value at p0 = %d\n", *p0);
	printf("value at p0+1 = %d\n", *(p0 + 1));
}