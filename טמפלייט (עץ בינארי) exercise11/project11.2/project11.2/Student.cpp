//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 11 Question 2
//this program uses binary search tree to save students.
#include <iostream>
#include <string>
using namespace std;
#include "Student.h"


//defult ctr
Student::Student()
{
	id = "0";
	lName = "";
	fName = "";
}


Student::~Student()
{
}
//operator <
bool Student::operator<(const Student& st)const
{
	if (this->lName == st.lName)
		return this->fName < st.fName;
	return this->lName < st.lName;
}
//operator >
bool Student::operator>(const Student& st)const
{
	if (this->lName == st.lName)
		return this->fName > st.fName;
	return this->lName > st.lName;
}
//operator ==
bool Student::operator==(const Student& st)const
{
	if (this->lName == st.lName)
		return this->fName == st.fName;
	return false;
}
//operator !=
bool Student::operator!=(const Student& st)const
{
	return !(*this == st);
}
//operator =
void Student::operator=(const Student& st)
{
	this->id = st.id;
	this->fName = st.fName;
	this->lName = st.lName;
}
//prints
ostream& operator<<(ostream& os, Student& st)
{
	os << st.id << ' ' << st.lName << ' ' << st.fName << endl;
	return os;
}
//reads
istream& operator>>(istream& is, Student& st)
{
	is >> st.id;
	is >> st.lName;
	is >> st.fName;
	return is;
}