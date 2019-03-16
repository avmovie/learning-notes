#include<stdio.h>

const int i = 0;
int main()
{
	const int a = 10;
	int *p =(int *)&a;
	*p = 99;
	printf("%d\n",a);
	return 0;	
}
