//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 5 Question 2
//this program checking the functions "merge" and "makeSet" on link list. 
#include <iostream>
#include "List.h"
using namespace std;
//this function merges 2 lists into in.
List merge(List l1, List l2)
{
	List newL;
	try
	{
		while (true)
		{
			newL.insert(l1.firstElement());
			l1.removeFirst();
		}
	}
	catch(const char * msg)
	{ }
	try
	{
		while (true)
		{
			newL.insert(l2.firstElement());
			l2.removeFirst();
		}
	}
	catch (const char * msg)
	{
	}
	return newL;
}
//this function delete all double elements from the list.
void makeSet(List &l)
{
	List temp;
	try
	{
		temp.insert(l.firstElement());
		l.removeFirst();
		while (true)
		{
			if (!temp.search(l.firstElement()))
				temp.insert(l.firstElement());
			l.removeFirst();
		}
	}
	catch (const char * msg)
	{
		l = temp;
	}
}
int main()
{
	List lst1, lst2, mergedList;

	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;

	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	//system("pause");
	return 0;
}
//Running example:
//enter sorted values for the first list :
//1 2 3 5 6 0
//enter sorted values for the second list :
//3 4 5 7 0
//the new merged list : 1 2 3 3 4 5 5 6 7
//the new merged set : 1 2 3 4 5 6 7
//Press any key to continue . . .