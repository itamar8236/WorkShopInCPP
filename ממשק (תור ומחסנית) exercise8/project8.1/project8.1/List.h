//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 8 Question 1
//this program reads infex expression, prints the postfix and its value.  
#pragma once
#include <iostream>
using namespace std;
class List
{
protected:
	//--------------------------------------------
   // inner class link
   // a single element for the linked List
   //--------------------------------------------
	class Link
	{
	public:
		// constructor
		Link(float linkValue, Link * nextPtr);
		Link(const Link &);
		// data areas
		float value;
		Link * next;
	}; //end of class Link

public:
	// constructors
	List();
	List(const List&);
	~List();
	// operations
	void add(float value);
	float firstElement() const;
	bool search(const float &value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
protected:
	// data field
	Link* head;
};
