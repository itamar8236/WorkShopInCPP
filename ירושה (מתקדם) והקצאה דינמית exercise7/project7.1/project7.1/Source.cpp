//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 7 Question 1
//this program create array of 7 students and prints those who allowed milga. 
#include "Student.h"
#include "BA.h"
#include "PHD.h"
#include "MA.h"
#include <iostream>
using namespace std;
//this function gets array of students addresses and its size 
//the function prints all students who allowed milga.
void printScholar(Student** s, int size)
{
	for (int i = 0; i < size; i++)
		if (s[i]->milga())
		{
			s[i]->print();
			cout << endl;
		}
}
int main()
{
	int * gradesBA1 = new int[3]{ 90, 100, 90 };//grades array
	int * gradesBA2 = new int[10]{ 100, 100, 90, 100, 90, 100, 90, 100, 90, 100};
	int * gradesMA1 = new int[7]{ 90, 100, 90, 100, 90, 100, 90 };
	int * gradesMA2 = new int[7]{ 90, 100, 90, 100, 90, 100, 90 };
	Student** s = new Student*[7]{ new BA(123, "abe", "avraham", 3, gradesBA1),
									new BA(234, "yitzhak", "avrahamson", 10, gradesBA2), 
									new MA(345, "yaacov", "jacobson", 7, gradesMA1, 0),
									new MA(456, "sara", "emanu", 7, gradesMA1, 1), 
									new PHD(567, "rivka", "imanu", 1, 30),
									new PHD(678, "rachel", "jacobs", 2, 20),
									new PHD(789, "leah", "jacobs", 2, 30) };
	delete[] gradesBA1;//deleting dynamic memory
	delete[] gradesBA2;
	delete[] gradesMA1;
	delete[] gradesMA2;

	printScholar(s, 7);//printing students

	for (int i = 0; i < 7; i++)//deleting dynamic memory
		delete s[i];
	delete[]s;
	//system("pause");
	return 0;
}
//Running example:
//ID: 234
//	first name : yitzhak
//	last name : avrahamson
//	num courses : 10
//	grades : 100 100 90 100 90 100 90 100 90 100
//
//	ID : 456
//	first name : sara
//	last name : emanu
//	num courses : 7
//	grades : 90 100 90 100 90 100 90
//	research : yes
//
//	ID : 789
//	first name : leah
//	last name : jacobs
//	num courses : 2
//	hours : 30
//
//	Press any key to continue . . .