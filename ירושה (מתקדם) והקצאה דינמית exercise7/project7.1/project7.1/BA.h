//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 7 Question 1
//this program create array of 7 students and prints those who allowed milga. 
#pragma once
#include "Student.h"
#include <iostream>
using namespace std;
#include<cstring>
#include<string>
#pragma warning (disable:4996)
class BA: public Student
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
	~BA();
};

