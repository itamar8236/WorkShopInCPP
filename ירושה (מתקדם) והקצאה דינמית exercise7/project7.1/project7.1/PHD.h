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
class PHD: public Student
{
private:
	int hours;
public:
	void print();
	bool milga();
	PHD();
	PHD(int, const char*, const char*, int, int);
	~PHD();
};

