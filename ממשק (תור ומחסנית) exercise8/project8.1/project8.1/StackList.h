//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 8 Question 1
//this program reads infex expression, prints the postfix and its value. 
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
	float pop()override;
	void push(float value) override;
	float top()override;
protected:
	// data fields
	List data;
};

