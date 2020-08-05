#include<stdio.h>

int SUM(int a[])
{
	int i,sum=0;
	int size = sizeof(a)/sizeof(a[0]);
	for (i=0;i<size;i++)
	{
		sum+=a[i];
	}
	return sum;
}


int main()
{
	int a[]={1,2,3,4,5};
	int sum = SUM(a);
	printf("%d\n",sum );

}