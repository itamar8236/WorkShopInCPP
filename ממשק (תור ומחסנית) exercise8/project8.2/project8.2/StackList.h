//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 8 Question 2
//this program checks QueueStack class. 
#pragma once
#include "Stack.h"
#include "List.h"
//-------------------------------------------------------
// class StackList
// Stack implemented using List operations
//-------------------------------------------------------
class StackList : public Stack
{
public:
	StackList();
	StackList(const StackList&);
	// Stack operations
	void clear()override;
	bool isEmpty() const override;
	int pop()override;
	void push(int value) override;
	int top()override;
protected:
	// data fields
	List data;
};


