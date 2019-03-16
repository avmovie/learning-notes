#include<iostream>
using namespace std;

class item
{
	int code;
	static int count;
public:
	void setCode(void);
	void showCode(void);
	static void showCount();
};

inline void item::setCode(void)
{
	code=++count;
}

inline void item::showCode(void)
{
	cout<<"code="<<code<<endl;
}

void item::showCount()
{
	cout<<"count="<<count<<endl;
}

int item::count;	//初始化静态成员变量count
int main()
{
	item a,b,c;

	a.setCode();
	a.showCode();
	item::showCount();

	b.setCode();
	b.showCode();
	item::showCount();

	c.setCode();
	c.showCode();
	item::showCount();	
	return 0;	
}
