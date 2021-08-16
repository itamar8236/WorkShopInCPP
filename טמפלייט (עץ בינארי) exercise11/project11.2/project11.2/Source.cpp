//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 11 Question 2
//this program uses binary search tree to save students.
#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include "Student.h"
using namespace std;
int main()
{
	Student stTemp;
	char option;
	BinarySearchTree<Student> students;
	cout << "enter a-e" << endl;
	cin >> option;
	while (option != 'e')
	{
		switch (option)
		{
		case 'a':
			cout << "enter a student" << endl;
			cin >> stTemp;
			students.add(stTemp);
			break;
		case 'b':
			cout << "enter a student" << endl;
			cin >> stTemp;
			students.remove(stTemp);
			break;
		case 'c':
			cout << "enter a student" << endl;
			cin >> stTemp;
			if (students.search(stTemp))
				cout << "exist" << endl;
			else cout << "not exist" << endl;
			break;
		case 'd':
			students.inOrder();
			break;
		default:
			cout << "error" << endl;
			break;
		}
		cout << "enter a-e" << endl;
		cin >> option;
	}
	//system("pause");
	return 0;
}
//Running example:
//enter a - e
//a
//enter a student
//2 b b
//enter a - e
//a
//enter a student
//5 e e
//enter a - e
//a
//enter a student
//1 a a
//enter a - e
//a
//enter a student
//4 d d
//enter a - e
//a
//enter a student
//7 g g
//enter a - e
//a
//enter a student
//3 c c
//enter a - e
//b
//enter a student
//5 e e
//enter a - e
//d
//1 a a
//2 b b
//3 c c
//4 d d
//7 g g
//enter a - e
//e
//Press any key to continue . . .