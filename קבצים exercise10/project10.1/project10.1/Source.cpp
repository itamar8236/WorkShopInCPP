//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 10 Question 1
//this program can add, delete update check rishum prints and print by course to students. the program use binary files to save the students's information
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
enum option { stop, ADD, DEL, UPDATE, RISHUM, PRINT, COURSE };
//student information
struct Student
{
	int stNum;
	char lName[20];
	char fName[20];
	bool courses[5];
};
//this function gets reference to file.
//the function starts the file with 100 places for students's info.
void init(fstream&f)
{
	Student st;
	st.stNum = 0;
	strcpy_s(st.fName, "");
	strcpy_s(st.lName, "");
	for (int i = 0; i < 5; i++)
		st.courses[i] = false;
	for (int i = 0; i < 100; i++)
		f.write((char*)&st, sizeof(st));
}
//this function gets reference to file.
//the function reads new studenst's infp and write to the file.
void add(fstream&f)
{
	Student curst;
	cout << "Eneter student number, last name, first name and 0/1 for 5 courses (true or false).\n";
	cin >> curst.stNum >> curst.lName >> curst.fName;//reading student info
	for (int i = 0; i < 5; i++)
		cin >> curst.courses[i];
	if (curst.stNum < 1 || curst.stNum > 100)//checking for errors
		throw "ERROR: Invalid student number";
	Student temp;
	f.seekg((curst.stNum-1)*sizeof(curst));
	f.read((char*)&temp, sizeof(temp));
	if (temp.stNum != 0)//checking for errors
		throw "ERROR: Student is already in the file";
	f.seekp((curst.stNum - 1) * sizeof(curst));
	f.write((char*)&curst, sizeof(curst));//writing new student
}
//this function gets reference to file and student number.
//the function deletes the student (stNum = 0).
void del(fstream&f, int num)
{
	if (num < 1 || num > 100)//checking for errors
		throw "ERROR: Invalid student number";
	Student temp;
	f.seekg((num - 1) * sizeof(temp));//reading cur st
	f.read((char*)&temp, sizeof(temp));
	temp.stNum = 0;//deleting
	f.seekp((num - 1) * sizeof(temp));
	f.write((char*)&temp, sizeof(temp));//rewrite deleted student
}
//this function gets reference to file and student number.
//the function updates the student's  courses array.
void update(fstream&f, int num)
{
	if (num < 1 || num > 100)//checking for errors
		throw "ERROR: Invalid student number";
	Student temp;
	f.seekg((num - 1) * sizeof(temp));//reading cur st
	f.read((char*)&temp, sizeof(temp));
	if (temp.stNum == 0)
		throw "ERROR: Student is not in the file";
	cout << "Enter 0/1  for 5 courses (true or false).\n";
	for (int i = 0; i < 5; i++)
		cin >> temp.courses[i];
	f.seekp((num - 1) * sizeof(temp));
	f.write((char*)&temp, sizeof(temp));//update
}
//this function gets reference to file and student number, and course number.
//the function returns if the student does this course.
bool rishum(fstream&f, int sNum, int cNum)
{
	if (sNum < 1 || sNum > 100)//checking for errors
		throw "ERROR: Invalid student number";
	if (cNum < 1 || cNum > 5)//checking for errors
		throw "ERROR: Invalid course number";
	Student temp;
	f.seekg((sNum - 1) * sizeof(temp));//reading cur st
	f.read((char*)&temp, sizeof(temp));
	if (temp.stNum == 0)
		throw "ERROR: Student is not in the file";
	return temp.courses[cNum-1];//-1 because of array indexes
}
//this function gets reference to file and student number.
//the function prints tghe student.
void print(fstream&f, int num)
{
	if (num < 1 || num > 100)//checking for errors
		throw "ERROR: Invalid student number";
	Student temp;
	f.seekg((num - 1) * sizeof(temp));//reading cur st
	f.read((char*)&temp, sizeof(temp));
	if (temp.stNum == 0)
		throw "ERROR: Student is not in the file";
	cout << "Fisrt name: " << temp.fName << "\nLast name: " << temp.lName << "\nCourses:\n";
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ": ";
		if (temp.courses[i])
			cout << "Y";
		else
			cout << "N";
		cout << endl;
	}

}
//this function gets reference to file and course number.
//the function prints all students who do that course.
void inCourse(fstream&f, int cNum)
{
	if (cNum < 1 || cNum > 5)//checking for errors
		throw "ERROR: Invalid course number";
	Student temp;
	for (int i = 1; i <= 100; i++)
	{
		f.seekg((i - 1) * sizeof(temp));//reading cur st
		f.read((char*)&temp, sizeof(temp));
		if (temp.stNum != 0 && temp.courses[cNum - 1])
			cout << temp.fName << " " << temp.lName << endl;
	}
}
int main()
{//copied.
	{
		fstream file;
		file.open("students.txt", ios::binary |
			ios::in | ios::out);
		/*file.open("students.txt");*/
		if (!file)
		{
			cout << "ERROR: couldn't open file\n";
			system("pause");
			return 0;
		}
		init(file);
		int choice;
		int snum;
		int cnum;
		cout << "Choices are:\n0 to exit\n1 to add a student\n2 to delete a student\n3 to update rishum to courses\n4 to check rishum for a course\n5 to print a student\n6 to print all the students that participate in a specific course\n";
		cout << "enter 0-6:\n";
		cin >> choice;
		while (choice)
		{
			switch (choice)
			{
			case ADD://add to the file
				try { add(file); }
				catch (const char * msg) { cout << msg; }
				break;
			case DEL://delete from file
				cout << "enter number of student to delete:\n";
				cin >> snum;
				try { del(file, snum); }
				catch (const char * msg) { cout << msg; }
				break;
			case UPDATE://update the list of courses of a student
				cout << "enter number of student to update:\n";
				cin >> snum;
				try { update(file, snum); }
				catch (const char * msg) { cout << msg; }
				break;
			case RISHUM://check rishum to a specific course
				cout << "enter number of student to check rishum:\n";
				cin >> snum;
				cout << "enter number of course to check rishum:\n";
				cin >> cnum;
				try
				{
					cout << "The student is" << (rishum(file, snum, cnum) ? " " : " not ") << "taking the course\n";
				}
				catch (const char * msg) { cout << msg; }
				break;
			case PRINT://print the details of a specific student
				cout << "enter number of student to print:\n";
				cin >> snum;
				try { print(file, snum); }
				catch (const char * msg) { cout << msg; }
				break;
			case COURSE://print the details of all the students that are taking a specific course
				cout << "enter number of course to check rishum:\n";
				cin >> cnum;
				try { inCourse(file, cnum); }
				catch (const char * msg) { cout << msg; }
				break;
			default:
				cout << "ERROR: invalid choice\n";
			}
			cout << "\nenter 0-6:\n";
			cin >> choice;
		}

		file.close();
		//system("pause");
		return 0;
	}
}
//Running example:
//Choices are :
//0 to exit
//1 to add a student
//2 to delete a student
//3 to update rishum to courses
//4 to check rishum for a course
//5 to print a student
//6 to print all the students that participate in a specific course
//enter 0 - 6:
//1
//Eneter student number, last name, first name and 0 / 1 for 5 courses(true or false).
//36 cohen itamar 1 0 0 1 1
//
//enter 0 - 6 :
//	1
//	Eneter student number, last name, first name and 0 / 1 for 5 courses(true or false).
//	67 last first 1 1 1 1 1
//
//	enter 0 - 6 :
//	2
//	enter number of student to delete :
//	67
//
//	enter 0 - 6 :
//	6
//	enter number of course to check rishum :
//1
//itamar cohen
//
//enter 0 - 6 :
//	5
//	enter number of student to print :
//67
//ERROR : Student is not in the file
//	enter 0 - 6 :
//	5
//	enter number of student to print :
//36
//Fisrt name : itamar
//Last name : cohen
//Courses :
//1 : Y
//2 : N
//3 : N
//4 : Y
//5 : Y
//
//enter 0 - 6 :
//	0
//	Press any key to continue . . .