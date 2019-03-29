// 派生类的构造函数
// 1. 只要基类的构造函数不需要参数，派生类就不需要构造函数
// 2. 如果基类的构造函数需要参数，派生类就必=必须要有构造函数
// 3. 构造函数的实现顺序：
// 	当基类和派生类都有构造函数时，基类构造函数总是先执行，然后是派生类的构造函数
// 	在多继承中，基类的构造顺序和它们在派生类中声明的次序一致。
// 	在多级继承中，构造函数将按照继承的次序执行（由基类到派生类的顺序）
// 4. 基类构造函数的执行次序：
// 	继承于基类的派生类的构造函数的执行次序于基类在派生类中的声明顺序有关
// 	首先，虚基类的构造函数在任何非虚基类的构造函数之前被调用，
// 	其次，如果有多个虚基类，调用的次序与其声明的次序保持一致
// 	然后，在派生类构造函数执行之前，任何非虚基类的构造函数被调用
// 	最后，执行派生类本身的构造函数

#include<iostream>
using namespace std;

class theX
{
	int x;
	public:
	void show_theX()
	{
		cout<<"theX value:"<<x<<endl;
	}
	theX(int X)
	{
		x = X;	
	}
};

class alpha:virtual public theX
{
	int a;
	public:
	void show_a()
	{
		cout<<"alpha value:"<<a<<endl;
	}	
	alpha(int A,int X):theX(X)
	{
		a = A;
	}
};

class beta:virtual public theX
{
	int b;
	public:
	void show_b()
	{
		cout<<"beta value:"<<b<<endl;
	}
	beta(int B,int X):theX(X)
	{
		b = B;
	}
};

class gamma :virtual public theX,public alpha,public beta
{
	int g;
	public:
	void showGamma()
	{
		cout<<"gamma value:"<<g<<endl;
	}
	gamma(int x,int a,int b,int G):theX(x),alpha(a,x),beta(b)
	{
		g=G;
	}
};

int main()
{
	gamma G(1,2,3,4);
	G.show_theX();
	G.show_a();
	G.show_b();
	G.showGamma();
	return 0;
}
