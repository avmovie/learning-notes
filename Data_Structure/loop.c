#include<stdio.h>

void printN(int N);
int main()
{
	int N;
	printf("input yout number:");
	scanf("%d",&N);
	printN(N);
	return 0;
}

void printN(int N)
{
	for (int i = 0;i<N;i++)
	printf("%d\n",i);
}
