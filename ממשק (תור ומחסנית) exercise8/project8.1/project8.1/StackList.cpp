//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 8 Question 1
//this program reads infex expression, prints the postfix and its value. 
#include "StackList.h"
#include "Stack.h"
#include "List.h"
#include <iostream>
using namespace std;
//-------------------------------------------------------
// class StackList implementation
//-------------------------------------------------------
StackList::StackList() :data()
{
	// create and initialize a Stack based on Lists
}
StackList::StackList(const StackList& lst)
	: data(lst.data)
{ /* copy constructor*/
}
void StackList::clear()
{
	// clear all elements from Stack, by setting
	// delete all values from List
	data.clear();
}
bool StackList::isEmpty() const
{ // return true if Stack is empty
	return data.isEmpty();
}
float StackList::pop()
{
	// return and remove the intopmost element in the Stack
	// get first element in List
	float result = data.firstElement();
	// remove element from List
	data.removeFirst();
	// return value
	return result;
}
void StackList::push(float val)
{
	// push new value onto Stack
	data.add(val);
}
float StackList::top()
{
	return data.firstElement();
}
