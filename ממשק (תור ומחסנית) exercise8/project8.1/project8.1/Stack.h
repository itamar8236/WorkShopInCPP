//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 8 Question 1
//this program reads infex expression, prints the postfix and its value. 
#pragma once
//-------------------------------------------------------
// class stack
// abstract class - simply defines protocol for
// stack operations
//-------------------------------------------------------
class Stack
{
public:
	virtual void clear() = 0;
	virtual bool isEmpty() const = 0;
	virtual float pop() = 0;
	virtual void push(float value) = 0;
	virtual float top() = 0;
};

