//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 9 Question 1
//this program gives the following options:  addNewStudent, milgaList, mostResearch, countMilgaBA, noResearchMA, overheadStudent, removePHDFailers(and stop).
#include "PHD.h"
#include "Student.h"
#include <iostream>
using namespace std;
#include<cstring>
#include<string>
#pragma warning (disable:4996)
//printing function
void PHD::print()
{
	Student::print();
	cout << "hours: " << this->hours << endl;
}
//milga allowence
bool PHD::milga()
{
	return this->numOfCourses >= 2 && this->hours > 25;
}
//defult ctr
PHD::PHD() :Student()
{
}
//ctr
PHD::PHD(int id, const char* fn, const char* ln, int num, int hours) : Student(id, fn, ln, num)
{
	this->hours = hours;
}
//dstr
PHD::~PHD()
{
}
//return hours
int PHD::getHours() { return this->hours; }
//student type
const char* PHD::studType()
{
	return "PHD";
}
