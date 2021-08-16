//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 4 Question 1
//this program simulate bank account. 
#pragma once
#include <iostream>
using namespace std;
class Clock
{
private:
	int hour;
	int minute;
	int second;
public:
	void setHour(int);
	int getHour();
	void setMinute(int);
	int getMinute();
	void setSecond(int);
	int getSecond();
	Clock operator+=(int);
	friend ostream& operator<<(ostream& os, Clock& cl);//output
	friend istream& operator>>(istream& is, Clock& cl);//input
	Clock(int h = 0, int m = 0, int s = 0);//ctr
	~Clock();
};

