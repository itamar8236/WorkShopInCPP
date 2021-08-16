//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 9 Question 1
//this program gives the following options:  addNewStudent, milgaList, mostResearch, countMilgaBA, noResearchMA, overheadStudent, removePHDFailers(and stop).
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
	firstName = new char[strlen(fn) + 1];
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
int Student::getHours() { return 0; }
//return first name
char* Student::getFname()
{
	return firstName;
}
//return last name
char* Student::getLname()
{
	return lastName;
}
//return is research
bool Student::isResearch() { return false; }
//return NumOfCourses
int Student::getNumOfCourses() { return numOfCourses; }