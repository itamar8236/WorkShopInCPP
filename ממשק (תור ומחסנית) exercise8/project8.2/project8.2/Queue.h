//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 8 Question 2
//this program checks QueueStack class. 
#pragma once
class Queue
{
public:
	// protocol for Queue operations
	virtual void clear() = 0;
	virtual int dequeue() = 0;
	virtual void enqueue(int value) = 0;
	virtual int front() = 0;
	virtual bool isEmpty() const = 0;
};

