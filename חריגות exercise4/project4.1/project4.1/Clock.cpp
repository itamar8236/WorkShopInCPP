//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 4 Question 1
//this program simulate bank account. 
#include "Clock.h"
#include <iostream>
using namespace std;
//this functions sets new hour if valid.
void Clock::setHour(int h)
{
	try {
		if (h > 23)
			throw "Invalid time - more than 24 hours.";
		if (h < 0)
			throw "Invalid time - negative number of hours.";
		this->hour = h;
	}
	catch(const char* msg)
	{
		cout << msg << endl;
		hour = 0;
	}
}
//this functions returns the hour.
int Clock::getHour() { return hour; }
//this functions sets new minute if valid.
void Clock::setMinute(int m)
{
	try {
		if (m > 59)
			throw "Invalid time - more than 60 minutes.";
		if (m < 0)
			throw "Invalid time - negative number of minutes.";
		this->minute = m;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		minute = 0;
	}
}
//this functions returns the minute.
int Clock::getMinute() { return minute; }
//this functions sets new second if valid.
void Clock::setSecond(int s)
{
	try {
		if (s > 59)
			throw "Invalid time - more than 60 seconds.";
		if (s < 0)
			throw "Invalid time - negative number of seconds.";
		this->second = s;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		second = 0;
	}
}
//this functions returns the second.
int Clock::getSecond() { return second; }
//the operator += on seconds.
Clock Clock::operator+=(int s)
{
	if (s >= 0)
	{
		this->hour = this->hour + ((this->minute + ((this->second + s) / 60)) / 60) % 24;
		this->minute = (this->minute + ((this->second + s) / 60)) % 60;
		this->second = (this->second + s) % 60;
	}
	return *this;
}
//the operator << for output
ostream& operator<<(ostream& os, Clock& cl)
{
	if (cl.hour < 10)
		os << '0';
	os << cl.hour << ':';
	if (cl.minute < 10)
		os << '0';
	os << cl.minute << ':';
	if (cl.second < 10)
		os << '0';
	os << cl.second << endl;
	return os;
}
//the operator >> for input
istream& operator>>(istream& is, Clock& cl)
{
	int h, m, s;
	char ch;
	is >> h;
	is >> ch;
	is >> m;
	is >> ch;
	is >> s;
	cl = Clock(h, m, s);
	return is;
}
//ctr
Clock::Clock(int h, int m, int s)
{
	try {
		if (h > 23)
			throw "Invalid time - more than 24 hours.";
		if (h < 0)
			throw "Invalid time - negative number of hours.";
		if (m > 59)
			throw "Invalid time - more than 60 minutes.";
		if (m < 0)
			throw "Invalid time - negative number of minutes.";
		if (s > 59)
			throw "Invalid time - more than 60 seconds.";
		if (s < 0)
			throw "Invalid time - negative number of seconds.";
		this->hour = h;
		this->minute = m;
		this->second = s;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		this->hour = 0;
		this->minute = 0;
		this->second = 0;
	}
}
Clock::~Clock()
{
}
