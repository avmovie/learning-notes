//友元函数的使用

#include<iostream>
using namespace std;

class A {
	int a ,b;
	public:
	void setValue(){
		a =10;
		b =99;
}
	friend void display(A x);
};

void display(A x)
{
	cout<<x.a<<x.b<<endl;
}

int main()
{
	A v;
	v.setValue();
	display(v);
	return 0;
}
