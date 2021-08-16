//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 7 Question 1
//this program create array of 7 students and prints those who allowed milga. 
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
	bool virtual milga() = 0;
	void virtual print();
	Student();
	Student(int, const char*, const char*, int);
	virtual ~Student();
};

