//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 8 Question 2
//this program checks QueueStack class. 
#include<string>
#include <iostream>
#include "QueueStack.h"
using namespace std;
int main()
{//main copied from the question
	Queue* Q;
	Q = new QueueStack();
	try {
		for (int i = 0; i < 10; i++)
			Q->enqueue(i);
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	cout << "first on Q is: " << Q->front() << endl;
	cout << "take out 2 elemets:" << endl;
	cout << Q->dequeue() << ' ' << Q->dequeue() << endl;
	cout << "first on Q is: " << Q->front() << endl;
	Q->enqueue(8);
	Q->enqueue(9);
	while (!Q->isEmpty())
		cout << Q->dequeue() << " ";
	//system("pause");
	return 0;
}
//Running example:
//first on Q is : 0
//take out 2 elemets :
//	1 0
//	first on Q is : 2
//	2 3 4 5 6 7 8 9 8 9 Press any key to continue . . .