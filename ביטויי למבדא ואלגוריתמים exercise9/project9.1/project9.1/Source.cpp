//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 9 Question 1
//this program gives the following options:  addNewStudent, milgaList, mostResearch, countMilgaBA, noResearchMA, overheadStudent, removePHDFailers(and stop).
#include "Student.h"
#include "BA.h"
#include "PHD.h"
#include "MA.h"
#include "vector"
#include <algorithm>
#include<string>
#include <iostream>
using namespace std;
enum option { stop, addNewStudent, milgaList, mostResearch, countMilgaBA, noResearchMA, overheadStudent, removePHDFailers };
//this functions adds new student
void add(vector<Student*>& vec)
{
	int type;
	int id, numOfCourses;
	char first[100];
	char last[100];
	int* grades;
	cout << "enter 1 to add a BA student\n";
	cout << "enter 2 to add a MA student\n";
	cout << "enter 3 to add a PHD student\n";
	cin >> type;
	cout << "enter id, first name, last name and number OfCourses\n";	cin >> id >> first >> last >> numOfCourses;
	switch (type)
	{
	case 1:
		grades = new int[numOfCourses];
		cout << "enter " << numOfCourses << " grades\n";
		for (int i = 0; i < numOfCourses; i++)
			cin >> grades[i];
		vec.push_back(new BA(id, first, last, numOfCourses, grades));
		delete[] grades;
		break;
	case 2:
		grades = new int[numOfCourses];
		bool res;
		cout << "enter " << numOfCourses << " grades\n";
		for (int i = 0; i < numOfCourses; i++)
			cin >> grades[i];
		cout << "enter 1 if the student does research and 0 if not\n";
		cin >> res;
		vec.push_back(new MA(id, first, last, numOfCourses, grades, res));
		delete[] grades;
		break;
	case 3:
		int hours;
		cout << "enter number of research hours\n";
		cin >> hours;
		vec.push_back(new PHD(id, first, last, numOfCourses, hours));
		break;
	};
}
//printing all students that allow to milga
void milga(vector<Student*> vec)
{
	for_each(vec.begin(), vec.end(),[](Student* st) {if (st->milga()) st->print();});
}
//return the phd student with most research hours
Student* mostResearchHours(vector<Student*> vec)
{
	Student* retst = NULL;
	auto it = vec.begin();
	while (it != vec.end())
	{
		if ((*it)->studType() == "PHD")
			if (retst == NULL || retst->getHours() < (*it)->getHours())
				retst = *it;
		++it;
	}
	return retst;
}
int main()
{//copied.
	vector<Student*> v;
	int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != stop)
	{
		switch (op)
		{
		case addNewStudent: add(v);
			break;
		case milgaList:milga(v);
			break;
		case mostResearch:
		{
			Student *s = mostResearchHours(v);
			if (s != NULL)
			{
				cout << "PHD studnet with most research hours: ";
				cout << s->getFname() << ' ' << s->getLname() << endl;
			}
		}
			break;
		case countMilgaBA: cout << "#BA studnets for milga: ";
			cout << count_if(v.begin(), v.end(),[](Student* st) {return st->studType() == "BA" && st->milga(); });
			cout << endl;
			break;
		case noResearchMA: cout << "list of no research MA students : ";
			for_each(v.begin(), v.end(), [](Student* st) {if (st->studType() == "MA") if (!st->isResearch()) cout << st->getFname() << ' ' << st->getLname() << endl; });
			break;
		case overheadStudent:
			if (any_of(v.begin(), v.end(), [](Student* st) {return st->getNumOfCourses() > 15; }))
				cout << "there is a student that takes more than 15 courses\n";
			else cout << "no student takes more than 15 courses\n";
			break;
		case removePHDFailers:
			v.erase(remove_if(v.begin(), v.end(), [](Student* st) {return st->studType() == "PHD" && st->getNumOfCourses() == 0; }), v.end());
			for_each(v.begin(), v.end(), [](Student* st) {st->print(); });
			break;

		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	//system("pause");
	return 0;
}
//Running example:
//enter 0 - 7
//1
//enter 1 to add a BA student
//enter 2 to add a MA student
//enter 3 to add a PHD student
//1
//enter id, first name, last name and number OfCourses
//123
//abe
//avraham
//3
//enter 3 grades
//90 100 90
//enter 0 - 7
//1
//enter 1 to add a BA student
//enter 2 to add a MA student
//enter 3 to add a PHD student
//1
//enter id, first name, last name and number OfCourses
//234
//yitzhak
//avrhamson
//10
//enter 10 grades
//100 100 90 100 90 100 90 100 90 100
//enter 0 - 7
//2
//ID: 234
//	first name : yitzhak
//	last name : avrhamson
//	num courses : 10
//	grades : 100 100 90 100 90 100 90 100 90 100
//	enter 0 - 7
//	0