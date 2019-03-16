#include<iostream>
using namespace std;

int main()
{
	class cls
	{
		int x,y;
		public:
		static int w;
		void set(int a,int b)
		{
			x=a;
			y=b;
		}
		void show()
		{
			cout<<x<<y<<endl;
		}
	};
	
	int cls::w = 50;

	cls bingo;
	bingo.set(10,12);
	bingo.show();	

	return 0;
}
