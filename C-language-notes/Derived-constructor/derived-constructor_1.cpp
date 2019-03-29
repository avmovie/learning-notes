#include<iostream>
using namespace std;

class alpha
{
	int a;
	public:
	alpha(int i)
	{
		a = i;	
	}
	void showAlpha()
	{
		cout<<"the value of alpha:"<<a<<endl;
	}
};

class beta
{
	float p,q;
	public:
	beta(float a,float b):p(a),q(b+p){}
	void showBeta()
	{
		cout<<"the value of p:"<<p<<endl;
		cout<<"the value of q:"<<q<<endl;
	}
};

class gamma:public beta,public alpha
{
	float u,v;
	public:
	gamma(int a,int b,float c):alpha(a),beta(c,c),u(a)
	{
		v = b;
	}
	void show_gamma()
	{
		
		cout<<"the value of u:"<<u<<endl;
		cout<<"the value of v:"<<v<<endl;
	}
};

int main()
{
	gamma g(2,4,2.5);
	g.showAlpha();
	g.showBeta();
	g.show_gamma();
	return 0;
}
