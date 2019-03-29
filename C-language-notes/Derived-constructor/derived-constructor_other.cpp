//构造函数中的初始化列表
//notice :
//	数据成员按照声明次序进行初始化，与初始化列表中的次序无关。
//	也就是与“a”,"b"，变量在xyz类中的声明次序有关，和初始化列表中的次序无关

#include<iostream>
using namespace std;

class xyz
{
	int a ;
	int b ;
	public:
	xyz(int x,int y):a(x),b(y){};
	void show()
	{
		cout<<"the value of a:"<<a<<endl;
		cout<<"the value of b:"<<b<<endl;
	}
};

int main()
{
	xyz D(1,2);
	D.show();
	return 0;
}
