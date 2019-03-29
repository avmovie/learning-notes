//最终的结果是：
//this is base display
//this is base show
//this is base display
//this is derived show
//虚函数的注意事项：
//1. 当我们在基类和派生类中使用同名函数时，将基类函数声明为虚的，当函数变为虚函数时，根据基类指针所指向的对象类型而不是指针累心，c++将在运行期决定要调用哪个函数。
//2. 需要注意的一点是，我们必须通过声明为基类的指针来访问虚函数。为何不能通过像调用其他成员函数一样，使用对象名（加上点操作符）来调用虚函数呢？因为只有当虚函数通过基类指针被访问时，运行时多态才能实现。
//3. 虚函数的法则：
//	（1）虚函数必须是某一类的成员函数
//	（2）虚函数不能是静态成员
//	（3）它们可以通过对象访问指针
//	（4）虚函数可以是另一类的友元
//	（5）基类中的虚函数必须定义，即使它不会被用到
//	（6）...........p229

#include<iostream>
using namespace std;

class base 
{
	public:
	void display()
	{
		cout <<"this is base display"<<endl;
	}
	virtual void show()
	{
		cout<<"this is base show"<<endl;
	}
};

class derived:public base
{
	void display()
	{
		cout<<"this is derived display"<<endl;
	}
	void show()
	{
		cout<<"this is derived show"<<endl;
	}
};

int main()
{
	base bc;
	base *bptr;
	derived D;

	bptr = &bc;
	bptr->display();
	bptr->show();

	bptr = &D;
	bptr->display();
	bptr->show();
	return 0 ;
}
