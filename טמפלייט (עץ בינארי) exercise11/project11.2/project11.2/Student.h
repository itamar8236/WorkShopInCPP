//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 11 Question 2
//this program uses binary search tree to save students.
#include <iostream>
#include <string>
using namespace std;
#pragma once
class Student
{
private://fields
	string id;
	string lName;
	string fName;
public://operators
	bool operator<(const Student& st)const;
	bool operator>(const Student& st)const;
	bool operator==(const Student& st)const;
	bool operator!=(const Student& st)const;
	void operator=(const Student& st);
	friend ostream& operator<<(ostream& os, Student& st);//output
	friend istream& operator>>(istream& is, Student& st);//input
	Student();
	~Student();
};

