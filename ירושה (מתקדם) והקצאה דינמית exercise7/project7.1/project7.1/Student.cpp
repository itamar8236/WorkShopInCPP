//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 7 Question 1
//this program create array of 7 students and prints those who allowed milga. 
#include "Student.h"
#include <iostream>
using namespace std;
#include<cstring>
#include<string>
#pragma warning (disable:4996)
//printing function
void Student::print()
{
	cout << "ID: " << id << endl
		<< "first name: " << firstName << endl
		<< "last name: " << lastName << endl
		<< "num courses: " << numOfCourses << endl;
}
//defult ctr
Student::Student()
{
	firstName = NULL;
	lastName = NULL;
	numOfCourses = 0;
}
//ctr
Student::Student(int id, const char* fn, const char* ln, int num)
{
	this->id = id;
	this->numOfCourses = num;
	firstName = new char[strlen(fn)+1];
	strcpy(firstName, fn);
	lastName = new char[strlen(ln) + 1];
	strcpy(lastName, ln);
}
//dstr
Student::~Student()
{
	if (firstName)
		delete[] firstName;
	if (lastName)
		delete[]lastName;
}
