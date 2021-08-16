//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 7 Question 1
//this program create array of 7 students and prints those who allowed milga. 
#include "BA.h"
#include "Student.h"
#include <iostream>
using namespace std;
#include<cstring>
#include<string>
#pragma once
#pragma warning (disable:4996)
class MA:public BA
{
private:
	bool research;
public:
	void print();
	bool milga();
	MA();
	MA(int, const char*, const char*, int, int*, bool);
	~MA();
};

