//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 8 Question 2
//this program checks QueueStack class. 
#include "QueueStack.h"
#include "Queue.h"
#include "StackList.h"
#include "Stack.h"
#include <iostream>
using namespace std;

QueueStack::QueueStack()
{
	data = new StackList();
}
void QueueStack::clear()
{
	data->clear();
}
int QueueStack::dequeue()
{
	if (this->isEmpty())
		throw "the queue is empty, cannot dequeue";
	int val;
	StackList temp;
	while (!this->isEmpty())
		temp.push(data->pop());
	val = temp.pop();
	while (!temp.isEmpty())
		data->push(temp.pop());
	return val;
}
void QueueStack::enqueue(int value)
{
	data->push(value);
}
int QueueStack::front()
{
	if (this->isEmpty())
		throw "the queue is empty, no front value";
	int val;
	StackList temp;
	while (!this->isEmpty())
		temp.push(data->pop());
	val = temp.top();
	while (!temp.isEmpty())
		data->push(temp.pop());
	return val;
}
bool QueueStack::isEmpty() const
{
	return data->isEmpty();
}
QueueStack::~QueueStack()
{
	delete data;
}
