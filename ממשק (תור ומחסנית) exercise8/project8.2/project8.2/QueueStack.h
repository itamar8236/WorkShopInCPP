//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 8 Question 2
//this program checks QueueStack class. 
#pragma once
#include "Queue.h"
#include "StackList.h"
#include "Stack.h"
class QueueStack : public Queue
{
protected:
	Stack* data;
public:
	QueueStack();
	void clear() override;
	int dequeue() override;
	void enqueue(int value) override;
	int front() override;
	bool isEmpty() const override;
	~QueueStack();
};

