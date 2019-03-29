#include<iostream>
using namespace std;

class student
{
	protected:
	int roll_number;
	public:
	void get_number(int a)
	{
		roll_number=a;
	}	
	void put_number(void)
	{
		cout<<"roll_number:"<<roll_number<<endl;
	}
};

class test:virtual public student
{
	protected:
		float part1,part2;
	public:
		void getMarks(float x,float y)
		{
			part1 = x;
			part2 = y;
		}
		void putMarks()
		{
			cout<<"part1 ="<<part1<<endl;
			cout<<"part2 ="<<part2<<endl;
		}

};

class sports:public virtual student
{
	protected:
		float score;
	public:
		void getScore(float s)
		{
			score = s;
		}
		void putScore()
		{
			cout<<"score:"<<score<<endl;
		}
};

class result:public test,public sports
{
	float total;
	public:
	void display(void);
};

void result::display(void)
{
	total = part1 + part2 + score;
	put_number();
	putMarks();
	putScore();
	cout<<"total:"<<total<<endl;
}

int main()
{
	result student_1;
	student_1.get_number(678);
	student_1.getMarks(30.5,25.5);
	student_1.getScore(7.0);
	student_1.display();
	return 0;
}
