//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 5 Question 1
//this program checks the functions: =, cin, cout, insert and remove in link list. 
#include <iostream>
#include <string>
#include "List.h"
using namespace std;
int main()
{//copied from the question
	/*List lst;
	int choice, val;
	cout << "enter the list values\n";
	cin >> lst;
	cout << "choose 0-2\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case 1:cout << "enter a value to insert\n";
			cin >> val;
			lst.insert(val);
			break;
		case 2:cout << "enter a value to remove\n";
			cin >> val;
			try {
				lst.remove(val);
			}
			catch (char * msg)
			{
				cout << msg << endl;
			}
			break;
		default:cout << "ERROR\n";
		}
		cout << lst << endl;
		cout << "choose 0-2\n";
		cin >> choice;
	}*/

	string str = "123";
	cout << str.substr(0, str.length() - 1);
	system("pause");
	return 0;
}
//Running example:
//enter the list values
//1 2 3 3
//choose 0 - 2
//2
//enter a value to remove
//2
//13
//choose 0 - 2
//1
//enter a value to insert
//4
//134
//choose 0 - 2
//1
//enter a value to insert
//2
//1234
//choose 0 - 2
//0
//Press any key to continue . . .