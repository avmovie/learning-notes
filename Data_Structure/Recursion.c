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
	if(N)
	{
		printN(N-1);
		printf("%d\n",N);
	}
	return ;
}
