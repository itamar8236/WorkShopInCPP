//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 9 Question 1
//this program gives the following options:  addNewStudent, milgaList, mostResearch, countMilgaBA, noResearchMA, overheadStudent, removePHDFailers(and stop).
#include "MA.h"
#include "BA.h"
#include "Student.h"
#include <iostream>
using namespace std;
#include<cstring>
#include<string>
#pragma warning (disable:4996)
//printing function
void MA::print()
{
	BA::print();
	cout << "research: ";
	if (research)
		cout << "yes";
	else
		cout << "no";
	cout << endl;
}
//milga allowence
bool MA::milga()
{
	return this->numOfCourses >= 7 && this->average() > 90 && research;
}
//defult ctr
MA::MA() :BA()
{
}
//ctr
MA::MA(int id, const char* fn, const char* ln, int num, int*grades, bool res) : BA(id, fn, ln, num, grades)
{
	research = res;
}
//dstr
MA::~MA()
{
}
//return research
bool MA::isResearch() { return research; }
//student type
const char* MA::studType()
{
	return "MA";
}
