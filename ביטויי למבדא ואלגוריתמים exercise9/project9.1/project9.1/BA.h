//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 9 Question 1
//this program gives the following options:  addNewStudent, milgaList, mostResearch, countMilgaBA, noResearchMA, overheadStudent, removePHDFailers(and stop).
#pragma once
#include "Student.h"
#include <iostream>
using namespace std;
#include<cstring>
#include<string>
#pragma warning (disable:4996)
class BA : public Student
{
protected:
	int* grades;
	int size;
	double average();
public:
	void print();
	bool milga();
	BA();
	BA(int, const char*, const char*, int, int*);
	const char* studType();
	~BA();
};
