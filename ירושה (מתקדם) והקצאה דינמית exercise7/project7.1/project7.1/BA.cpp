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
#pragma warning (disable:4996)
//this function returns the average of the student
double BA::average()
{
	double avg = 0;
	for (int i = 0; i < this->size; i++)
		avg += grades[i];
	if (this->size != 0)
		avg = avg / this->size;
	return avg;
}
//this function returns true or false if student allow milga
bool BA::milga()
{
	return this->numOfCourses >= 10 && average() > 95;
}
//printing function
void BA::print()
{
	Student::print();
	cout << "grades: ";
	for (int i = 0; i < this->size; i++)
		cout << this->grades[i] << ' ';
	cout << endl;
}
//defult ctr
BA::BA():Student()
{
	grades = NULL;
	size = 0;
}
//ctr
BA::BA(int id, const char* fn, const char* ln, int num, int*grades):Student(id, fn, ln, num)
{
	this->size = num;
	this->grades = new int[this->size];
	for (int i = 0; i < this->size; i++)
		this->grades[i] = grades[i];
}
//dstr
BA::~BA()
{
	if (grades)
		delete[] grades;
}
