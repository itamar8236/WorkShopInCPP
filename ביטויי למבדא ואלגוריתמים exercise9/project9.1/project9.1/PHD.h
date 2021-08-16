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
class PHD : public Student
{
private:
	int hours;
public:
	int getHours();
	void print();
	bool milga();
	PHD();
	PHD(int, const char*, const char*, int, int);
	const char* studType();
	~PHD();
};

