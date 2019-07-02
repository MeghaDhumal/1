#include"Student.h"

Student::Student()
{
	this->rollno = 0;
	strcpy(this->name, "Unknwn");
	this->marks = 0.0;
}
Student::Student(int rollno, const char* name, float marks)
{
	this->rollno = rollno;
	strcpy(this->name, name);
	this->marks = marks;
}

void Student::accept()
{
	cout << "\n Enter the rollno::";
	cin >> this->rollno;
	cout << "\n Enter the name::";
	cin >> this->name;
	cout << "\n Enter the marks::";
	cin >> this->marks;
}
void Student::display()
{
	cout << "\n The details are-----";
	cout << "\n rollno: " << this->rollno;
	cout << "\n Name: " << this->name;
	cout << "\n Marks: " << this->marks;
}