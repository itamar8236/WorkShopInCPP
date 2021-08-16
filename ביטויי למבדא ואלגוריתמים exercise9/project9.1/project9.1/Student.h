//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 9 Question 1
//this program gives the following options:  addNewStudent, milgaList, mostResearch, countMilgaBA, noResearchMA, overheadStudent, removePHDFailers(and stop). 
#pragma once
#include <iostream>
using namespace std;
#include<cstring>
#include<string>
#pragma warning (disable:4996)
class Student//abstract class
{
protected:
	int id;
	char* firstName;
	char* lastName;
	int numOfCourses;
public:
	int getNumOfCourses();
	char* getFname();
	char* getLname();
	bool virtual milga() = 0;
	void virtual print();
	int virtual getHours();
	bool virtual isResearch();
	Student();
	Student(int, const char*, const char*, int);
	virtual const char* studType() = 0;
	virtual ~Student();
};

