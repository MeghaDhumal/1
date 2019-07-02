#include<iostream>
using namespace std;

class Student
{
private:
	int rollno;
	char name[10];
	float marks;
public:
	Student();
	Student(int, const char*, float);
	int getRollNo()
	{
		return this->rollno;
	}
	void accept();
	void display();
};