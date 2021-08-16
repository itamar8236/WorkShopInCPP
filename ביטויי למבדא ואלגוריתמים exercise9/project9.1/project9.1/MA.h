//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 9 Question 1
//this program gives the following options:  addNewStudent, milgaList, mostResearch, countMilgaBA, noResearchMA, overheadStudent, removePHDFailers(and stop).
#include "BA.h"
#include "Student.h"
#include <iostream>
using namespace std;
#include<cstring>
#include<string>
#pragma once
#pragma warning (disable:4996)
class MA :public BA
{
private:
	bool research;
public:
	bool isResearch();
	void print();
	bool milga();
	MA();
	MA(int, const char*, const char*, int, int*, bool);
	const char* studType();
	~MA();
};

