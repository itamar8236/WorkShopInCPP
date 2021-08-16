//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 11 Question 1
//this program checks binary search tree as int class.
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;
int main()
{
	BinarySearchTree<int> T1;
	cout << "enter 10 numbers\n";
	int x, y;
	for (int i = 0; i < 10; i++)
	{
		cin >> x;
		T1.add(x);
	}
	cout << "inorder: ";
	T1.inOrder();
	cout << "\n enter 0-6:\n";
	cin >> x;
	while (x != 0)
	{
		switch (x)
		{
		case 1:
			cout << "# of leaves: " << T1.leaves() << endl;
			break;
		case 2:
			cout << "height of tree: " << T1.height() << endl;
			break;
		case 3:
			T1.reflect();
			cout << "reflected tree: ";
			T1.inOrder();
			T1.reflect();
			cout << endl;
			break;
		case 4:
			cout << "# left sons only: " << T1.onlyLeftSon() << endl;
			break;
		case 5:
			cout << "enter a number ";
			cin >> y;
			cout << "level of " << y << " on tree: " << T1.level(y) << endl;
			break;
		case 6:
			cout << "enter a number ";
			cin >> y;
			T1.remove(y);
			cout << "after removing " << y << ": ";
			T1.inOrder();
			cout << endl;
		}
		cout << "enter 0-6:\n";
		cin >> x;
	}
	return 0;
}
//Running example:
//enter 10 numbers
//1 2 3 4 5 6 7 8 9 0
//inorder: 0 1 2 3 4 5 6 7 8 9
//	enter 0 - 6 :
//	1
//	# of leaves : 2
//	enter 0 - 6 :
//	2
//	height of tree : 8
//	enter 0 - 6 :
//	4
//	# left sons only : 0
//	enter 0 - 6 :
//	5
//	enter a number 7
//	level of 7 on tree : 6
//	enter 0 - 6 :
//	6
//	enter a number 8
//	after removing 8 : 0 1 2 3 4 5 6 7 9
//	enter 0 - 6 :
//	2
//	height of tree : 7
//	enter 0 - 6 :
//	0